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
#include <stdint.h>
/* --- */
#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
#include "xc/am_seq/xc_am_seq.h"
/* --- */
#include "xc/common/xc_cstr.h"
#include "xc/common/xc_str.h"
#include "xc/common/xc_strd.h"
#include "xc/common/xc_si.h"
/* --- */

/* initialization indicator */
#define xc_strd_INITBASE (10120)

/* --- --- --- --- */

struct xc_strd_private_t
{
	int d_capacity;
	int d_length;
	char* d_buf;
	char d_dummy[1];
	
};

static void xc_strd_updateLen(xc_strd_t* refp_self);

static int xc_strd_set_LL(xc_strd_t* refp_self, const size_t str_len, const char* str);

static int xc_strd_insert_LL(xc_strd_t* refp_self, const int target_off, const size_t str_len, const char* str);

static int xc_strd_overwr_LL(xc_strd_t* refp_self, const int target_off, const int str_len, const char* str);

static int xc_strd_substSubstr_LL(xc_strd_t* refp_self, const xc_cstrRo_t str_replaced, const xc_cstrRo_t str_replacement);

static int xc_strd_realloc_alias_LL(xc_strd_t* refp_self, const int new_requested_length);

/* --- --- --- --- */

static void xc_strd_updateLen(xc_strd_t* refp_self)
{
	if(NULL==refp_self) {
		return;
	}
	if(NULL==refp_self->d_private) {
		return;
	}
	
	if(NULL!=refp_self->d_private->d_buf) {
		refp_self->d_private->d_length=strlen(refp_self->d_private->d_buf);
	}
	else {
		refp_self->d_private->d_length=0;
	}
	
	return;
}

static int xc_strd_realloc_alias_LL(xc_strd_t* refp_self, const int new_requested_length)
{
	xc_p_pBytes_t tmp_byteptr={0};
	xc_am_seq_cfg_t tmp_cfg=xc_am_seq_cfg_retv(
		  sizeof(xc_str_char_t)
		, 1
	);
	xc_am_seq_state_t tmp_input=xc_am_seq_state_retv(
		  xc_p_refp2pBytes_from_raw( (unsigned char**)&refp_self->d_private->d_buf )
		, refp_self->d_private->d_length
		, refp_self->d_private->d_capacity
	);
	xc_am_seq_state_t tmp_output={0};
	
	xc_err_decl();
	
	if(0!=xc_am_seq_tStatic_realloc(
			  &tmp_cfg
			, &tmp_input
			, &tmp_output
			, new_requested_length+1
		) 
	) {
		xc_err_term_unmg();
	}
	tmp_byteptr=xc_p_pBytes_from_ref2pBytes(tmp_output.refp_itemArray_byteptr);
	refp_self->d_private->d_buf=(char*)tmp_byteptr.BtPtr;
	refp_self->d_private->d_capacity=tmp_output.capacity;
	refp_self->d_private->d_length=tmp_output.length;
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

/* --- --- --- --- */

const char* xc_strd_cstr(const xc_strd_t* refp_self)
{
	xc_err_decl();
	
	if(1)
	{
		if(NULL == refp_self) {
			return NULL;
		}
	}
	/* --- */
	if(1)
	{
		if( 0 == xc_strd_isInit(refp_self) ) {
			return NULL;
		}
	}
	/* --- */
	
	return refp_self->d_private->d_buf;
	
	xc_err_on_unmg();
	return NULL;
}

int xc_strd_isInit(const xc_strd_t* refp_self)
{
	if(NULL == refp_self) {
		return 0;
	}
	/* --- */
	
	if(NULL==refp_self->d_private) {
		return 0;
	}
	
	if( 0 == xc_initc_anyscopeNZ_isValid_u(&refp_self->d_inits, xc_strd_INITBASE) ) {
		return 0;
	}
	
	return 1;
}


int xc_strd_init(xc_strd_t* refp_self)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( xc_strd_isInit(refp_self) ) {
		xc_strd_deinit(refp_self);
	}
	
	/* --- */
	
	xc_mem_u_bzero_obj(xc_strd_t, refp_self);
	
	refp_self->d_private=xc_mem_u_allocz_obj(xc_strd_private_t);
	
	if(NULL == refp_self->d_private ) {
		xc_err_term_unmg();
	}
	
	/* init members values:  */
	if(1)
	{
		if(0!=xc_initc_anyscopeNZ_init_c(&refp_self->d_inits, xc_strd_INITBASE) ) {
			xc_err_term_unmg();
		}
		
		refp_self->d_private->d_dummy[0]=0;
		
		if(0!=xc_strd_realloc_alias_LL(refp_self, 1) ) {
			xc_err_term_unmg();
		}
	}
	/* init members values: done */
	
	return 0;
	
	xc_err_on_unmg();
	/* cleanup: */
	if( NULL != refp_self)
	{
		if(NULL != refp_self->d_private )
		{
			if(NULL!=refp_self->d_private->d_buf) {
				free(refp_self->d_private->d_buf);
			}
			
			xc_mem_u_bzero_obj(xc_strd_private_t, refp_self->d_private);
			free(refp_self->d_private);
		}
		
		xc_mem_u_bzero_obj(xc_strd_t, refp_self);
	}
	/* cleanup: done */
	
	return 1;
}
int xc_strd_init_fmt(xc_strd_t* refp_self, const char* fmt, ...)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( xc_strd_isInit(refp_self) ) {
		xc_strd_deinit(refp_self);
	}
	/* --- */
	
	if( 0 != xc_strd_init(refp_self) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		va_list arg_va;
		int retv=0;
		
		va_start(arg_va, fmt);
		if( 0 != xc_strd_set_vfmt(refp_self, fmt, arg_va) ) {
			/* manageable error */
		}
		va_end(arg_va);
		
		if(0!=retv) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_strd_deinit(refp_self);
	return 1;
}
int xc_strd_init_vfmt(xc_strd_t* refp_self, const char* fmt, va_list arg_va)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( xc_strd_isInit(refp_self) ) {
		xc_strd_deinit(refp_self);
	}
	/* --- */
	
	if( 0 != xc_strd_init(refp_self) ) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strd_set_vfmt(refp_self, fmt, arg_va) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_strd_deinit(refp_self);
	return 1;
}

int xc_strd_deinit(xc_strd_t* refp_self)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	
	if( NULL != refp_self->d_private )
	{
		if( NULL != refp_self->d_private->d_buf ) {
			free(refp_self->d_private->d_buf);
		}
		
		xc_mem_u_bzero_obj(xc_strd_private_t, refp_self->d_private);
		free(refp_self->d_private);
	}
	
	xc_mem_u_bzero_obj(xc_strd_t, refp_self);
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_strd_getLength(const xc_strd_t* refp_self)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	
	return refp_self->d_private->d_length;
	
	xc_err_on_unmg();
	return 0;
}

int xc_strd_getLastOff(const xc_strd_t* refp_self)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	
	if( refp_self->d_private->d_length <= 0 ) {
		return 0;
	}
	
	return refp_self->d_private->d_length-1;
	
	xc_err_on_unmg();
	return xc_str_npos;
}

static int xc_strd_set_LL(xc_strd_t* refp_self, const size_t str_len, const char* str)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != xc_strd_realloc_alias_LL(refp_self, str_len) ) {
		xc_err_term_unmg();
	}
	
	xc_mem_bzero_bytes(refp_self->d_private->d_buf, refp_self->d_private->d_capacity);  /* TODO redundant after custom realloc enforcing zeroed bytes? */
	xc_mem_u_cp_obj_array(char, str_len, refp_self->d_private->d_buf, str);
	
	xc_strd_updateLen(refp_self);
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_set(xc_strd_t* refp_self, const xc_strd_t* refp_str)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != xc_strd_set_LL(refp_self, refp_str->d_private->d_length, refp_str->d_private->d_buf) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_set_fmt(xc_strd_t* refp_self, const char* fmt, ...)
{
	xc_cstrd_t tmp_cstrd={0};
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		va_list tmp_va;
		int retv=0;
		
		va_start(tmp_va, fmt);
		if( 0 != (retv=xc_cstrd_vfmt(&tmp_cstrd, fmt, tmp_va) ) ) {
			/* manageable error */
		}
		va_end(tmp_va);
		
		if(0!=retv) {
			xc_err_term_unmg();
		}
	}
	
	if( 0 != xc_strd_set_LL(refp_self, tmp_cstrd.d_len, tmp_cstrd.d_buf) ) {
		xc_err_term_unmg();
	}
	
	xc_cstrd_deinit(&tmp_cstrd);
	
	return 0;
	
	xc_err_on_unmg();
	xc_cstrd_deinit(&tmp_cstrd);
	return 1;
}
int xc_strd_set_vfmt(xc_strd_t* refp_self, const char* fmt, va_list arg_va)
{
	xc_cstrd_t tmp_cstrd={0};
	int retv=0;
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != (retv=xc_cstrd_vfmt(&tmp_cstrd, fmt, arg_va) ) ) {
		/* manageable error */
	}
	
	if(0!=retv) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strd_set_LL(refp_self, tmp_cstrd.d_len, tmp_cstrd.d_buf) ) {
		xc_err_term_unmg();
	}
	
	xc_cstrd_deinit(&tmp_cstrd);
	
	return 0;
	
	xc_err_on_unmg();
	xc_cstrd_deinit(&tmp_cstrd);
	return 1;
}



static int xc_strd_insert_LL(xc_strd_t* refp_self, const int target_off, const size_t str_len, const char* str)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == str) {
		xc_err_term_unmg();
	}
	if(0 == str_len) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* check if target offset is valid: */
	if(1)
	{
		const int last_off=xc_strd_getLastOff(refp_self);
		
		if( target_off < 0 ) {
			xc_err_term_unmg();
		}
		
		if( target_off > refp_self->d_private->d_length ) {
			xc_err_term_unmg();
		}
		else {
			/* OK : either <0;length) which means insert OR <0;length> which means append at end */
		}
		
	}
	/* check if target offset is valid: done */
	
	/* realloc: */
	if(1)
	{
		if( 0 != xc_strd_realloc_alias_LL(refp_self, str_len ) ) {
			xc_err_term_unmg();
		}
	}
	/* realloc: done */
	
	/* write values to grown array: */
	if(1)
	{
		xc_mem_u_cp_bytes(str_len, refp_self->d_private->d_buf+target_off, str);
	}
	/* write values to grown array: done */
	
	xc_strd_updateLen(refp_self);
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_insert(xc_strd_t* refp_self, const int target_off, const xc_strd_t* refp_str)
{
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strd_isInit(refp_str) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != xc_strd_insert_LL(refp_self, target_off, refp_str->d_private->d_length, refp_str->d_private->d_buf) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_insert_sub(xc_strd_t* refp_self, const int target_off, const xc_strd_t* refp_str, const xc_str_substrOffs_t offs)
{
	int validated_sub_len=0;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strd_isInit(refp_str) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* validate / adjust sub offset vs src str: */
	if( 0 != xc_str_offLen_validLenBound(
			  refp_self->d_private->d_capacity
			, refp_self->d_private->d_length
			, offs.off
			, offs.length
			, &validated_sub_len
		)
	)
	{
		xc_err_term_unmg();
	}
	/* validate / adjust sub offset vs src str: done */
	
	if( 0 != xc_strd_insert_LL(refp_self, target_off, validated_sub_len, refp_str->d_private->d_buf+offs.off) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_insert_fmt(xc_strd_t* refp_self, const int target_off, const char* fmt, ...)
{
	xc_cstrd_t tmp_cstrd={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		va_list tmp_va;
		int retv=0;
		
		va_start(tmp_va, fmt);
		if( 0 != (retv=xc_cstrd_vfmt(&tmp_cstrd, fmt, tmp_va) ) ) {
			/* manageable error */
		}
		va_end(tmp_va);
		
		if(0!=retv) {
			xc_err_term_unmg();
		}
	}
	
	if( 0 != xc_strd_insert_LL(refp_self, target_off, tmp_cstrd.d_len, tmp_cstrd.d_buf ) ) {
		xc_err_term_unmg();
	}
	
	xc_cstrd_deinit(&tmp_cstrd);
	
	return 0;
	
	xc_err_on_unmg();
	xc_cstrd_deinit(&tmp_cstrd);
	return 1;
}
int xc_strd_insert_vfmt(xc_strd_t* refp_self, const int target_off, const char* fmt, va_list arg_va)
{
	xc_cstrd_t tmp_cstrd={0};
	int retv=0;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != (retv=xc_cstrd_vfmt(&tmp_cstrd, fmt, arg_va) ) ) {
		/* manageable error */
	}
	
	if(0!=retv) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strd_insert_LL(refp_self, target_off, tmp_cstrd.d_len, tmp_cstrd.d_buf ) ) {
		xc_err_term_unmg();
	}
	
	xc_cstrd_deinit(&tmp_cstrd);
	
	return 0;
	
	xc_err_on_unmg();
	xc_cstrd_deinit(&tmp_cstrd);
	return 1;
}

int xc_strd_append(xc_strd_t* refp_self, const xc_strd_t* refp_str)
{
	xc_err_decl();
	
	if(0 != xc_strd_insert(refp_self, xc_strd_getLength(refp_self), refp_str) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_append_sub(xc_strd_t* refp_self, const xc_strd_t* refp_str, const xc_str_substrOffs_t range)
{
	xc_err_decl();
	
	if(0 != xc_strd_insert_sub(refp_self, xc_strd_getLength(refp_self), refp_str, range) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_append_fmt(xc_strd_t* refp_self, const char* fmt, ...)
{
	xc_err_decl();

	if(1)
	{
		va_list tmp_va;
		int retv=0;
		
		va_start(tmp_va, fmt);
		if(0 != ( retv = xc_strd_insert_vfmt(refp_self, xc_strd_getLength(refp_self), fmt, tmp_va) ) ) {
			/* manageable error */
		}
		va_end(tmp_va);
		
		if(0!=retv) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_append_vfmt(xc_strd_t* refp_self, const char* fmt, va_list args)
{
	xc_err_decl();
	
	if(0 != xc_strd_insert_vfmt(refp_self, xc_strd_getLength(refp_self), fmt, args) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_strd_prepend(xc_strd_t* refp_self, const xc_strd_t* refp_str)
{
	xc_err_decl();
	
	if(0 != xc_strd_insert(refp_self, 0, refp_str) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_prepend_fmt(xc_strd_t* refp_self, const char* fmt, ...)
{
	xc_err_decl();
	
	if(1)
	{
		va_list tmp_va;
		int retv=0;
		
		va_start(tmp_va, fmt);
		if(0 != ( retv = xc_strd_insert_vfmt(refp_self, 0, fmt, tmp_va) ) ) {
			/* manageable */
		}
		va_end(tmp_va);
		
		if(0 != retv) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_prepend_vfmt(xc_strd_t* refp_self, const char* fmt, va_list args)
{
	xc_err_decl();
	
	if(0 != xc_strd_insert_vfmt(refp_self, 0, fmt, args) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}



static int xc_strd_overwr_LL(xc_strd_t* refp_self, const int target_off, const int str_len, const char* str)
{
	xc_err_decl();
	
	/* resize so it's varranted that buffer will store new buffer: */
	if(0) /* TODO */
	{
		int tmp_overfl=0;
		
		if(0!=xc_str_calc_overflow_offLen(
				  refp_self->d_private->d_capacity
				, refp_self->d_private->d_length
				, target_off
				, str_len
				, &tmp_overfl
			) 
		) {
			xc_err_term_unmg();
		}
		
		if(tmp_overfl > 0 )
		{
			if( 0 != xc_strd_realloc_alias_LL(refp_self, target_off+str_len ) ) {
				xc_err_term_unmg();
			}
		}
	}
	if(1)
	{
		if( 0 != xc_strd_realloc_alias_LL(refp_self, target_off+str_len ) ) {
			xc_err_term_unmg();
		}
	}
	/* resize so it's varranted that buffer will store new buffer: done */
	
	/*  overwrite buffer at off: */
	if(1)
	{
		xc_mem_u_cp_bytes(str_len, refp_self->d_private->d_buf+target_off, str);
	}
	/* overwrite buffer at off: done */
	
	xc_strd_updateLen(refp_self);
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_overwrOff(xc_strd_t* refp_self, const int target_off, const xc_strd_t* refp_str)
{
	int retv=0;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strd_isInit(refp_str) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != (retv=xc_strd_overwr_LL(refp_self, target_off, refp_str->d_private->d_length, refp_str->d_private->d_buf) ) ) {
		/* manageable error */
	}
	
	if(0!=retv) {
		xc_err_term_unmg();
	}
	
	return retv;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_overwrOff_fmt(xc_strd_t* refp_self, const int target_off, const char* fmt, ...)
{
	xc_err_decl();
	
	if(1)
	{
		va_list tmp_va;
		int retv=0;
		
		va_start(tmp_va, fmt);
		if( 0 != ( retv = xc_strd_overwrOff_vfmt(refp_self, target_off, fmt, tmp_va) ) ) {
			/* manageable */
		}
		va_end(tmp_va);
		
		if(0 != retv) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_overwrOff_vfmt(xc_strd_t* refp_self, const int target_off, const char* fmt, va_list arg_va)
{
	xc_cstrd_t tmp_cstrd={0};
	int retv=0;
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != xc_cstrd_vfmt(&tmp_cstrd, fmt, arg_va) ) {
		xc_err_term_unmg();
	}
	
	if( 0 != (retv=xc_strd_overwr_LL(refp_self, target_off, tmp_cstrd.d_len, tmp_cstrd.d_buf) ) ) {
		/* manageable error */
	}
	
	if(0 != retv) {
		xc_err_term_unmg();
	}

	xc_cstrd_deinit(&tmp_cstrd);
	
	return 0;
	
	xc_err_on_unmg();
	xc_cstrd_deinit(&tmp_cstrd);
	return 1;
}


int xc_strd_substrOffLen_alloc(const xc_strd_t* refp_self, const int off, const int len, xc_strd_t* refp_result)
{
	int target_validated_len=0;
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strd_isInit(refp_result) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(0!=xc_str_off_validLenBound(refp_self->d_private->d_capacity, refp_self->d_private->d_length, off) ) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_str_offLen_validLenBound(
			  refp_self->d_private->d_capacity
			, refp_self->d_private->d_length
			, off
			, len
			, &target_validated_len
		) 
	) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strd_set_LL(refp_result, target_validated_len, refp_self->d_private->d_buf+off) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_substrOffRange_alloc(const xc_strd_t* refp_self, const int off1, const int off2, xc_strd_t* refp_result)
{
	int calc_len=0;
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strd_isInit(refp_result) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(0!=xc_str_off_validLenBound(refp_self->d_private->d_capacity, refp_self->d_private->d_length, off1) ) {
		xc_err_term_unmg();
	}
	if(0!=xc_str_off_validLenBound(refp_self->d_private->d_capacity, refp_self->d_private->d_length, off2) ) {
		xc_err_term_unmg();
	}
	
	if(off1 <= off2 ) {
		calc_len=off2-off1+1;
	}
	else { /* (off1>off2) */
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strd_substrOffLen_alloc(refp_self, off1, calc_len, refp_result) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_strd_remOffLen(xc_strd_t* refp_self, const int off, const int len)
{
	int target_validated_len=0;
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(0!=xc_str_off_validLenBound(refp_self->d_private->d_capacity, refp_self->d_private->d_length, off) ) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_str_offLen_validLenBound(
			  refp_self->d_private->d_capacity
			, refp_self->d_private->d_length
			, off
			, len
			, &target_validated_len
		) 
	) {
		xc_err_term_unmg();
	}
	
	/* perform shift left of str byte sequence: */
	if(1)
	{
		xc_am_seq_cfg_t tmp_cfg={0};
		xc_am_seq_state_t tmp_state={0};
		
		tmp_cfg.cnt_items_in_chunk=1;
		tmp_cfg.item_bytesize=sizeof(xc_str_char_t);
		
		tmp_state.capacity=refp_self->d_private->d_capacity;
		tmp_state.length=refp_self->d_private->d_length;
		tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw( refp_self->d_private->d_buf );
		
		if( 0 != xc_am_seq_tStatic_shiftLeft(
				  &tmp_cfg
				, &tmp_state
				, off+target_validated_len
				, target_validated_len
			) 
		)
		{
			xc_err_term_unmg();
		}
	}
	/* perform shift left of str byte sequence: done */
	
	xc_strd_updateLen(refp_self);
	
	/* adjust capacity aftger change: */
	if(1)
	{
		if( 0 != xc_strd_realloc_alias_LL(refp_self, refp_self->d_private->d_length) ) {
			xc_err_term_unmg();
		}
	}
	/* adjust capacity aftger change: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
int xc_strd_remOffRange(xc_strd_t* refp_self, const int off1, const int off2)
{
	int calc_len=0;
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(0!=xc_str_off_validLenBound(refp_self->d_private->d_capacity, refp_self->d_private->d_length, off1) ) {
		xc_err_term_unmg();
	}
	if(0!=xc_str_off_validLenBound(refp_self->d_private->d_capacity, refp_self->d_private->d_length, off2) ) {
		xc_err_term_unmg();
	}

	if(off1 <= off2 ) {
		calc_len=off2-off1+1;
	}
	else { /* (off1>off2) */
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strd_remOffLen(refp_self, off1, calc_len) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

int xc_strd_findNext_off(const xc_strd_t* refp_self, xc_str_substrOffs_t* refp_result, const int off, const char* str_to_find)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == refp_result) {
		xc_err_term_unmg();
	}
	if(NULL == str_to_find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strd_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 != xc_str_off_validLenBound(refp_self->d_private->d_capacity, refp_self->d_private->d_length, off) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		uintptr_t tmp_start=(uintptr_t)refp_self->d_private->d_buf;
		const char* found_str=NULL;
		
		xc_mem_bzero_obj(xc_str_substrOffs_t, refp_result);
		
		if( NULL != (found_str=strstr(refp_self->d_private->d_buf, str_to_find) ) ) {
			uintptr_t tmp_off=0;
			uintptr_t tmp_diff=0;
			xc_si_uintptr_t_t tmp_uptr={0};
			xc_si_int_t tmp_i={0};
			
			tmp_off=(uintptr_t)found_str;
			tmp_diff=tmp_off-tmp_start;
			
			tmp_uptr=xc_si_uintptr_t_p(&tmp_diff);
			tmp_i=xc_si_int_from_uintptr_t(tmp_uptr);
			
			if( 0 != xc_si_isError(tmp_i) ) {
				refp_result->off=xc_si_val(tmp_i);
				refp_result->length=strlen(str_to_find);
				refp_result->overflow=0;
			}
		}
		else { /* manageable error */
			return 1;
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

int xc_strd_finds_deinit(xc_strd_finds_t* refp_result)
{
	xc_err_decl();
	
	if(NULL==refp_result) {
		xc_err_term_mg();
	}
	
	if(refp_result->entry_arrayLen!=0 && NULL!=refp_result->entry_array) {
		free(refp_result->entry_array);
	}
	
	xc_mem_bzero_obj(xc_strd_finds_t, refp_result);
	
	return 0;
	
	xc_err_on_mg();
	return 1;
}

int xc_strd_findAll_alloc(const xc_strd_t* refp_self, xc_strd_finds_t* refp_result, const char* str_to_find)
{
	xc_err_decl();
	
	/* contextless param validation: */
	if(1)
	{
		if(NULL == refp_self) {
			xc_err_term_unmg();
		}
		if(NULL == refp_result) {
			xc_err_term_unmg();
		}
		if(NULL == str_to_find) {
			xc_err_term_unmg();
		}
		if(0 == strlen(str_to_find) ) {
			xc_err_term_unmg();
		}
	}
	/* contextless param validation: done */
	/* --- */
	
	/* contextful param validation: */
	if(1)
	{
		if( 0 == xc_strd_isInit(refp_self) ) {
			xc_err_term_unmg();
		}
	}
	/* contextful param validation: done */
	
	/* --- */
	
	/* TODO: replace static allocation with growing xc_tcVector or sth, in order to avoid searching the string twice */
	if(1)
	{
		int find_counter=0;
		const char* tmp_src=refp_self->d_private->d_buf;
		const char* tmp=NULL;
		
		while( NULL != (tmp=strstr(tmp_src, str_to_find) ) ) 
		{
			find_counter++;
			tmp_src=tmp+1;
		}
		
		xc_mem_bzero_obj(xc_strd_finds_t, refp_result);
		
		if(0 == find_counter) {
			refp_result->entry_arrayLen=0;
		}
		else
		{
			int n=0;
			
			refp_result->entry_arrayLen=find_counter;
			refp_result->entry_array=xc_mem_allocz_obj_array(xc_str_substrOffs_t, find_counter);
			
			if( NULL == refp_result->entry_array ) {
				xc_err_term_unmg();
			}
			
			for(n=0; n<find_counter; n++)
			{
				int cur_off=0;
				xc_str_substrOffs_t* cur_offs=&refp_result->entry_array[n];
				
				if( 0 == xc_strd_findNext_off(refp_self, cur_offs, cur_off, str_to_find) )  {
					/* OK */
				}
				else { /* manageable error */
					/* this is paranoia */
					/* zero length of invalid entry */
					cur_offs->length=0;
				}
				
				cur_off=cur_offs->off+1;
			}
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

static int xc_strd_substSubstr_LL(xc_strd_t* refp_self, const xc_cstrRo_t str_replaced, const xc_cstrRo_t str_replacement)
{
	xc_strd_t tmp_strd={0};
	xc_strd_finds_t finds={0};
	xc_err_decl();
	
	/* contextless param validation: */
	if(1)
	{
		if(NULL == refp_self) {
			xc_err_term_unmg();
		}
		if(NULL == str_replaced.ro_buf) {
			xc_err_term_unmg();
		}
		if(str_replaced.ro_len<=0) {
			xc_err_term_unmg();
		}
		if(0 == strlen(str_replaced.ro_buf) ) { /* TODO redundant? */
			xc_err_term_unmg();
		}
		if(NULL == str_replacement.ro_buf) {
			xc_err_term_unmg();
		}
		if(str_replacement.ro_len<0) {
			xc_err_term_unmg();
		}
	}
	/* contextless param validation: done */

	/* contextful param validation: */
	if(1)
	{
		if( 0 == xc_strd_isInit(refp_self) ) {
			xc_err_term_unmg();
		}
	}
	/* contextful param validation: done */
	
	if(1)
	{
		if(0 != xc_strd_findAll_alloc(refp_self, &finds, str_replaced.ro_buf) )  {
			xc_err_term_unmg();
		}
		
		if( 0 != xc_strd_init(&tmp_strd) ) {
			xc_err_term_unmg();
		}
		
		if( 0 != finds.entry_arrayLen )
		{
			int n=0;
			int src_off=0;
			
			for(n=0; n< finds.entry_arrayLen; n++)
			{
				const xc_str_substrOffs_t* refp_offs=&finds.entry_array[n];
				xc_str_substrOffs_t tmp_offs={0};
				
				/* copy <current; cur substr occurence): */
				if(1)
				{
					tmp_offs.off=src_off;
					tmp_offs.length=refp_offs->off-tmp_offs.off+1;
					
					if( 0 != xc_strd_append_sub(&tmp_strd, refp_self,tmp_offs) ) {
						xc_err_term_unmg();
					}
				}
				/* copy <current; cur substr occurence): done */
				
				src_off+=tmp_offs.length;
				src_off+=refp_offs->length;
				
				/* replace: */
				if(1)
				{
					if( 0 != xc_strd_append_fmt(&tmp_strd, "%s", str_replacement.ro_buf) ) {
						xc_err_term_unmg();
					}
				}
				/* replace: done */
			}
			
			/* add substr between end of last occurence and end of string: */
			if(1)
			{
				xc_str_substrOffs_t tmp_offs={0};
				tmp_offs.off=src_off;
				tmp_offs.length=xc_str_npos;

				if( 0 != xc_strd_append_sub(&tmp_strd, refp_self, tmp_offs) ) {
					xc_err_term_unmg();
				}
			}
			/* add substr between end of last occurence and end of string: */
			
			if( 0 != xc_strd_set(refp_self, &tmp_strd) ) {
				xc_err_term_unmg();
			}
			
		}
		else {
			/* do nothing*/
		}
		
	}
	
	xc_strd_finds_deinit(&finds);
	xc_strd_deinit(&tmp_strd);
	
	return 0;
	
	xc_err_on_unmg();
	xc_strd_finds_deinit(&finds);
	xc_strd_deinit(&tmp_strd);
	return 1;
}
/*
 * [refp_self: must be not null, must be initialized];
 * [str_replaced: must be not null, must be not empty];
 * [str_replaced: must be not null];
 */
int xc_strd_replaceSubstr_cstr(xc_strd_t* refp_self, const char* str_replaced, const char* str_replacing)
{
	xc_cstrRo_t tmp_str_replaced={0};
	xc_cstrRo_t tmp_str_replacing={0};
	xc_err_decl();
	
	/* contextless param validation: */
	if(1)
	{
		if(NULL == refp_self) {
			xc_err_term_unmg();
		}
		if(NULL == str_replaced) {
			xc_err_term_unmg();
		}
		if(NULL == str_replacing) {
			xc_err_term_unmg();
		}
	}
	/* contextless param validation: done */
	/* --- */
	
	/* contextful param validation: */
	if(1)
	{
		if( 0 == xc_strd_isInit(refp_self) ) {
			xc_err_term_unmg();
		}
	}
	/* contextful param validation: done */
	
	if(1)
	{
		tmp_str_replaced=xc_cstrRo(str_replaced);
		tmp_str_replacing=xc_cstrRo(str_replacing);
		
		if(0 == tmp_str_replaced.ro_len) { /* [str_replaced: must be not null, must be not empty]; */
			xc_err_term_unmg();
		}
		
		if( 0 != xc_strd_substSubstr_LL(refp_self, tmp_str_replaced, tmp_str_replacing) ) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

/* --- --- --- --- */

int xc_strd_toUpper(xc_strd_t* refp_self)
{
	return 0;
}

int xc_strd_toLower(xc_strd_t* refp_self)
{
	return 0;
}

/* --- --- --- --- */

int xc_strd_appendLn(xc_strd_t* refp_self, const xc_strd_t* refp_str)
{
	return 0;
}

int xc_strd_appendLn_sub(xc_strd_t* refp_self, const xc_strd_t* refp_str, const xc_str_substrOffs_t range)
{
	return 0;
}

int xc_strd_appendLn_fmt(xc_strd_t* refp_self, const char* fmt, ...)
{
	return 0;
}

int xc_strd_appendLn_vfmt(xc_strd_t* refp_self, const char* fmt, va_list args)
{
	return 0;
}

/* --- --- --- --- */
