/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2018 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
/* --- */
#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
/* --- */
#include "xc/test/xc_test.h"
/* --- */


int xc_test_msg(const char* fmt, ...)
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

xc_test_data_t xc_test_data_initializer(const char* label_str)
{
	xc_test_data_t t__testdata={0};
	
	t__testdata.cur_label_str=label_str;
	return t__testdata;
}

