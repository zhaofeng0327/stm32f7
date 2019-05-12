#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "manage_at_cmd.h"
#include "manage_at_uart.h"
#include "fml_log.h"

/* This type MUST be 8-bit */
typedef unsigned char	BYTE;

#define UPPER(x) (((x)>='a' && (x)<='z')?((x)-'a'+'A'):(x))

#define in_range(c, lo, up)  ((unsigned char )c >= lo && (u8_t)c <= up)
#define isprint(c)           in_range(c, 0x20, 0x7f)
#define isdigit(c)           in_range(c, '0', '9')
#define isxdigit(c)          (isdigit(c) || in_range(c, 'a', 'f') || in_range(c, 'A', 'F'))
#define islower(c)           in_range(c, 'a', 'z')
#define isspace(c)           (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
#define AT_RX_MIN_LEN 4


bool memncmp(const char *mem1, const char *mem2, unsigned int mem1_len, unsigned int mem2_len)
{
	unsigned int im1 = 0;

	for (im1 = 0; im1 <= (mem1_len-mem2_len); im1++)
	{
		if(memcmp(&mem1[im1], mem2, mem2_len) == 0)
		{
			return true;
		}
	}
	return false;
}

static AT_RESULT send_at_command(char *strcmd) 
{
	if((NULL == strcmd) || (strcmd[0] == '\0') || (UPPER(strcmd[0])!='A' && UPPER(strcmd[1])!='T'))
	{
		return (errAtCmd);
	}
    
	at_uart_send_data((unsigned char*)strcmd,(unsigned short)strlen(strcmd));
	
	return errOK;
}
extern int hal_it_flag;
extern unsigned int try_cnt;

unsigned int recieve_at_command(char *rcvbuf, unsigned int buflen, unsigned int waittime,unsigned char* err) 
{
	unsigned int length = 0;
	//memset(rcvbuf,0,buflen);
	length = at_uart_recv((unsigned char *)rcvbuf, buflen, waittime, err);
	if (length > AT_RX_MIN_LEN)
	{
		//判断接收数据正确性
     //  printf("recv data=%s\n",rcvbuf);
	}
	
	printf("recv uard len = %d,data=%s\n",length, rcvbuf);

	return length;
}



#if 0
/****************************************************************************************
 *函数名：CSim_RecieveFromUart
 *描  述：从串口中接收数据；根据各自的平台情况做相应的修改；
 Waittime的单位为ms
 * 返回值:
 < 0  链路有问题
 = 0  没有读取到数据
 > 0  有读取到数据，返回值为数据大小
 *****************************************************************************************/ 
int CSim_RecieveFromUart(unsigned char *RcvBuf, int BufLen, int Waittime) 
{
	int nLength = 0;
	AT_RESULT errCode = errOK;
	unsigned char *pbuf = NULL;
	//int iSocketId = m_ucSockId;
	int iDataLen = 0;
	int iLeftLen = 0;
	int iKeyLen = 0;
	unsigned char err;

	memset(RcvBuf, 0, BufLen);

	nLength = at_uart_recv(RcvBuf, Waittime, BufLen,&err);
	if (nLength > AT_RX_MIN_LEN)
	{
		printf("Uart(%d):%s\n",nLength, RcvBuf);
	}

	return nLength;
}

/****************************************************************************************
 *函数名：CSim_RawCheckATCommand

 *描  述：向模块发送命令，并确认是否返回正确的命令

 支持多个希望的返回值字符串同时比较
 "%d%s%s"
 %d为比较关系，表示equal或not equal
 %s后的字符串为比较内容
 比如:
 "%d%s%s", true, "aaaa", "bbbb"
 则代表，返回值要匹配"aaaa"或"bbbb"
 但函数只要匹配所有字符串里面的任意一个，则命令执行结束

 返回值:
 < 0 参数或其他原因失败，或多次尝试没有返回想要的结果，归纳为超时
 > 0 命令下发成功，同时返回了想要的结果

 *****************************************************************************************/ 
AT_RESULT CSim_RawCheckATCommand(
		const char *atcmd, // 下发的AT命令
		int Sendtimes ,    // 允许AT命令重发次数
		int Readtimes,     // 发送一次AT命令，允许读取串口返回次数
		int UartWaittime,  // 串口等待时间(MS)
		int Waittime,      // 操作系统延迟时间(这个参数已经没有使用)
		char *RcvBuf,     // 串口返回结果接收缓冲
		int *BufLen,    // 接收结果的缓冲大小及返回结果大小
		char *fmt, ...) // 比较结果的控制内容
{
	unsigned char aucRcvBuf[UART_BUF_LEN];
	int iRcvLen = 0;
	int iSend = 0;  // 超时次数变量；
	int iRead = 0;
	int isEqual = -1;
	bool bFound = false; 
	char * pfmt = NULL; // 指向%d%s%s ...
	char *s = NULL;
	va_list ap;
	int iSimResp = 0; // 记录模块在整个命令执行过程中是否有反应

	if (NULL == atcmd || NULL == fmt || atcmd[0] == '\0' || strlen(atcmd) > GPRS_FRAME_SIZE)
	{
		return (errAtCmd);
	}

	// 执行设置和结果比较
	while (iSend++ < Sendtimes)
	{   
		printf("第%d次发送:\n", iSend);

		// 通过串口发送AT回车，参数有问题直接返回，不再循环
		if (errOK != send_at_command((char *)atcmd)) 
		{
			return errAtCmd;
		}

		// 多次尝试读取返回结果
		iRead = 0;
		while (iRead++ < Readtimes)
		{
			iRcvLen = CSim_RecieveFromUart(aucRcvBuf, sizeof(aucRcvBuf), UartWaittime);

#if 0
			if (iRcvLen < 0)
			{
				return  (ComResult)iRcvLen;
			}
			if(NULL != aucRcvBuf && strstr(atcmd,AT_CMD_CIPSTART)!=NULL )
			{
				if(memncmp(aucRcvBuf, AT_CMDR_ERR, iRcvLen, strlen(AT_CMDR_ERR)))
				{
					return errReset; 
				}
			}
#endif
			if (iRcvLen > 0) 
			{
				iSimResp++;

				// 对多个希望值进行比较
				va_start(ap, fmt);
				pfmt = fmt;
				while(*pfmt)
				{
					switch(*pfmt++)
					{
						case 'd':
							{
								// 开始新的查找
								isEqual = va_arg(ap, int);
								bFound = false;
								printf("Param->%s\n", isEqual?"true":"false");
							}
							break;
						case 's':
							{
								// 只有没找到的情况下再找
								if (!bFound)
								{
									s = va_arg(ap, char *);
									bFound = memncmp(aucRcvBuf, (unsigned char *)s, iRcvLen, strlen(s));

									// 需要接收返回内容
									if ((NULL != RcvBuf) && bFound)
									{
										memset(RcvBuf, 0, *BufLen);

										// 确保拷贝不越界
										if (*BufLen < iRcvLen)
										{
											//ComErrPrint(errBuffer);
										}
										else
										{
											*BufLen = iRcvLen;
										}

										memcpy(RcvBuf, aucRcvBuf, *BufLen);
									}
									printf("Key:%s\n", s);
								}
							}
							break;
						default:
							break;
					}

					// 每经过一轮查找，设置结果
					if (bFound)
					{
						break;
					}
				}

				va_end(ap);

				if ((bFound && isEqual) || (!bFound && !isEqual))
				{
					return errOK;
				}
				else
				{
					// 不是想要的执行结果，则重新发送AT命令
					//continue;
				}
			}
		} 
	}

	if (iSimResp > 0)
	{
		return errTimeOut;  // 命令执行失败
	}
	else
	{
#if 0
		// 检测一下模块是否有反应
		// 以防止电压不稳导致模块假死
		(void)CSim_SendATCommand(AT_CMD_ATI) ;
		OsPrintf("检测模块是否假死\n");
		iRead = 0;
		while (iRead++ < 4)
		{
			OsThreadDelayS(1);
			iRcvLen = CSim_RecieveFromUart(aucRcvBuf, sizeof(aucRcvBuf), 1000);
			if (iRcvLen > 0)
			{
				if (memncmp(aucRcvBuf, AT_CMDR_OK, iRcvLen, strlen(AT_CMDR_OK)))
				{
					return errTimeOut;
				}
			}
		}

		ComErrPrintReturn(errGprsModule);  // 模块没反应
#endif

	}
}

// 执行一些执行很快的AT命令
AT_RESULT CSim_CheckQuickATCommand(const char *atcmd,const char *pExpend, bool isEqual )
{
	int RetLen = 0;
	return CSim_RawCheckATCommand(atcmd, 1, 2, WAITE_1S, UART_RESND_DELAY_TIME, 
			NULL, &RetLen, "%d%s", isEqual, pExpend);
}

// 执行一些普通的AT命令
AT_RESULT CSim_CheckATCommand(const char *atcmd,const char *pExpend, bool isEqual )
{
	int RetLen = 0;
	return CSim_RawCheckATCommand(atcmd, UART_RESND_TIMES, 2, WAITE_1S, UART_RESND_DELAY_TIME, 
			NULL, &RetLen, "%d%s", isEqual, pExpend);
}


// 执行一些花费时间比较长的AT命令
AT_RESULT CSim_CheckWasteATCommand(const char *atcmd,const char *pExpend, bool isEqual )
{
	int RetLen = 0;
	return CSim_RawCheckATCommand(atcmd, 1, 20, 3*WAITE_1S, UART_RESND_DELAY_TIME, 
			NULL, &RetLen, "%d%s", isEqual, pExpend);
}

// 执行需要得到串口返回值的AT命令
AT_RESULT CSim_CheckATCommandReturn(const char *atcmd,char *RcvBuf, int *BufLen, const char *pExpend, bool isEqual )
{
	return CSim_RawCheckATCommand(atcmd, 1, 3, WAITE_1S, UART_RESND_DELAY_TIME, 
			RcvBuf, BufLen, "%d%s", isEqual, pExpend);
}
#endif

static AT_RESULT raw_check_at_command(
		AT_CMD_LIST listcmd,
		char *atcmd, 		// 下发的at命令
		unsigned int sendtimes,    	// 允许at命令重发次数
		unsigned int readtimes,     	// 发送一次at命令，允许读取串口返回次数
		unsigned int uartwaittime,  	// 串口等待时间(ms)
		char *rcvbuf,     	// 串口返回结果接收缓冲
		unsigned int *buflen,    	// 接收结果的缓冲大小及返回结果大小
		char *fmt) 			// 比较结果的控制内容
{
	char aucrcvbuf[UART_BUF_LEN];
	unsigned int ircvlen = 0;
	unsigned int isend = 0;  // 超时次数变量；
	unsigned int iread = 0;
    unsigned char err = 0;
	
	char *phead = NULL, *psure = NULL, *pend = NULL, *pdata = NULL;
    http_action_result_t action_result; 

	if (NULL == atcmd || NULL == fmt || atcmd[0] == '\0' || strlen(atcmd) > GPRS_FRAME_SIZE)
	{
		return (errAtCmd);
	}

	// 执行设置和结果比较
	while(isend++ < sendtimes)
	{   

		// 通过串口发送at回车，参数有问题直接返回，不再循环
		if (errOK != send_at_command(atcmd)) 
		{
			return errAtCmd;
		}

		//多次尝试读取返回结果
		iread = 0;
		while (iread++ < readtimes)
		{
			printf("the sendtime=%d revctime=%d\n", isend,iread);
			ircvlen = recieve_at_command(aucrcvbuf, sizeof(aucrcvbuf), uartwaittime,&err);
			
			if (ircvlen > 0) 
			{

				if(memncmp(aucrcvbuf, fmt, ircvlen, strlen(fmt)))
				{
                    printf("revc the fmt \n");
					if(listcmd == LIST_CMD_MIPSTART)
					{	
                        rcvbuf[0] = TCP_CONN_OK;
						*buflen = 1;
					}
					else if (listcmd == LIST_CMD_HTTPACTION)	//HTTP ACTION
					{
						phead = strstr(aucrcvbuf, "+HTTPACTION: ");
						if(!phead)
							return errRvcData;

						pend = strstr(phead, "\r\n");
						if(!pend)
							return errRvcData;
						phead += strlen("+HTTPACTION: ");
						if(pend - phead <= 0)
							return errRvcData;
						
						//HTTP 方式
						if(phead != NULL)
						{
							action_result.method = atoi(phead);
						}
						else
						{
							return errRvcData;
						}
						
						
                        //<statuscode>
						pdata = strstr(phead,",");
						if(pdata != NULL)
						{
							pdata++;
							action_result.status_code = atoi(pdata);//HTTP statuscode
						}
						else
						{
							return errRvcData;
						}

						//得到的数据长度
						pdata = strstr(pdata,",");
						if(pdata != NULL)
						{
							pdata++;
							action_result.data_len = atoi(pdata);//HTTP得到数据的长度
						}
						else
						{
							return errRvcData;
						}
						
						//拷贝输出
						if((rcvbuf != NULL) && (buflen != NULL) && ((*buflen) >= sizeof(http_sapbr_t))) 	//检查数据输出缓存参数正确性
						{
							memcpy(rcvbuf, (char *)&action_result,sizeof(http_action_result_t));
							*buflen = sizeof(http_sapbr_t);
						}
						else
						{
							return errBuffPara;
						}
					}
					
					return errOK;
				}
				else if(memncmp(aucrcvbuf, AT_CMDR_ERR, ircvlen, strlen(AT_CMDR_ERR)))
				{
                    printf("revc err \n");
					
					//特殊命令处理
					if(listcmd == LIST_CMD_MIPSTART && memncmp(aucrcvbuf,AT_CMDR_CONN_ALREADY, ircvlen, strlen(AT_CMDR_CONN_ALREADY)))
					{
						//数据返回有待商定
						rcvbuf[0] = TCP_CONN_ALREADY;
						*buflen = 1;
						return errOK;
					}
					goto ERR;
				}
				else if(memncmp(aucrcvbuf, AT_CMDR_OK, ircvlen, strlen(AT_CMDR_OK)))
				{
                    printf("revc ok \n");
					continue;
				}
				else
				{
                    printf("revc other\n");
					//特殊处理MIPSTART命令
					if(listcmd == LIST_CMD_MIPSTART && memncmp(aucrcvbuf,AT_CMDR_CONN_FAIL, ircvlen, strlen(AT_CMDR_CONN_FAIL)))
					{
						goto ERR;
					}
					
					return errRvcData;
				}
			}
			else
			{
				return errTimeOut;
			}
				
		} 
	}
	ERR:
	switch (listcmd)
	{
		case LIST_CMD_MIPSTART:	//建立TCP连接
			return errMQTTTCPConnect;
		break;
		
		case LIST_CMD_MCONNECT:	//请求会话连接
			return errMQTTConnect;
		break;
		
		case LIST_CMD_MSUB:		//订阅主题
			return errMQTTSub;
		break;
		
		case LIST_CMD_MPUB:		//发布消息
			return errMQTTPub;
		break;

		case LIST_CMD_HTTPACTION://HTTP ACTION
			return errHttpAction;
			break;
		
		default:
			return errNotAnyData;
	}
}


//AT命令直接返回OK/ERROR,不需要返回AT返回任何数据
static AT_RESULT common_cmd_handle(AT_CMD_LIST cmd,char* in_data,bool errflag)
{
    AT_RESULT ret = errOK;
	unsigned char try_cnt = 0;
	unsigned char err=0;
	char rcvbuf[UART_BUF_LEN]={0};
	char *phead = NULL,*psure = NULL,*pend = NULL;
	memset(rcvbuf,0,sizeof(rcvbuf));
	
	do
	{
		if(in_data != NULL && strlen(in_data) > 0)
		{
			if((ret = send_at_command(in_data)) != errOK)
				return ret;
		} 
		else 
		{
				return errAtCmd;
		}
		
		if((recieve_at_command(rcvbuf, sizeof(rcvbuf),WAITE_2S, &err)) > 0) 
		{
			if(errflag)
			{
				phead = strstr(rcvbuf, "ERROR");
				if(phead != NULL)
					goto ERR;
			}
			
			psure = strstr(rcvbuf, "OK");
			if(!psure)
				goto ERR;
			pend = strstr(psure,"\r\n");
			if(!pend)
				goto ERR;
			
			return errOK;
		}
		//OsThreadDelayS( WAITTIMECSQ );

	}while(try_cnt--);

	
	ERR:
	switch (cmd)
	{
		case LIST_CMD_CSTT://设置APN
			return errSetAPN;
		break;
		case LIST_CMD_CIICR://激活移动场景
			return errPPP;
		break;
		case LIST_CMD_AT:
			return errGprsModule;
		break;

		case LIST_CMD_MCONFIG:	//设置相关参数	
			return errMQTTSetCfg;
		break;
		
		case LIST_CMD_MDISCONNECT://关闭MQTT连接
			return errMQTTDisConect;
		break;
		case LIST_CMD_MIPCLOSE:	 //关闭TCP连接
			return errMQTTTCPClose;
		break;
		case LIST_CMD_CIPSHUT:	//关闭移动场景
			return errCIPShut;
		break;
		
		case LIST_CMD_HTTPINIT:			//初始化HTTP服务
			return errHttpInit;
		break;
		case LIST_CMD_HTTPTERM:			//终止HTTP任务
			return errHttpTerm;
		break;
		case LIST_CMD_HTTPPARA: 		//设置HTTP参数值	
			return errHttpPara;
		break;
		case LIST_CMD_CNTP:
			return errCNTP;
		break;
		case LIST_CMD_CNTPCID:		//设置GPRS承载场景ID
			return errCNTPCID;
		break;
		
		default:
			return errNotAnyData;
	}
}

static AT_RESULT common_data_cmd_handle(AT_CMD_LIST cmd,char* in_data,char *out_data, unsigned int* out_len)
{
    AT_RESULT ret = errOK;
	unsigned int len = 0,i = 0;
	unsigned int in_data_len = 0;
	char str_rssi[3] = {0};
	unsigned char try_cnt = 0;
	unsigned char err=0;
	char rcvbuf[UART_BUF_LEN]={0};
	char *phead = NULL, *psure = NULL, *pend = NULL, *pdata = NULL;
	memset(rcvbuf,0,sizeof(rcvbuf));
	
	do
	{
		if(in_data != NULL && strlen(in_data) > 0)
		{
			if((ret = send_at_command(in_data)) != errOK)
				return ret;
		} 
		else 
		{
			return errAtCmd;
		}
		
		if((len = recieve_at_command(rcvbuf, sizeof(rcvbuf), WAITE_2S, &err)) > 0) 
		{
			switch(cmd)
			{
				case LIST_CMD_CPIN:	//查询SIM卡是否READY
				{
					phead = strstr(rcvbuf, "+CPIN: ");
					if(!phead)
						return errRvcData;
					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;
					pend = strstr(phead, "\r\n");
					if(!pend)
						return errRvcData;
					phead += strlen("+CPIN: ");
					if(pend - phead <= 0)
						return errRvcData;	
					
					if(!strncmp("READY", phead, strlen("READY")))
						return errOK;
					else
						return errSIMCard;					
				}break;
				
				case LIST_CMD_CSQ:	//查询信号强度
				{
					rssi_data_t rssi_data;
					
					phead = strstr(rcvbuf, "+CSQ: ");
					if(!phead)
						return errRvcData;
					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;
					pend = strstr(phead, "\r\n");
					if(!pend)
						return errRvcData;
					phead += strlen("+CSQ: ");
					if(pend - phead <= 0)
						return errRvcData;	
					
					pdata = strstr(phead, ",");
					if(!pdata)
						return errRvcData;
					
					memcpy(str_rssi, phead, pdata-phead);
					rssi_data.rssi = atoi(str_rssi);
					rssi_data.biterror = atoi(pdata+1);
					
					if((out_data != NULL) && (out_len != NULL) && ((*out_len) >= sizeof(rssi_data)))		//检查数据输出缓存参数正确性
					{
						memcpy(out_data,(char*)&rssi_data , sizeof(rssi_data));
						*out_len = sizeof(rssi_data);
					}
					else
					{
						return errBuffPara;
					}
					
					return errOK;
				}break;
				
				case LIST_CMD_CGREG://查询注册状态
				{
					phead = strstr(rcvbuf, "+CGREG: ");
					if(!phead)
						return errRvcData;
					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;
					pend = strstr(phead, "\r\n");
					if(!pend)
						return errRvcData;
					phead += strlen("+CGREG: ");
					if(pend - phead <= 0)
						return errRvcData;	
					
					if (!strncmp("0,1", phead, strlen("0,1")) ||!strncmp("0,5", phead, strlen("0,5")))
						return errOK;
					else
						return errModuleReg;
				}break;

				case LIST_CMD_CCID: //查询SIM卡的CCID号
				{
					for(i = 0; i < len;i++)
					{
						if(rcvbuf[i] >= '0' && rcvbuf[i] <= '9')
						{
							phead = rcvbuf + i;
							break;
						}
					}
					if(!phead)
						return errRvcData;
					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;
					pend = strstr(phead, "\r\n\r\n");
					if(!pend)
						return errRvcData;
					if(pend - phead <= 0)
						return errRvcData;
					
					if((out_data != NULL) && (out_len != NULL) && ((*out_len) >= (pend-phead)))		//检查数据输出缓存参数正确性
					{
						*out_len = pend-phead;
						memcpy(out_data, phead, pend-phead);
				        out_data[pend - phead] = '\0';		//字符串输出
					}
					else
					{
						return errBuffPara;
					}
					
                    return errOK;
				}break;
				
				case LIST_CMD_CGATT: //查询附着分离
				{
					phead = strstr(rcvbuf, "+CGATT: ");
					if(!phead)
						return errRvcData;
					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;
					pend = strstr(phead, "\r\n");
					if(!pend)
						return errRvcData;
					phead += strlen("+CGATT: ");
					if(pend - phead <= 0)
						return errRvcData;	
					
					if (!strncmp("1", phead, 1))
						return errOK;
					else
						return errAttach;
				}break;
				
				case LIST_CMD_CIFSR:	//查询IP地址
				{
					phead = strstr(rcvbuf, "\r\n");
					if(!phead)
						return errRvcData;
					for(i = 0; i < len;i++)
					{
						if(phead[i] >= '0' && phead[i] <= '9')
						{
							phead = phead + i;
							break;
						}
					}
					if(!phead)
						return errRvcData;
                    
                    //调试过程发现没有返回OK
					pend = strstr(phead, "\r\n");
					if(!pend)
						return errRvcData;	
					
					if((out_data != NULL) && (out_len != NULL) && ((*out_len) >= (pend-phead)))//检查数据输出缓存参数正确性						
					{
						*out_len = pend-phead;
						memcpy(out_data, phead, *out_len);
			     	  	out_data[pend - phead] = '\0';	//IP地址字符串输出	
					}
					else
					{
						return errBuffPara;
					}
					
                    return errOK;
				}break;
				
				case LIST_CMD_MQTTSTATU: //查询MQTT连接状态
				{
					phead = strstr(rcvbuf, "+MQTTSTATU: ");
					if(!phead)
						return errRvcData;
					else
					{
						if((phead = strstr(rcvbuf, "ERROR")) != NULL)
							return errMQTTGetStatu;
					}
					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;
					pend = strstr(phead, "\r\n");
					if(!pend)
						return errRvcData;
					phead += strlen("+MQTTSTATU: ");
					if(pend - phead <= 0)
						return errRvcData;	
					
					out_data[0] = atoi(phead);
					*out_len = 1;
					
					return errOK;
	
				}break;
				
				case LIST_CMD_MQTTMSGGET:	//接收所有订阅消息
				{
					mqtt_msg_t mqtt_msg;
					int msg_cnt = 0;

					if((out_data != NULL) && (out_len != NULL))//检查数据输出缓存参数正确性	
					{
						in_data_len = *out_len;
						*out_len = 0;
					}
					else
					{
						return errBuffPara;
					}
					
					phead = strstr(rcvbuf, "+MSUB: ");
					if(!phead)
						return errRvcData;

					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;
					
					mqtt_msg.msg_buf = malloc(len);//系统是否有内存分配函数?多申请几个字节(包括数据头)

					if(mqtt_msg.msg_buf == NULL)
					{
						printf("MQTTMSGGET malloc fail \n");
						return errRvcData;
					}

					do
					{
						pend = strstr(phead, "\r\n");
						if(!pend)
						{
							free(mqtt_msg.msg_buf);
							mqtt_msg.msg_buf = NULL;
							return errRvcData;
						}
						if(pend - phead <= 0)
						{
							free(mqtt_msg.msg_buf);
							mqtt_msg.msg_buf = NULL;
							return errRvcData;
						}
						
						//获取信息
						pdata = strstr(phead,",");


						//数据长度
						if(pdata != NULL)
						{
							pdata++;
							mqtt_msg.len = atoi(pdata);//数据长度
						}
						else
						{
							free(mqtt_msg.msg_buf);
							mqtt_msg.msg_buf = NULL;
							return errRvcData;
						}
						
						//数据内容
						pdata = strstr(pdata,",");
						if(pdata != NULL)
						{
							pdata++;
							memset(mqtt_msg.msg_buf,0,len);
							memcpy(mqtt_msg.msg_buf,pdata,mqtt_msg.len);//数据内容
							//拷贝输出
							if(in_data_len >= len)//检查数据输出缓存参数正确性						
             		      	{         
							  	out_data[(*out_len)] = mqtt_msg.len;
		                        *out_len += 4;
								memcpy(out_data+(*out_len), mqtt_msg.msg_buf,mqtt_msg.len);
								*out_len += mqtt_msg.len;
							}
							else
							{
								free(mqtt_msg.msg_buf);
								mqtt_msg.msg_buf = NULL;
								return errBuffPara;
							}
						}
						
						//处理下一条
						pdata += mqtt_msg.len;
						if(pdata != NULL)
							phead = pdata;//???多条不运行这里
						else
						{
							free(mqtt_msg.msg_buf);
							mqtt_msg.msg_buf = NULL;
							return errOK;
						}
						
						phead = strstr(phead, "+MSUB: ");
						if(!phead)
						{
							free(mqtt_msg.msg_buf);
							mqtt_msg.msg_buf = NULL;
							return errOK;
						}
						
					}while(msg_cnt++ < 10);//一条命令最多的条数(模块长沙确认待定)

					if(mqtt_msg.msg_buf != NULL)
						free(mqtt_msg.msg_buf);
					
					return errOK;
				}break;

				case LIST_CMD_HHTTPDATA://HTTP发送(写)数据
				{
					phead = strstr(rcvbuf, "DOWNLOAD");
					if(!phead)
						return errRvcData;
					else
						return errOK;
				}break;
					
				case LIST_CMD_HTTPREAD:	//查询HTTP服务器返回数据
				{
					if((out_data != NULL) && (out_len != NULL))
					{
						in_data_len = *out_len;
						*out_len = 0;
					}
					else
					{
						return errBuffPara;
					}
						
					phead = strstr(rcvbuf, "+HTTPREAD: ");
					if(!phead)
						return errRvcData;

					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;		

					pend = strstr(phead, "\r\n");
					if(!pend)
						return errRvcData;
					
					phead += strlen("+HTTPREAD: ");
					if(pend - phead <= 0)
						return errRvcData;	

					*out_len = atoi(phead);
					if(in_data_len >= (*out_len)  )//检查数据输出缓存参数正确性						
					{
						pend += 2;//去掉\r\n
						memcpy(out_data,pend,*out_len);
					}
					else
					{
						return errBuffPara;
					}
					
					return errOK;
				}break;

				case LIST_CMD_REQ_SAPBR:		//查询HTTP功能的承载类型
				{
					http_sapbr_t http_sapbr;
					
					phead = strstr(rcvbuf, "+SAPBR: ");
					if(!phead)
						return errRvcData;

					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;		

					pend = strstr(phead, "\r\n");
					if(!pend)
						return errRvcData;		
					
					phead += strlen("+SAPBR: ");
					if(pend - phead <= 0)
						return errRvcData;	
					if(NULL != phead)
						http_sapbr.cid = atoi(phead);
					else
						return errRvcData;
					
					pdata = strstr(pdata,",");
					if(pdata != NULL)
					{
						pdata++;
						http_sapbr.status = atoi(pdata);
						if(http_sapbr.status != 1)
							return errSapbr;
					}
					else
					{
						return errRvcData;
					}

					pdata = strstr(pdata,",");
					if(pdata != NULL)
					{
						pdata++;
						memcpy(http_sapbr.ip,pdata,sizeof(http_sapbr.ip));
					}
					else
					{
						return errRvcData;
					}

					if((out_data != NULL) && (out_len != NULL) && ((*out_len) >= sizeof(http_sapbr_t)))		//检查数据输出缓存参数正确性
					{
						*out_len = sizeof(http_sapbr_t);
						memcpy(out_data,(char*)&http_sapbr,(*out_len));
					}
					else
					{
						return errBuffPara;
					}
					
					return errOK;
				}break;

				case LIST_CMD_NTPM: 	//查询连接小区信息
				{
					phead = strstr(rcvbuf, "%NTPM: ");
					if(!phead)
						return errRvcData;
					psure = strstr(rcvbuf, "OK");
					if(!psure)
						return errRvcData;
					
					pend = (psure - 2);//去掉回车换行
					if(!pend)
						return errRvcData;
					phead += (strlen("%NTPM: ") + 1);//去掉num
					if(pend - phead <= 0)
						return errRvcData;	
					
					if((out_data != NULL) && (out_len != NULL) && ((*out_len) >= (pend-phead)))//检查数据输出缓存参数正确性						
					{
						*out_len = (pend-phead);
						memcpy(out_data,phead,(*out_len));
					}
					else
					{
						return errBuffPara;
					}
				}break;
				
				default :
					break;
			}				
	
		}

		//OsThreadDelayS( WAITTIMECSQ );

	}while(try_cnt--);

	return errNotAnyData; 
}
		
static AT_RESULT common_raw_cmd_handle(AT_CMD_LIST cmd,char* in_data,char *out_data, unsigned int* out_len)
{
	switch(cmd)
	{
		case LIST_CMD_MIPSTART:	//建立TCP连接
			return raw_check_at_command(cmd,in_data,1,2,WAITE_2S*5,out_data,out_len,AT_CMDR_CONN_OK);
		break;
		
		case LIST_CMD_MCONNECT:	//请求会话连接
			return raw_check_at_command(cmd,in_data,1,2,WAITE_2S,out_data,out_len,AT_CMDR_MCONN_OK);
		break;
		
		case LIST_CMD_MSUB:		//订阅主题
			return raw_check_at_command(cmd,in_data,1,2,WAITE_2S,out_data,out_len,AT_CMDR_MSUB_OK);
		break;
		
		case LIST_CMD_MPUB:		//发布消息
			return raw_check_at_command(cmd,in_data,1,2,WAITE_2S,out_data,out_len,AT_CMDR_MPUB_OK);
		break;

		case LIST_CMD_HTTPACTION:		//HTTP方式激活
			return raw_check_at_command(cmd,in_data,1,2,WAITE_2S*5,out_data,out_len,AT_CMDR_HTTP_ACTION);
		break;
		
		default:
			return errAtCmd;
	}
	
	//return errAtCmd;
}

AT_RESULT manage_at_cmd(AT_CMD_LIST list_cmd, char * in_cmd_data,char *out_data, unsigned int* out_len)
{
	AT_RESULT ret;

	switch(list_cmd) {
	//返回OK/ERROR的AT处理
	case LIST_CMD_AT:
	case LIST_CMD_CSTT:			//设置APN,用户名,密码
	case LIST_CMD_MDISCONNECT:	//关闭MQTT连接
	case LIST_CMD_MIPCLOSE:	 	//关闭TCP连接
	
	case LIST_CMD_ATE0:			//关闭回显
	case LIST_CMD_HTTPINIT:			//初始化HTTP服务
	case LIST_CMD_HTTPTERM:			//终止HTTP任务
	case LIST_CMD_HTTPPARA: 		//设置HTTP参数值
	case LIST_CMD_SAPBR: 			//设置HTTP功能的承载类型
	case LIST_CMD_MQTTMSGSET: //设置MQTT接收消息模式
	case LIST_CMD_CNTP:			//同步网络时间
	case LIST_CMD_CNTPCID:		//设置GPRS承载场景ID
		ret = common_cmd_handle(list_cmd,in_cmd_data,false);
		break;
	
	case LIST_CMD_CIICR: 		//建立ppp连接(激活移动场景)
	case LIST_CMD_CIPSHUT:	//关闭移动场景
	case LIST_CMD_MCONFIG:		//设置MQTT相关参数	
        ret = common_cmd_handle(list_cmd,in_cmd_data,true);
        break;
        
	case LIST_CMD_CPIN:			//查询SIM卡是否READY
	case LIST_CMD_CSQ:			//查询信号强度
	case LIST_CMD_CGREG:		//查询注册状态
	case LIST_CMD_MQTTSTATU: 	//查询MQTT查询状态
	case LIST_CMD_CGATT:		//查询附着分离
	case LIST_CMD_CIFSR:		//查询IP地址
	case LIST_CMD_MQTTMSGGET:	//接收所有订阅消息
	case LIST_CMD_CCID:	//查询SIM卡ccid值
	case LIST_CMD_HHTTPDATA:		//HTTP写数据
	case LIST_CMD_HTTPREAD:			//查询HTTP服务响应
	case LIST_CMD_REQ_SAPBR:		//查询HTTP功能的承载类型
	case LIST_CMD_NTPM: 			//查询连接小区信息
	case LIST_CMD_AMGSMLOC: 		//获取基站定位（LBS）位置和日期时间
	case LIST_CMD_CCLK:			//获取时间
		ret = common_data_cmd_handle(list_cmd,in_cmd_data,out_data,out_len);
	break;
		
	//MQTT 异步操作
	case LIST_CMD_MIPSTART:	//建立TCP连接
	case LIST_CMD_MCONNECT:	//请求会话连接
	case LIST_CMD_MSUB:		//订阅主题
	case LIST_CMD_MPUB:		//发布消息
	case LIST_CMD_HTTPACTION: 		//HTTP方式激活
		ret = common_raw_cmd_handle(list_cmd,in_cmd_data,out_data,out_len);
	break;


	//定位信息与时间
	


	default:
		return errAtCmd;
		break;
	}

    return ret;
}



