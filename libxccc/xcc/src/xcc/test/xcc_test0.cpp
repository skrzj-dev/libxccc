/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2019 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* --- */
#ifdef _WIN32

#include <windows.h>
#include <tchar.h>

#else 

#include <unistd.h>

#endif
/* --- */
/* --- */
#include "xcc/test/xcc_test0.hpp"
/* --- */

xcc_test0_data_scopeInfo xcc_test0_data_scopeInfo_LL_initializer(const char* filename, const char* fnname, const int line)
{
	xcc_test0_data_scopeInfo retv={0};
	
	snprintf(retv.filename, sizeof(retv.filename), "%s", filename);
	snprintf(retv.fnname, sizeof(retv.fnname), "%s", fnname);
	retv.line=line;
	
	return retv;
}

xcc_test0_data_failInfo xcc_test0_data_failInfo_LL_initializer(xcc_test0_data_scopeInfo scopeInfo, xcc_test0_data_annotation annotation)
{
	xcc_test0_data_failInfo retv={0};
	
	retv.scopeInfo=scopeInfo;
	retv.annotation=annotation;
	
	return retv;
}

xcc_test0_data_annotation xcc_test0_data_annotation_initializer(const char* static_str, const char* runtime_str_fmt, ...)
{
	xcc_test0_data_annotation retv={0};
	va_list args;
	
	try
	{
		if(NULL == static_str) {
			throw 1;
		}
		if(NULL == runtime_str_fmt) {
			throw 1;
		}
		
		snprintf(retv.static_part, sizeof(retv.static_part),  "%s", static_str);
		
		va_start (args, runtime_str_fmt);
		vsnprintf(retv.runtime_part, sizeof(retv.runtime_part), runtime_str_fmt, args);
		va_end (args);
		
		return retv;
	}
	catch(...)
	{
		return retv;
	}
}

int xcc_test0_msg(const char* fmt, ...)
{
	va_list args;
	char buffer[256]={0};
	
	if(NULL==fmt) {
		return 1;
	}
	
	va_start (args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end (args);
	
	fprintf(stdout, "%s\n", buffer);
	
	return 0;
}

