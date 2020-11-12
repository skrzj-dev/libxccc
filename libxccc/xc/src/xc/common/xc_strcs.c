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
#include <strings.h>
#include <stdarg.h>
/* --- */
#include "xc/common/xc_err.h"
#include "xc/common/xc_si.h"
#include "xc/common/xc_mem.h"
#include "xc/common/xc_initcheck.h"
#include "xc/common/xc_preprocessor.h"
#include "xc/common/xc_strc_ll.h"
/* --- */
#include "xc/common/xc_strcs.h"
/* --- */

#define xc_LEN_T int

#define xc_strcs_LL_INITCHECK_VAL (0x9870)

#define xc_strcs_DIAG_RETV_ERR_SAMEOBJ (-99)

#define xc_strcs_DIAG_RETV_OK_SAMEOBJ (-199)

#define xc_strcs_DIAG_RETV_TRUE_SAMEOBJ 1

#define xc_strcs_ISIMMUTABLE 1

static int xc_strcs_LL_isInvalid(const xc_strcs_t* refp_src);
static int xc_strcs_LL_initFrom(xc_strcs_t* refp_self, xc_strcRW_t* allocated, const size_t capacity);
static int xc_strcs_LL_isItself(const xc_strcs_t* refp_src1, const xc_strcs_t* refp_src2);

/*
 * xc_strcs_<public API>
 * xc_strc_LL_<public API> - low- level API meeting following requirements:
 *    - 1. operates on already construucted priimiitive sstructs
 *    - 2. is diisconnected from resource management (alloction, deallocation)
 * 
 */


static int xc_strcs_LL_isItself(const xc_strcs_t* refp_src1, const xc_strcs_t* refp_src2)
{
	if(NULL != refp_src1 && NULL != refp_src2)
	{
		if(refp_src1 == refp_src2) {
			return 1;
		}
		
		if( refp_src1->private_data.strcs_buf == refp_src2->private_data.strcs_buf ) {
			return 1;
		}
	}
	
	return 0;
}


static int xc_strcs_LL_isInvalid(const xc_strcs_t* refp_src)
{
	if(NULL == refp_src) {
		return 10;
	}
	
	if( NULL == refp_src->private_data.strcs_buf ) {
		return 20;
	}
	
	if( refp_src->private_data.strcs_capacity <= 0 ) {
		return 30;
	}
	
	if( refp_src->private_data.strcs_len < 0 ) {
		return 40;
	}
	
	if( 0 == xc_initc_anyscopeNZ_isValid_u(&refp_src->private_data.initcheck, xc_strcs_LL_INITCHECK_VAL) ) {
		return 50;
	}
	
	
	return 0;
}

int xc_strcs_isInit(const xc_strcs_t* refp_src)
{
	if(NULL == refp_src) {
		return 0;
	}
	
	if( 0 != xc_strcs_LL_isInvalid(refp_src) ) {
		return 0;
	}
	
	return 1;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */

static int xc_strcs_LL_initFrom(xc_strcs_t* refp_self, xc_strcRW_t* allocated, const size_t capacity)
{
	xc_err_decl();
	/* --- */
	
	if( capacity == 0 ) {
		xc_err_term_unmg();
	}

	if( allocated->rw_len < 0 ) {
		xc_err_term_unmg();
	}

	if( xc_si_UNCHECKED_INT2UINT( (size_t)allocated->rw_len ) > capacity ) {
		xc_err_term_unmg();
	}
	
	if( NULL == allocated->rw_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* alloc buffer and copy string: */
	if(1)
	{
		/* FINALZATION: */
		/* when everything is succesful: deinit self (if required), zero object bytes, assign new data */
		if(1)
		{
			if( 0 != xc_strcs_isInit(refp_self) ) {
				xc_strcs_deinit(refp_self);
			}
			
			xc_mem_bzero_obj(xc_strcs_t, refp_self);
			xc_initc_anyscopeNZ_init_c(&refp_self->private_data.initcheck, xc_strcs_LL_INITCHECK_VAL);
			
			refp_self->private_data.strcs_buf = allocated->rw_buf;
			refp_self->private_data.strcs_capacity = capacity;
			refp_self->private_data.strcs_len = allocated->rw_len;
			
			if(1)
			{
				xc_hash_inputBytes_t tmp_hash_input=xc_hash_inputBytes(allocated->rw_len, (unsigned char*)allocated->rw_buf);
				xc_hash_x65599_32(tmp_hash_input, &refp_self->private_data.hash32);
			}
			
		}
		/* FINALZIATION: done */
	}
	/* alloc buffer and copy string: done */
	return 0;
	
	xc_err_termpt_unmg();
	return 1;
}


int xc_strcs_from_init(xc_strcs_t* refp_self, const xc_strcs_t* refp_src)
{
	size_t capacity=0;
	xc_strcRW_t tmpRW={0};
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == refp_src) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		if(xc_strcs_ISIMMUTABLE)
		{
			if( 0 != xc_strcs_isInit(refp_self) ) {
				xc_err_term_unmg();
			}
		}
	}
	
	if( 0 == xc_strcs_isInit(refp_src) ) {
		xc_err_term_unmg();
	}
	
	/* shortcut against self x self: */
	if(1)
	{
		if(refp_self == refp_src) {
			return xc_strcs_DIAG_RETV_ERR_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */
	
	if( 0 != xc_strc_allocEmpty_fixedSize(refp_src->private_data.strcs_len, &tmpRW, &capacity) ) {
		xc_err_term_unmg();
	}
	
	xc_mem_cp_obj_array(char, refp_src->private_data.strcs_len, tmpRW.rw_buf, refp_src->private_data.strcs_buf);
	
	if( 0 != xc_strcs_LL_initFrom(
			  refp_self
			, &tmpRW
			, capacity
		) 
	) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_termpt_unmg();
	return 1;
}


int xc_strcs_fromVfmt_init(xc_strcs_t* refp_self, const char* fmt, va_list arg_va)
{
	xc_strcRW_t tmpRW={0};
	size_t capacity=0;
	int snprintf_retv=0;
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		if(xc_strcs_ISIMMUTABLE)
		{
			if( 0 != xc_strcs_isInit(refp_self) ) {
				xc_err_term_unmg();
			}
		}
	}
	
	/* shortcut against self x self: */
	if(1)
	{
		if(refp_self->private_data.strcs_buf == fmt) {
			return xc_strcs_DIAG_RETV_ERR_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */
	
	snprintf_retv=vsnprintf(NULL, 0, fmt, arg_va);
	
	if( snprintf_retv < 0 ) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strc_allocEmpty_fixedSize(snprintf_retv, &tmpRW, &capacity) ) {
		xc_err_term_unmg();
	}

	vsnprintf(tmpRW.rw_buf, capacity-1, fmt, arg_va);
	
	if( 0 != xc_strcs_LL_initFrom(
			  refp_self
			, &tmpRW
			, capacity
		) 
	) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_termpt_unmg();
	return 1;
}

int xc_strcs_fromFmt_init(xc_strcs_t* refp_self, const char* fmt, ...)
{
	int done_ok=0;
	va_list arglist;
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		if(xc_strcs_ISIMMUTABLE)
		{
			if( 0 != xc_strcs_isInit(refp_self) ) {
				xc_err_term_unmg();
			}
		}
	}
	
	/* shortcut against self x self: */
	if(1)
	{
		if(refp_self->private_data.strcs_buf == fmt) {
			return xc_strcs_DIAG_RETV_ERR_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */
	
	va_start(arglist, fmt);
	if(1)
	{
		if( 0 != xc_strcs_fromVfmt_init(refp_self, fmt, arglist) ) {
			xc_err_term_unmg();
		}
		done_ok=1;
	}
	va_end(arglist);
	
	return 0;
	
	xc_err_termpt_unmg();
	if(0!=done_ok) {
		va_end(arglist);
	}
	return 1;
}


int xc_strcs_fromCstr_init(xc_strcs_t* refp_self, const char* src_str)
{
	size_t strlen_value=0;
	size_t capacity_value=0;
	xc_strcRW_t tmpRW={0};
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == src_str) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		if(xc_strcs_ISIMMUTABLE)
		{
			if( 0 != xc_strcs_isInit(refp_self) ) {
				xc_err_term_unmg();
			}
		}
	}
	
	/* shortcut against self x self: */
	if(1)
	{
		if(refp_self->private_data.strcs_buf == src_str) {
			return xc_strcs_DIAG_RETV_ERR_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */
	
	strlen_value=strlen(src_str);
	
	if( 0 != xc_strc_allocEmpty_fixedSize(strlen_value, &tmpRW, &capacity_value) ) {
		xc_err_term_unmg();
	}
	
	strncpy(tmpRW.rw_buf, src_str, xc_si_UNCHECKED_INT2UINT(strlen_value) );
	
	if( 0 != xc_strcs_LL_initFrom(
			  refp_self
			, &tmpRW
			, capacity_value
		) 
	) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_termpt_unmg();
	return 1;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */

int xc_strcs_eq(const xc_strcs_t* refp_self, const xc_strcs_t* refp_target)
{
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == refp_target) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_target) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* shortcut against self x self: */
	if(1)
	{
		if(refp_self == refp_target) {
			return xc_strcs_DIAG_RETV_TRUE_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */

	/* hash shortcut: */
	if(1)
	{
		if(refp_self->private_data.hash32.v.val != refp_target->private_data.hash32.v.val) {
			return 0;
		}
	}
	/* hash shortcut: done */
	
	if(1)
	{
		xc_strcRO_t str_self={0};
		xc_strcRO_t str_other={0};
		
		str_self.ro_buf=refp_self->private_data.strcs_buf;
		str_self.ro_len=refp_self->private_data.strcs_len;

		str_other.ro_buf=refp_target->private_data.strcs_buf;
		str_other.ro_len=refp_target->private_data.strcs_len;
		
		return xc_strc_LL_eq(&str_self, &str_other);
	}

	xc_err_termpt_unmg();
	return 0;
}

int xc_strcs_eq_cstr(const xc_strcs_t* refp_self, const char* refp_target_str)
{
	size_t strlen_bin=0;
	xc_si_int_t strlen_int={0};
	xc_err_decl();
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == refp_target_str) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* shortcut against self x self: */
	if(1)
	{
		if(refp_self->private_data.strcs_buf == refp_target_str) {
			return xc_strcs_DIAG_RETV_TRUE_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */
	
	strlen_bin=strlen(refp_target_str);
	strlen_int=xc_si_int_from_size_t_p(&strlen_bin);
	
	if( 0 != xc_si_isError(strlen_int) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		xc_strcRO_t str_self={0};
		xc_strcRO_t str_other={0};
		
		str_self.ro_buf=refp_self->private_data.strcs_buf;
		str_self.ro_len=refp_self->private_data.strcs_len;
		
		str_other.ro_buf=refp_target_str;
		str_other.ro_len=xc_si_val(strlen_int);
		
		return xc_strc_LL_eq(&str_self, &str_other);
	}
	
	xc_err_termpt_unmg();
	return 0;
}


/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */

int xc_strcs_eqNC(const xc_strcs_t* refp_self, const xc_strcs_t* refp_target)
{
	xc_strcRO_t obj1={0};
	xc_strcRO_t obj2={0};
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == refp_target) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_target) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* shortcut against self x self: */
	if(1)
	{
		if(refp_self == refp_target) {
			return xc_strcs_DIAG_RETV_TRUE_SAMEOBJ;
		}
		if(refp_self->private_data.strcs_buf == refp_target->private_data.strcs_buf) {
			return xc_strcs_DIAG_RETV_TRUE_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */
	
	/* hash shortcut: */
	if(1)
	{
		/* n/a */
	}
	/* hash shortcut: done */
	
	obj1.ro_buf=refp_self->private_data.strcs_buf;
	obj1.ro_len=refp_self->private_data.strcs_len;
	
	obj2.ro_buf=refp_target->private_data.strcs_buf;
	obj2.ro_len=refp_target->private_data.strcs_len;
	
	return xc_strc_LL_eqNC(&obj1, &obj2);
	
	xc_err_termpt_unmg();
	return 0;
}

int xc_strcs_eqNC_cstr(const xc_strcs_t* refp_self, const char* cstr_src)
{
	xc_strcRO_t obj1={0};
	xc_strcRO_t obj2={0};
	xc_si_int_t strlen_int={0};
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == cstr_src) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* shortcut against self x self: */
	if(1)
	{
		if(refp_self->private_data.strcs_buf == cstr_src) {
			return xc_strcs_DIAG_RETV_TRUE_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */
	
	/* hash shortcut: */
	if(1)
	{
		/* n/a */
	}
	/* hash shortcut: done */

	if(1)
	{
		size_t strlen_bin=0;
		
		strlen_bin=strlen(cstr_src);
		strlen_int=xc_si_int_from_size_t_p(&strlen_bin);
		
		if( 0 != xc_si_isError(strlen_int) ) {
			xc_err_term_unmg();
		}
	}
	
	obj1.ro_buf=refp_self->private_data.strcs_buf;
	obj1.ro_len=refp_self->private_data.strcs_len;
	
	obj2.ro_buf=cstr_src;
	obj2.ro_len=xc_si_val(strlen_int);
	
	return xc_strc_LL_eqNC(&obj1, &obj2);
	
	xc_err_termpt_unmg();
	return 0;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */


int xc_strcs_deinit(xc_strcs_t* refp_self)
{
	int invalid_err=0;
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != ( invalid_err = xc_strcs_LL_isInvalid(refp_self) ) ) {
		xc_mem_u_bzero_obj(xc_strcs_t, refp_self);
		return 2;
	}
	/* --- */
	
	xc_mem_u_bzero_bytes(refp_self->private_data.strcs_capacity, refp_self->private_data.strcs_buf);
	free(refp_self->private_data.strcs_buf);
	
	xc_mem_u_bzero_obj(xc_strcs_t, refp_self);
	
	return 0;
	
	xc_err_termpt_unmg();
	return 1;
}


int xc_strcs_get_length(const xc_strcs_t* refp_self)
{
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	return refp_self->private_data.strcs_len;
	
	xc_err_termpt_unmg();
	return 0;
}

size_t xc_strcs_get_capacity(const xc_strcs_t* refp_self)
{
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	return refp_self->private_data.strcs_capacity;
	
	xc_err_termpt_unmg();
	return 0;
}

const char* xc_strcs_get_cstr(const xc_strcs_t* refp_self)
{
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	return refp_self->private_data.strcs_buf;
	
	xc_err_termpt_unmg();
	return NULL;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */

xc_strcsa_t* xc_strcs_from_alloc(const xc_strcs_t* refp_src)
{
	xc_strcsa_t* retv=NULL;
	xc_err_decl();
	
	if(NULL==refp_src) {
		xc_err_term_unmg();
	}
	
	if(NULL == ( retv=xc_mem_allocz_obj(xc_strcsa_t) ) ) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strcs_from_init(&retv->obj, refp_src) ) {
		xc_err_term_unmg();
	}
	
	return retv;
	
	xc_err_termpt_unmg();
	if(NULL != retv) {
		xc_strcs_dealloc(retv);
	}
	return NULL;
}

xc_strcsa_t* xc_strcs_fromFmt_alloc(const char* fmt, ...)
{
	int done_ok=0;
	va_list arglist;
	xc_strcsa_t* retv=NULL;
	xc_err_decl();
	/* --- */
	
	if(NULL == fmt) {
		xc_err_term_unmg();
	}
	/* --- */
	
	va_start(arglist, fmt);
	if(1)
	{
		if(NULL == ( retv=xc_mem_allocz_obj(xc_strcsa_t) ) ) {
			xc_err_term_unmg();
		}
		
		if( 0 != xc_strcs_fromVfmt_init(&retv->obj, fmt, arglist) ) {
			xc_err_term_unmg();
		}
		
		done_ok=1;
	}
	va_end(arglist);
	
	return 0;
	
	xc_err_termpt_unmg();
	if(0!=done_ok) {
		va_end(arglist);
	}
	if(NULL != retv) {
		xc_strcs_dealloc(retv);
	}
	return NULL;
}

xc_strcsa_t* xc_strcs_fromCstr_alloc(const char* cstr)
{
	xc_strcsa_t* retv=NULL;
	xc_err_decl();
	
	if(NULL==cstr) {
		xc_err_term_unmg();
	}
	
	if(NULL == ( retv=xc_mem_allocz_obj(xc_strcsa_t) ) ) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strcs_fromCstr_init(&retv->obj, cstr) ) {
		xc_err_term_unmg();
	}
	
	return retv;
	
	xc_err_termpt_unmg();
	if(NULL != retv) {
		xc_strcs_dealloc(retv);
	}
	return NULL;
}

int xc_strcs_dealloc(xc_strcsa_t* refp_self)
{
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	
	xc_strcs_deinit(&refp_self->obj);
	
	xc_mem_free_obj(xc_strcsa_t, refp_self);
	
	return 0;
	
	xc_err_termpt_unmg();
	return 1;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */

int xc_strcs_ifContains_cstr(const xc_strcs_t* refp_self, const char* cstr_str2find)
{
	xc_strcRO_t self={0};
	xc_strcRO_t str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==cstr_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	
	self.ro_buf=refp_self->private_data.strcs_buf;
	self.ro_len=refp_self->private_data.strcs_len;

	str2find.ro_buf=cstr_str2find;
	if( 0 != xc_pre_IS_STR_EMPTY(cstr_str2find) ) {
		str2find.ro_len=0;
	}
	else {
		str2find.ro_len=strlen(cstr_str2find);
	}
	
	return xc_strcs_LL_ifContains(&self, &str2find);
	
	xc_err_termpt_unmg();
	return 0;
}

int xc_strcs_ifContains(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find)
{
	xc_strcRO_t self={0};
	xc_strcRO_t str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_str2find) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	self.ro_buf=refp_self->private_data.strcs_buf;
	self.ro_len=refp_self->private_data.strcs_len;

	str2find.ro_buf=refp_str2find->private_data.strcs_buf;
	str2find.ro_len=refp_str2find->private_data.strcs_len;
	
	return xc_strcs_LL_ifContains(&self, &str2find);
	
	xc_err_termpt_unmg();
	return 0;
}

int xc_strcs_ifContainsNC_cstr(const xc_strcs_t* refp_self, const char* cstr_str2find)
{
	xc_strcRO_t self={0};
	xc_strcRO_t str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==cstr_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	
	self.ro_buf=refp_self->private_data.strcs_buf;
	self.ro_len=refp_self->private_data.strcs_len;

	str2find.ro_buf=cstr_str2find;
	if( 0 != xc_pre_IS_STR_EMPTY(cstr_str2find) ) {
		str2find.ro_len=0;
	}
	else {
		str2find.ro_len=strlen(cstr_str2find);
	}
	
	return xc_strcs_LL_ifContainsNC(&self, &str2find);
	
	xc_err_termpt_unmg();
	return 0;
}

int xc_strcs_ifContainsNC(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find)
{
	xc_strcRO_t self={0};
	xc_strcRO_t str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_str2find) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	self.ro_buf=refp_self->private_data.strcs_buf;
	self.ro_len=refp_self->private_data.strcs_len;

	str2find.ro_buf=refp_str2find->private_data.strcs_buf;
	str2find.ro_len=refp_str2find->private_data.strcs_len;
	
	return xc_strcs_LL_ifContainsNC(&self, &str2find);
	
	xc_err_termpt_unmg();
	return 0;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */

int xc_strcs_ifStartsWith(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find)
{
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_str2find) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, refp_str2find->private_data.strcs_len, refp_str2find->private_data.strcs_buf);
	
	return xc_strcs_LL_ifStartsWith(&tmp_self, &tmp_str2find);
	
	xc_err_termpt_unmg();
	return 0;
}

int xc_strcs_ifStartsWithNC(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find)
{
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_str2find) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, refp_str2find->private_data.strcs_len, refp_str2find->private_data.strcs_buf);
	
	return xc_strcs_LL_ifStartsWithNC(&tmp_self, &tmp_str2find);
	
	xc_err_termpt_unmg();
	return 0;
}

int xc_strcs_ifStartsWith_cstr(const xc_strcs_t* refp_self, const char* str2find)
{
	int tmplen=0;
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	tmplen=strlen(str2find);
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, tmplen, str2find);
	
	return xc_strcs_LL_ifStartsWith(&tmp_self, &tmp_str2find);
	
	xc_err_termpt_unmg();
	return 0;
}


int xc_strcs_ifStartsWithNC_cstr(const xc_strcs_t* refp_self, const char* str2find)
{
	int tmplen=0;
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	tmplen=strlen(str2find);
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, tmplen, str2find);
	
	return xc_strcs_LL_ifStartsWithNC(&tmp_self, &tmp_str2find);
	
	xc_err_termpt_unmg();
	return 0;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */


int xc_strcs_ifEndsWith(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find)
{
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_str2find) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, refp_str2find->private_data.strcs_len, refp_str2find->private_data.strcs_buf);
	
	return xc_strcs_LL_ifEndsWith(&tmp_self, &tmp_str2find);
	
	xc_err_termpt_unmg();
	return 0;
}


int xc_strcs_ifEndsWithNC(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find)
{
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_str2find) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, refp_str2find->private_data.strcs_len, refp_str2find->private_data.strcs_buf);
	
	return xc_strcs_LL_ifEndsWithNC(&tmp_self, &tmp_str2find);
	
	xc_err_termpt_unmg();
	return 0;
}


int xc_strcs_ifEndsWith_cstr(const xc_strcs_t* refp_self, const char* str2find)
{
	int tmplen=0;
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	tmplen=strlen(str2find);
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, tmplen, str2find);
	
	return xc_strcs_LL_ifEndsWith(&tmp_self, &tmp_str2find);
	
	xc_err_termpt_unmg();
	return 0;
}


int xc_strcs_ifEndsWithNC_cstr(const xc_strcs_t* refp_self, const char* str2find)
{
	int tmplen=0;
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	tmplen=strlen(str2find);
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, tmplen, str2find);
	
	return xc_strcs_LL_ifEndsWithNC(&tmp_self, &tmp_str2find);
	
	xc_err_termpt_unmg();
	return 0;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */


int xc_strcs_findNext(const xc_strcs_t* refp_self, const int start_off, const xc_strcs_t* refp_str2find, xc_strc_subStrInfo_t* refp_result)
{
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_str2find) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, refp_str2find->private_data.strcs_len, refp_str2find->private_data.strcs_buf);
	
	return xc_strcs_LL_findNext(&tmp_self, start_off, &tmp_str2find, refp_result);
	
	xc_err_termpt_unmg();
		if(NULL!=refp_result)  {
			refp_result->len=-1;
			refp_result->off=-1;
		}
	return -1;
}


int xc_strcs_findNextNC(const xc_strcs_t* refp_self, const int start_off, const xc_strcs_t* refp_str2find, xc_strc_subStrInfo_t* refp_result)
{
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strcs_isInit(refp_str2find) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, refp_str2find->private_data.strcs_len, refp_str2find->private_data.strcs_buf);
	
	return xc_strcs_LL_findNextNC(&tmp_self, start_off, &tmp_str2find, refp_result);
	
	xc_err_termpt_unmg();
		if(NULL!=refp_result)  {
			refp_result->len=-1;
			refp_result->off=-1;
		}
	return -1;
}


int xc_strcs_findNext_cstr(const xc_strcs_t* refp_self, const int start_off, const char* cstr2find, xc_strc_subStrInfo_t* refp_result)
{
	int tmplen=0;
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==cstr2find) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	tmplen=strlen(cstr2find);
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, tmplen, cstr2find);
	
	return xc_strcs_LL_findNext(&tmp_self, start_off, &tmp_str2find, refp_result);
	
	xc_err_termpt_unmg();
		if(NULL!=refp_result)  {
			refp_result->len=-1;
			refp_result->off=-1;
		}
	return -1;
}


int xc_strcs_findNextNC_cstr(const xc_strcs_t* refp_self, const int start_off, const char* cstr2find, xc_strc_subStrInfo_t* refp_result)
{
	int tmplen=0;
	xc_strcRO_t tmp_self={0};
	xc_strcRO_t tmp_str2find={0};
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==cstr2find) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 == xc_strcs_isInit(refp_self) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	tmplen=strlen(cstr2find);
	
	xc_strcRO_LL_SET(&tmp_self, refp_self->private_data.strcs_len, refp_self->private_data.strcs_buf);
	xc_strcRO_LL_SET(&tmp_str2find, tmplen, cstr2find);
	
	return xc_strcs_LL_findNextNC(&tmp_self, start_off, &tmp_str2find, refp_result);
	
	xc_err_termpt_unmg();
		if(NULL!=refp_result)  {
			refp_result->len=-1;
			refp_result->off=-1;
		}
	return -1;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */


int xc_strcs_substr_init(const xc_strcs_t* refp_self, const xc_strc_subStrInfo_t* refp_info, xc_strcs_t* refp_result)
{
	size_t capacity=0;
	xc_strcRO_t tmpRO={0};
	xc_strcRW_t tmpRW={0};
	xc_err_decl();
	/* --- */
	
	if(NULL == refp_self) {
		xc_err_term_unmg();
	}
	if(NULL == refp_result) {
		xc_err_term_unmg();
	}
	if(NULL == refp_info) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		if(xc_strcs_ISIMMUTABLE)
		{
			if( 0 != xc_strcs_isInit(refp_result) ) {
				xc_err_term_unmg();
			}
		}
	}
	/* --- */

	
	/* shortcut against self x self: */
	if(1)
	{
		if( 0 == xc_strcs_isInit(refp_self) ) {
			xc_err_term_unmg();
		}
		
		if(refp_self == refp_result) {
			return xc_strcs_DIAG_RETV_ERR_SAMEOBJ;
		}
		
		if( 0 != xc_strcs_LL_isItself(refp_self, refp_result) ) {
			return xc_strcs_DIAG_RETV_ERR_SAMEOBJ;
		}
	}
	/* shortcut against self x self: done */
	
	xc_strcRO_LL_SET(
		  &tmpRO
		, refp_self->private_data.strcs_len
		, refp_self->private_data.strcs_buf
	);
	
	if( 0 != xc_strcs_LL_init_substr(&tmpRO, refp_info, &tmpRW, &capacity) ) { 
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strcs_LL_initFrom(refp_result, &tmpRW, capacity) ) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_termpt_unmg();
	return 1;
}

/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */

int xc_strcs_LL_DIAG_verifyIntegrity(const xc_strcs_t* refp_target)
{
	int tmplen=0;
	size_t tmpcap=0;
	const char* tmpcstr=NULL;
	xc_hash_val32_t tmphash={0};
	xc_err_decl();
	
	if(NULL==refp_target) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strcs_LL_isInvalid(refp_target) ) {
		return 10;
	}
	
	tmplen=xc_strcs_get_length(refp_target);
	tmpcap=xc_strcs_get_capacity(refp_target);
	tmpcstr=xc_strcs_get_cstr(refp_target);
	
	if( (size_t)tmplen >= tmpcap ) {
		return 11;
	}

	if(1) {
		xc_hash_inputBytes_t tmp_hash_input=xc_hash_inputBytes(tmplen, (unsigned char*)tmpcstr);
		xc_hash_x65599_32(tmp_hash_input, &tmphash);
	}
	
	if(tmplen != refp_target->private_data.strcs_len) {
		return 100;
	}

	if(tmpcap != refp_target->private_data.strcs_capacity) {
		return 200;
	}

	if(tmpcstr != refp_target->private_data.strcs_buf) {
		return 300;
	}
	
	if( tmphash.v.val != refp_target->private_data.hash32.v.val) {
		return 9400;
	}
	
	if( (size_t)tmplen != tmpcap-2 ) {
		return 1200;
	}
	if( xc_strc_LL_termC != tmpcstr[tmpcap-1] ) {
		return 1400;
	}
	if( 0x0 != tmpcstr[tmpcap-2] ) { 
		return 1410;
	}
	
	return 0;
	
	xc_err_termpt_unmg();
	return -1;
}


/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */
/* ---- ---- ---- ---- */

#undef xc_strcs_ISIMMUTABLE
