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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
/* --- */
#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
#include "xc/am_seq/xc_ammo_seq.h"
/* --- */
#include "xc/common/xc_cstr.h"
/* --- */

xc_cstrRo_t xc_cstrRo(const char* str)
{
	xc_cstrRo_t retv={0};
	
	retv.ro_buf=str;
	retv.ro_len=strlen(str);
	
	return retv;
}


int xc_cstrd_vfmt(xc_cstrd_t* refp_self, const char* fmt, va_list arg_va)
{
	int snprintf_retv=0;
	int retv=0;
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	snprintf_retv=vsnprintf(NULL, 0, fmt, arg_va);
	
	if( snprintf_retv < 0 ) {
		xc_err_term_unmg();
	}
	else
	if( 0 == snprintf_retv )
	{
		char* ptr2alloc=NULL;
		
		if( NULL == (ptr2alloc=xc_mem_u_allocz_bytes(1) ) ) {
			xc_err_term_unmg();
		}
		
		ptr2alloc[0]=0x0;
		
		refp_self->d_buf=ptr2alloc;
		refp_self->d_len=1;
		refp_self->d_capacity=snprintf_retv+1;
	}
	else
	if( snprintf_retv > 0 )
	{
		char* ptr2alloc=NULL;
		
		if( NULL == (ptr2alloc=xc_mem_u_allocz_bytes(snprintf_retv+1) ) ) {
			xc_err_term_unmg();
		}
		
		vsnprintf(ptr2alloc, snprintf_retv+1, fmt, arg_va);
		
		refp_self->d_buf=ptr2alloc;
		refp_self->d_len=snprintf_retv;
		refp_self->d_capacity=snprintf_retv+1;
	}
	
	return 0;
	
	xc_err_on_unmg();
	if(refp_self) {
		xc_mem_u_bzero_obj(xc_cstrd_t, refp_self);
	}
	return 1;
}

int xc_cstrd_deinit(xc_cstrd_t* refp_self)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL != refp_self->d_buf ) {
		free(refp_self->d_buf);
	}
	
	xc_mem_u_bzero_obj(xc_cstrd_t, refp_self);
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
