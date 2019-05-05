#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "bll_log.h"
#include "BLL_manage_gprs.h"

char *str2str(char *buf, int len, char *fmt, ...)
{
	va_list args;
	memset(buf,0,len);
	va_start(args,fmt);
	vsprintf(buf,fmt,args);

	return buf;
}

static AT_RESULT wait_for_network_registered(void)
{
	AT_RESULT ret = errOK;
	unsigned int timeout = 0,len = 0;
	char data[256] = {0};
	
	//1.模块硬件是否正常
	ret = manage_at_cmd(LIST_CMD_AT,AT_CMD_AT,data, &len);
	while(errOK != ret && ++timeout < 3) 
	{
		printf("wait for gprs hw ready...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_AT,AT_CMD_AT,data, &len);
	}
	
	if(ret != errOK) 
	{
		printf("timeout=%d gprs hw is not ready!\n", timeout);
		return errGprsModule;
	}
	
	//2.SIM 是否READY
	timeout = 0;
	//memset(data,0,sizeof(data));
	ret = manage_at_cmd(LIST_CMD_CPIN,AT_CMD_CPIN,data, &len);
	while(errOK != ret && ++timeout < 3) 
	{
		printf("wait for SIM card ready...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_CPIN,AT_CMD_CPIN,data, &len);
	}
	if(ret != errOK) 
	{
		printf("timeout=%d SIM card is not ready!\n", timeout);
		return errSIMCard;
	}

	//读取CCID,PPP建立不需要此步骤
	timeout = 0;
	memset(data,0,sizeof(data));
	len = sizeof(data);
	ret = manage_at_cmd(LIST_CMD_CCID,AT_CMD_CCID,data, &len);
	while(errOK != ret && ++timeout < 3) 
	{
		printf("get CCID...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_CCID,AT_CMD_CCID,data, &len);
	}
	if(ret != errOK) 
	{
		printf("timeout=%d get CCID fail!\n", timeout);
		return errCardCcid;
	}
	else
	{
		printf("revc len=%d, ccid = %s\n",len,data);
	}

	//读取CSQ,PPP建立不需要此步骤
	timeout = 0;
	memset(data,0,sizeof(data));
	len = sizeof(data);
	ret = manage_at_cmd(LIST_CMD_CSQ,AT_CMD_CSQ,data, &len);
	while(errOK != ret && ++timeout < 3) 
	{
		printf("get CSQ...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_CSQ,AT_CMD_CSQ,data, &len);
	}
	if(ret != errOK) 
	{
		printf("timeout=%d get CSQ fail!\n", timeout);
		return errCSQ;
	}
	else
	{
		printf("revc len=%d, csq =%d \n",len,((rssi_data_t*)data)->rssi);
	}
	
	//3.网络注册状态 CGREG
	timeout = 0;
	//memset(data,0,sizeof(data));
	ret = manage_at_cmd(LIST_CMD_CGREG,AT_CMD_CGREG,data, &len);
	while(errOK != ret && ++timeout < 30) //需要一定的延时
	{
		printf("wait for gprs cgreg ready...\n");
		jd_om_msleep(100);
		ret = manage_at_cmd(LIST_CMD_CGREG,AT_CMD_CGREG,data, &len);
	}
	if(ret != errOK) 
	{
		printf("timeout=%d cgreg is not ready!\n", timeout);
		return errModuleReg;
	}

	//4.GPRS 附着状态
	timeout = 0;
	//memset(data,0,sizeof(data));
	ret = manage_at_cmd(LIST_CMD_CGATT,AT_CMD_CGATT,data, &len);
	while(errOK != ret && ++timeout < 3) 
	{
		printf("wait for gprs cgatt ready...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_CGATT,AT_CMD_CGATT,data, &len);
	}
	if(ret != errOK) 
	{
		printf("timeout=%d cgatt not ready!\n", timeout);
		return errAttach;
	}
	
	return ret;
}


AT_RESULT gprs_pppd_connect(void)
{
	AT_RESULT ret = errOK;
	unsigned int timeout = 0,len = 0;
	char data[256] = {0};
	char cmdstr[CMD_LEN] = {0};
	//1.等待网络注册完成
	ret = wait_for_network_registered();
	if(ret != errOK)
		return ret;
	
	//2.设置APN
	timeout = 0;
	str2str(cmdstr, sizeof(cmdstr), "%s%s\r\n", AT_CMD_CSTT,"\"cmiot\"");
	//printf("apn cmd=%s \n",cmdstr);
	ret = manage_at_cmd(LIST_CMD_CSTT,cmdstr,data,&len);
	while(errOK != ret && ++timeout < 3) 
	{
		printf("set apn...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_CSTT,cmdstr,data,&len);
	}
	if(ret != errOK) 
	{
		printf("timeout=%d set apn fail!\n", timeout);
		return errPPP;
	}
	
	//3.激活移动场景
	timeout = 0;
	ret = manage_at_cmd(LIST_CMD_CIICR,AT_CMD_CIICR,data, &len);
	while(errOK != ret && ++timeout < 3) 
	{
		printf("wait for ppp ready...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_CIICR,AT_CMD_CIICR,data, &len);
	}
	if(ret != errOK) 
	{
		printf("timeout=%d ppp fail!\n", timeout);
		return errPPP;
	}	
	
	//4.获取IP
	timeout = 0;
	memset(data,0,sizeof(data));
	len = sizeof(data);
	ret = manage_at_cmd(LIST_CMD_CIFSR,AT_CMD_CIFSR,data, &len);
	while(errOK != ret && ++timeout < 500) //需要延时一定的时间获取IP
	{
		printf("wait for get IP...\n");
		jd_om_msleep(20);
		ret = manage_at_cmd(LIST_CMD_CIFSR,AT_CMD_CIFSR,data, &len);
	}
	if(ret != errOK) 
	{
		printf("timeout=%d get IP fail!\n", timeout);
		return errIpFailed;
	}
	else
	{
		printf("revc len = %d, ip = %s \n",len,data);
	}

	return ret;
}


AT_RESULT http_send_data(char *buffer, unsigned int datalen,unsigned int timer)
{
	char cmdstr[CMD_LEN];
	char rcvbuf[512] = {0};
	unsigned int rcvlen = 0;
	AT_RESULT ret = errOK;
	unsigned char err = 0;
	unsigned int readtimes = 0;

	str2str(cmdstr,CMD_LEN,"%s%d,%d\r\n",AT_CMD_HHTTPDATA,datalen,timer);

	if(manage_at_cmd(LIST_CMD_HHTTPDATA,cmdstr,rcvbuf,&rcvlen) != errOK)
	{
		return errHttpData;
	}

	int ret_uart = 0;
	//发送长度为len的数据块(固定长度发送方式，在数据最后不需要增加0x1a结尾) 记得处理互斥资源*****
	ret_uart = at_uart_send_data(buffer, datalen); 
	printf("ret_uart =%d\n",ret_uart);


	while(readtimes++ < UART_SEND_TIMES)
	{
		printf("Waiting.....\n");
		memset(rcvbuf, 0, sizeof(rcvbuf));
		printf("rcvbuf len=%d \n",sizeof(rcvbuf));
		rcvlen = recieve_at_command(rcvbuf, sizeof(rcvbuf), WAITE_2S, &err);
		if(rcvlen == 0)
		{
			printf("1111111\n");
			continue;
		}
		else
		{
			if(memncmp(rcvbuf,AT_CMDR_OK, rcvlen, strlen(AT_CMDR_OK)))
			{
				printf("http post send ok88888\n");
				
				return errOK;
			}
			printf("2222222\n");
			continue;
		}
	}

	if(readtimes >= UART_SEND_TIMES)
	{
		printf("333333\n");
		return  errHttpData;
	}
	else
	{
		return errOK;
	}
}


AT_RESULT http_revc_data(char *buffer, unsigned int *buflen, unsigned int startaddr)
{
	char cmdstr[CMD_LEN];
	unsigned int rcvlen = ((*buflen) < 2048) ? (*buflen) : 2048;
	*buflen = rcvlen;

	if(buflen != NULL)
		str2str(cmdstr,CMD_LEN,"%s%d,%d\r\n",AT_CMD_HTTPREAD,startaddr,rcvlen);
	else
		strcpy(cmdstr,AT_CMD_HTTPREAD_A);

	return manage_at_cmd(LIST_CMD_HTTPREAD,cmdstr,buffer,buflen);
}


AT_RESULT http_post_int(void)
{
	char cmdstr[CMD_LEN];
	AT_RESULT ret = errOK;
	unsigned int timeout = 0,len = 0;
	char data[256] = {0};

	//1.设置HTTP功能的承载类型
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%d,%d,%s,%s\r\n",AT_CMD_SAPBR,3,1,"\"CONTYPE\"","\"GPRS\"");	
	ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("wait for set CONTYPE sapbr ready...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d set CONTYPE sapbr fail!\n", timeout);
		return errSapbr;
	}

	//2.设置HTTP功能的APN
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%d,%d,%s,%s\r\n",AT_CMD_SAPBR,3,1,"\"APN\"","\"cmiot\"");	
	ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("wait for sapbr set APN ready...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d sapbr set APN fail!\n", timeout);
		return errSapbr;
	}	

	//3.保存cid=1的承载的相关参数
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%d,%d\r\n",AT_CMD_SAPBR,5,1);	
	ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("wait for save sapbr ready...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);		
	}
	
	if(ret != errOK) 
	{
		printf("timeout=%d save sapbr fail!\n", timeout);
		return errSapbr;
	}	

	//4.激活该承载的GPRS PDP上下文
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%d,%d\r\n",AT_CMD_SAPBR,1,1);	
	ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("wait for activate sapbr...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d activate  sapbr fail!\n", timeout);
		return errSapbr;
	}	

	//5.查询承载状态
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%d,%d\r\n",AT_CMD_SAPBR,2,1);	
	ret = manage_at_cmd(LIST_CMD_REQ_SAPBR,cmdstr,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("get sapbr status...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_SAPBR,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d get sapbr status fail!\n", timeout);
		return errSapbr;
	}	

#if 0	
	//6.HTTP协议栈初始化
	//memset(cmdstr,0,sizeof(cmdstr));
	//str2str(cmdstr,CMD_LEN,"%s%d,%d\r\n",AT_CMD_SAPBR,1,1);	
	ret = manage_at_cmd(LIST_CMD_HTTPINIT,AT_CMD_HTTPINIT,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("init http...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_HTTPINIT,AT_CMD_HTTPINIT,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d init http fail!\n", timeout);
		return errHttpInit;
	}
#endif

	return ret;
}


AT_RESULT http_post_perform(char *buffer, unsigned int* datalen, char* url, unsigned int timer)
{
	char cmdstr[CMD_LEN];
	AT_RESULT ret = errOK;
	unsigned int timeout = 0,len = 0;
	char data[256] = {0};	
	
	//ret = http_post_int();
	//if(ret != errOK)
	//	return ret;

	//0.HTTP协议栈初始化
	//memset(cmdstr,0,sizeof(cmdstr));
	//str2str(cmdstr,CMD_LEN,"%s%d,%d\r\n",AT_CMD_SAPBR,1,1);	
	ret = manage_at_cmd(LIST_CMD_HTTPINIT,AT_CMD_HTTPINIT,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("init http...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_HTTPINIT,AT_CMD_HTTPINIT,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d init http fail!\n", timeout);
		return errHttpInit;
	}

	//1.设置HTTP会话参数：CID
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%s,%d\r\n",AT_CMD_HTTPPARA,"\"CID\"",1);	
	ret = manage_at_cmd(LIST_CMD_HTTPPARA,cmdstr,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("set http CID para...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_HTTPPARA,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d set http CID fail!\n", timeout);
		return errHttpPara;
	}

	//2.设置HTTP URL
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%s,%s\r\n",AT_CMD_HTTPPARA,"\"URL\"",url);	
	ret = manage_at_cmd(LIST_CMD_HTTPPARA,cmdstr,data,&len);
	while(errOK != ret && ++timeout < 3)
	{
		printf("set http URL...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_HTTPPARA,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d set http URL fail!\n", timeout);
		return errHttpPara;
	}

	//3.HTTP POST 发送数据,注意串口资源互斥
	*datalen = strlen(buffer);//发送数据长度
	ret = http_send_data(buffer,*datalen,timer);

	if(ret != errOK)
	{
		return errHttpData;
	}

	//4.执行
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%d\r\n",AT_CMD_HTTPACTION,1);	
	len = sizeof(data);
	ret = manage_at_cmd(LIST_CMD_HTTPACTION,cmdstr,data,&len);
    
	if(ret != errOK)
		return errHttpAction;
    
    printf("the post action=%d, post status=%d, datalen=%d \n",((http_action_result_t *)data)->method,((http_action_result_t*)data)->status_code,((http_action_result_t*)data)->data_len);
    
	return ret;
}


AT_RESULT http_post_revc_data(char *buffer, unsigned int* datalen)
{
		AT_RESULT ret = errOK;
		memset(buffer,0,sizeof(buffer));
        //*datalen = sizeof(buffer);
		ret = manage_at_cmd(LIST_CMD_HTTPREAD,AT_CMD_HTTPREAD_ALL,buffer,datalen);

		if(ret == errOK)
			ret = manage_at_cmd(LIST_CMD_HTTPTERM,AT_CMD_HTTPTERM,NULL,NULL);//销毁HTTP
			
		return ret;
}


//发布消息,注意发送缓存
AT_RESULT mqtt_pub_msg(char* topic, unsigned char qos, bool retain, char* message)
{
	char cmdstr[512];
	AT_RESULT ret = errOK;
	unsigned int timeout = 0,len = 0;
	char data[256] = {0};	

	//MQTT发布消息
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,sizeof(cmdstr),"%s%s,%d,%d,%s\r\n",AT_CMD_MPUB,topic,qos,retain,message);	
	ret = manage_at_cmd(LIST_CMD_MPUB,cmdstr,data,&len);

	while(errOK != ret && ++timeout < 3)
	{
		printf("mqtt pub msg...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_MPUB,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d mqtt pub msg fail!\n", timeout);
		return errMQTTPub;
	}	

	return ret;
}


//获取订阅信息
AT_RESULT mqtt_get_sub_msg(char* revcmsg, unsigned int *revc_len)
{
	AT_RESULT ret = errOK;
	
	if((revcmsg == NULL) || (revc_len == NULL))
		return errAtCmd;

	//MQTT获取订阅消息
	ret = manage_at_cmd(LIST_CMD_MQTTMSGGET,AT_CMD_MQTTMSGGET,revcmsg,revc_len);
	
	return ret;
}


AT_RESULT mqtt_init(void)
{
	char cmdstr[CMD_LEN];
	AT_RESULT ret = errOK;
	unsigned int timeout = 0,len = 0;
	char data[256] = {0};	

	//1.设置MQTT参数
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%s,%s,%s\r\n",AT_CMD_MCONFIG,"\"client_id_2\"","\"admin\"","\"public\"");	
	ret = manage_at_cmd(LIST_CMD_MCONFIG,cmdstr,data,&len);

	while(errOK != ret && ++timeout < 3)
	{
		printf("set mqtt para...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_MCONFIG,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d set mqtt para fail!\n", timeout);
		return errMQTTSetCfg;
	}	

	//2.MQTT TCP 连接
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%s,%s\r\n",AT_CMD_MIPSTART,"\"120.79.223.61\"","\"1883\"");	
	ret = manage_at_cmd(LIST_CMD_MIPSTART,cmdstr,data,&len);

	while(errOK != ret && ++timeout < 10)
	{
		printf("mqtt connect tcp...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_MIPSTART,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d mqtt connect tcp fail!\n", timeout);
		return errMQTTTCPConnect;
	}	

	//3.MQTT请求会话连接
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%d,%d\r\n",AT_CMD_MCONNECT,1,60);	
	ret = manage_at_cmd(LIST_CMD_MCONNECT,cmdstr,data,&len);

	while(errOK != ret && ++timeout < 3)
	{
		printf("mqtt  section connect...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_MCONNECT,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d mqtt section connect fail!\n", timeout);
		return errMQTTConnect;
	}	

	//4.MQTT设置接收消息模式
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%d\r\n",AT_CMD_MQTTMSGSET,1);	
	ret = manage_at_cmd(LIST_CMD_MQTTMSGSET,cmdstr,data,&len);

	while(errOK != ret && ++timeout < 3)
	{
		printf("set mqtt msg mode...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_MQTTMSGSET,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d set mqtt msg mode fail!\n", timeout);
		return errMQTTSetMsg;
	}	

	//5.MQTT订阅主题
	memset(cmdstr,0,sizeof(cmdstr));
	str2str(cmdstr,CMD_LEN,"%s%s,%d\r\n",AT_CMD_MSUB,"\"STC/#\"",1);	
	ret = manage_at_cmd(LIST_CMD_MSUB,cmdstr,data,&len);

	while(errOK != ret && ++timeout < 3)
	{
		printf("mqtt sub...\n");
		jd_om_msleep(1);
		ret = manage_at_cmd(LIST_CMD_MSUB,cmdstr,data,&len);		
	}
	if(ret != errOK) 
	{
		printf("timeout=%d set mqtt sub fail!\n", timeout);
		return errMQTTSub;
	}		

	return ret;
}


