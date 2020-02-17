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

#include <stddef.h>
#include <limits.h>
#include <stdint.h>
/* --- */
#include "xc/common/xc_err.h"
#include "xc/common/xc_si.h"
/* --- */

xc_si_int_t xc_si_int_v(const int val)
{
	xc_si_int_t retv={0};
	
	retv._private_val=val;
	retv._private_err=xc_si_retv_ok;
	
	return retv;
}


xc_si_int_t xc_si_int_p(const int* val)
{
	xc_si_int_t retv={0};
	
	if(NULL != val) {
		retv._private_val=*val;
		retv._private_err=xc_si_retv_ok;
	}
	else {
		retv._private_val=0;;
		retv._private_err=xc_si_retv_nullParam;
	}
	
	return retv;
}


xc_si_int_t xc_si_int(const xc_si_int_t val)
{
	xc_si_int_t retv={0};
	
	retv=val;
	
	return retv;
}


xc_si_int_t xc_si_int_add(const xc_si_int_t param_lval, const xc_si_int_t param_rval)
{
	xc_si_int_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(param_lval) ) {
		retv._private_err=param_lval._private_err;
		return retv;
	}
	if( 0 != xc_si_isError(param_rval) ) {
		retv._private_err=param_rval._private_err;
		return retv;
	}
	/* --- */
	
	retv=param_lval;
	
	if(1)
	{
		if( xc_si_int_val(param_rval) >= 0 )
		{
			if( xc_si_int_val(param_lval) > INT_MAX - xc_si_int_val(param_rval) ) {
				retv._private_err=xc_si_retv_overflow;
			}
		}
		else
		{
			if( xc_si_int_val(param_lval) < INT_MIN - xc_si_int_val(param_rval) ) {
				retv._private_err=xc_si_retv_underflow;
			}
		}
	}
	/*  --- */
	
	if( xc_si_retv_ok == xc_si_isError(retv) ) {
		retv._private_val+=xc_si_int_val(param_rval);
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}


xc_si_int_t xc_si_int_sub(const xc_si_int_t param_lval, const xc_si_int_t param_rval)
{
	xc_si_int_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(param_lval) ) {
		retv._private_err=param_lval._private_err;
		return retv;
	}
	if( 0 != xc_si_isError(param_rval) ) {
		retv._private_err=param_rval._private_err;
		return retv;
	}
	/* --- */
	
	retv=param_lval;
	
	if(1)
	{
		if( xc_si_int_val(param_rval) >= 0 )
		{
			if( xc_si_int_val(param_lval) < INT_MIN + xc_si_int_val(param_rval) ) {
				retv._private_err=xc_si_retv_underflow;
			}
		}
		else
		{
			if( xc_si_int_val(param_lval) > INT_MAX + xc_si_int_val(param_rval) ) {
				retv._private_err=xc_si_retv_overflow;
			}
		}
	}
	/* --- */
	
	if(xc_si_retv_ok == xc_si_isError(retv) ) {
		retv._private_val-=xc_si_int_val(param_rval);
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}


xc_si_int_t xc_si_int_div(const xc_si_int_t param_lval, const xc_si_int_t param_rval)
{
	xc_si_int_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(param_lval) ) {
		retv._private_err=param_lval._private_err;
		return retv;
	}
	if( 0 != xc_si_isError(param_rval) ) {
		retv._private_err=param_rval._private_err;
		return retv;
	}
	/* --- */
	
	retv=param_lval;
	
	if(1)
	{
		if( 0 == xc_si_int_val(param_rval) )
		{
			retv._private_err=xc_si_retv_divByZero;
		}
	}
	/* --- */
	
	if(xc_si_retv_ok == xc_si_isError(retv) ) {
		retv._private_val/=xc_si_int_val(param_rval);
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}


xc_si_int_t xc_si_int_mul(const xc_si_int_t param_lval, const xc_si_int_t param_rval)
{
	xc_si_int_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(param_lval) ) {
		retv._private_err=param_lval._private_err;
		return retv;
	}
	if( 0 != xc_si_isError(param_rval) ) {
		retv._private_err=param_rval._private_err;
		return retv;
	}
	/* --- */
	
	retv=param_lval;
	
	if(1)
	{
		if( xc_si_int_val(param_rval) != 0 )
		{
			if( xc_si_int_val(param_rval) > 0 )
			{
				if( xc_si_int_val(param_lval) > ( INT_MAX / xc_si_int_val(param_rval) ) ) {
					retv._private_err=xc_si_retv_overflow;
				}

				if( xc_si_int_val(param_lval) < ( INT_MIN / xc_si_int_val(param_rval) ) ) {
					retv._private_err=xc_si_retv_underflow;
				}
			}
			else
			{
				if( xc_si_int_val(param_lval) < ( INT_MAX / xc_si_int_val(param_rval) ) ) {
					retv._private_err=xc_si_retv_overflow;
				}

				if( xc_si_int_val(param_lval) > ( INT_MIN / xc_si_int_val(param_rval) ) ) {
					retv._private_err=xc_si_retv_underflow;
				}
			}
		}
		else {
			/* OK, X*0 is valid */
		}
	}
	/* --- */
	
	if(xc_si_retv_ok == xc_si_isError(retv) ) {
		retv._private_val*=xc_si_int_val(param_rval);
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}


xc_si_uint_t xc_si_uint_from_int(const xc_si_int_t target_val)
{
	xc_si_uint_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(target_val) ) {
		retv._private_err=target_val._private_err;
		return retv;
	}
	/* --- */
	
	if(1)
	{
		if( xc_si_int_val(target_val) < 0 ) {
			retv._private_err=xc_si_retv_underflow;
		}
	}
	/* --- */
	
	if( 0 == xc_si_isError(retv) ) {
		retv._private_val=target_val._private_val;
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}


xc_si_int_t xc_si_int_from_uint(const xc_si_uint_t target_val)
{
	xc_si_int_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(retv) ) {
		retv._private_err=target_val._private_err;
		return retv;
	}
	/* --- */
	
	if(1)
	{
		if( xc_si_uint_val(target_val) > (unsigned int)(INT_MAX) ) {
			retv._private_err=xc_si_retv_overflow;
		}
		
		if( xc_si_uint_val(target_val) < (unsigned int)(INT_MIN) ) {
			retv._private_err=xc_si_retv_underflow;
		}
	}
	/* --- */
	
	if( 0 == xc_si_isError(retv) ) {
		retv._private_val=target_val._private_val;
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}

xc_si_size_t_t xc_si_size_t_from_int(const xc_si_int_t target_val)
{
	xc_si_size_t_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(retv) ) {
		retv._private_err=target_val._private_err;
		return retv;
	}
	/* --- */
	
	if(1)
	{
		if( xc_si_int_val(target_val) < 0 )
		{
			retv._private_err=xc_si_retv_underflow;
		}
	}
	/* --- */
	
	if( 0 == xc_si_isError(retv) ) {
		retv._private_val=target_val._private_val;
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}


xc_si_int_t xc_si_int_from_size_t(const xc_si_size_t_t target_val)
{
	xc_si_int_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(retv) ) {
		retv._private_err=target_val._private_err;
		return retv;
	}
	/* --- */
	
	if(1)
	{
		if( xc_si_size_t_val(target_val) > (size_t)(INT_MAX) ) {
			retv._private_err=xc_si_retv_overflow;
		}
		
		if( xc_si_size_t_val(target_val) < (size_t)(INT_MIN) ) {
			retv._private_err=xc_si_retv_underflow;
		}
	}
	/* --- */
	
	if( 0 == xc_si_isError(retv) ) {
		retv._private_val=target_val._private_val;
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}

xc_si_int_t xc_si_int_from_uintptr_t(const xc_si_uintptr_t_t target_val)
{
	xc_si_int_t retv={0};
	/* --- */
	
	if( 0 != xc_si_isError(retv) ) {
		retv._private_err=target_val._private_err;
		return retv;
	}
	/* --- */
	
	if(1)
	{
		if( xc_si_size_t_val(target_val) > (uintptr_t)(INT_MAX) ) {
			retv._private_err=xc_si_retv_overflow;
		}
		
		/* no check for MIN due to unsigned param */
	}
	/* --- */
	
	if( 0 == xc_si_isError(retv) ) {
		retv._private_val=target_val._private_val;
	}
	else {
		retv._private_val=0;
	}
	
	return retv;
}

/* --- --- --- --- */

xc_si_uintptr_t_t xc_si_uintptr_t_v(const uintptr_t param)
{
	xc_si_uintptr_t_t retv={0};
	
	retv._private_val=param;
	
	return retv;
}

xc_si_uintptr_t_t xc_si_uintptr_t_p(const uintptr_t* param)
{
	xc_si_uintptr_t_t retv={0};
	
	if(NULL!=param) {
		retv._private_val=*param;
		retv._private_val=xc_si_retv_ok;
	}
	else {
		retv._private_val=0;
		retv._private_val=xc_si_retv_nullParam;
	}
	
	return retv;
}

#if 0
int xc_int0_cnv_int_to_size_t(const int* refp_input_val, size_t* refp_result)
{
	int tmp_input_val=0;
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_input_val) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	tmp_input_val=*refp_input_val;
	
	if( tmp_input_val>=0 && (size_t)tmp_input_val<=SIZE_MAX ) {
		*refp_result=(size_t)tmp_input_val;
	}
	else {
		*refp_result=0;
		return -1;
	}
	
	return 0;
	
	xc_err_handle_unmg();
	return 1;
}

size_t xc_int0_cnv_int_to_size_t_retv(const int* refp_input_val, int* result_err)
{
	size_t retv=0;
	int tmp_input_val=0;
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_input_val) {
		xc_err_term_unmg();
	}
	if(NULL==result_err) {
		xc_err_term_unmg();
	}
	/* --- */
	
	tmp_input_val=*refp_input_val;
	
	if( tmp_input_val>=0 && (size_t)tmp_input_val<=SIZE_MAX ) {
		retv=(size_t)tmp_input_val;
		*result_err=0;
	}
	else {
		retv=0;
		*result_err=1;
		return -1;
	}
	
	return retv;
	
	xc_err_handle_unmg();
	if(NULL!=result_err)  {
		*result_err=1;
	}
	return 0;
}
#endif
