/*
 * typedef
 * 2017-09-18
 * 盛耀微科技
 * wxj@glinkwin.com
 */



#ifndef __TYPEDEF_HH__
#define __TYPEDEF_HH__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#define LLC_UART	0
#define LLC_UDP		1

#define MALLOC_EN	1
#define LLC_TYPE	LLC_UART

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
//typedef unsigned int uint32_t;
typedef unsigned int UINT;

#define bool u8
#define true 1
#define false 0

#define dberr printf
#define dbinfo printf
#define debug printf
#define dump dump_buffer


#define dzlog_info debug
#define dzlog_debug debug
#define dzlog_error dberr


#define EXPORT_API

#endif
