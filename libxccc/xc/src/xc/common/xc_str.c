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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
/* --- */
#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
#include "xc/am_seq/xc_am_seq.h"
/* --- */
#include "xc/common/xc_str.h"
/* --- */

int xc_str_calc_overflow_offLen(const int orig_capacity, const int orig_len, const int target_off, const int addedlen, int* result_overflow)
{
	if(NULL==result_overflow) {
		return 1;
	}
	if(orig_capacity<=0) {
		return 1;
	}
	if(orig_len<=0) {
		return 1;
	}
	if(addedlen < 0) {
		return 1;
	}
	if(target_off>orig_len) {
		return 1;
	}
	/* --- */
	
	if( target_off + addedlen + 1 > orig_capacity ) {
		*result_overflow=( target_off + addedlen + 1 - orig_capacity );
	}
	else {
		*result_overflow=0;
	}

	return 0;
}

int xc_str_off_validLenBound(const int capacity, const int len, const int tested_off)
{
	if( xc_str_is_npos(tested_off) ) {
		return 1;
	}
	if(tested_off>=len) {
		return 1;
	}
	
	return 0;
}

int xc_str_offLen_validLenBound(const int capacity, const int len, const int tested_off, const int tested_len, int* result_len)
{
	int retv=0;
	int tmp_result=0;
	
	if( NULL == result_len ) {
		retv=10;
	}
	if( capacity <= 0 ) {
		retv=20;
	}
	if( len < 0 ) {
		retv=30;
	}
	if( tested_off < 0 ) {
		retv=40;
	}
	if( tested_off >= len ) {
		retv=50;
	}
	/* --- */
	
	if(0 == retv)
	{
		if( xc_str_is_npos(tested_len) )
		{ /* npos: */
			
			tmp_result=( len - tested_off );
			
		} /* npos: done */
		else
		{ /* fixed within len: */
			
			if( tested_off + tested_len < len ) {
				tmp_result=( tested_len );
			}
			else {
				tmp_result=( len - tested_off );
			}
			
		} /* fixed within len: done */
		
		*result_len=tmp_result;
		
		return 0;
	}
	else
	{
		if(NULL != result_len) {
			*result_len=xc_str_npos;
		}
		
		return retv;
	}
}
