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

#include "xc/common/xc_err.h"

typedef struct xc_err_globalData
{ 
	void (*refp_fn_signalize)(const xc_err_scopeInfo_t* refp_err_info);
} xc_err_globalData;

/* --- */

static void xc_errLL_sig_default(const xc_err_scopeInfo_t* refp_err_info);

/* --- */

xc_err_globalData xc_err_globalData_obj={ xc_errLL_sig_default };

/* --- */

static void xc_errLL_sig_default(const xc_err_scopeInfo_t* refp_err_info)
{
	
	if(NULL==refp_err_info) {
		return;
	}
	
	fprintf(stderr, "<ERR>[%s]:[%d]: error termination!</ERR>\n", refp_err_info->fnname, refp_err_info->err_line);
	
	return;
}

void xc_err_setup_errorHandler( void (*refp_fn_signalize)(const xc_err_scopeInfo_t* refp_err_info) )
{
	
	if(NULL==refp_fn_signalize) {
		xc_err_globalData_obj.refp_fn_signalize=xc_errLL_sig_default;
	}
	else {
		xc_err_globalData_obj.refp_fn_signalize=refp_fn_signalize;
	}
	
	return;
}

void xc_err_setup_errorHandler_default(void)
{
	
	xc_err_globalData_obj.refp_fn_signalize=xc_errLL_sig_default;
	
	return;
}


void xc_err_signalize_error(const xc_err_scopeInfo_t* refp_err_info)
{
	if(NULL==refp_err_info) {
		return;
	}
	if(NULL==xc_err_globalData_obj.refp_fn_signalize) {
		return;
	}
	
	xc_err_globalData_obj.refp_fn_signalize(refp_err_info);
	
	return;
}
