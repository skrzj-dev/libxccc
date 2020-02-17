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
#include "xc/common/xc_rtdbg.h"
/* --- */

int xc_rtdbg_msg_LL(const xc_rtdbg_ctx_t* refp_ctx, const char* fnname, const int linenr, const int level, const char* msg_fmt, ...)
{
	int retv=0;
	va_list args;
	char linebuffer_prefix[256]={0};
	char linebuffer_runtime[256]={0};
	/* --- */
	
	/* validate params: */
	if(NULL==refp_ctx) {
		return  10;
	}
	if(NULL==refp_ctx->refp_fn_msg) {
		return  11;
	}
	if(NULL==msg_fmt) {
		return  20;
	}
	/* validate params: done */
	
	/* --- */
	
	/* shortcut end: */
	if(0==refp_ctx->enabled) {
		return 0;
	}
	if(level > refp_ctx->cur_level ) {
		return 0;
	}
	/* shortcut end: done */
	
	/* --- */
	
	/* prepare print strs: */
	snprintf(linebuffer_prefix, sizeof(linebuffer_prefix), "DBG:([%s]:[%d]):{[%s]:[%s]}:", 
		  (NULL != fnname) ? fnname : "<NULL!>"
		, linenr
		,  refp_ctx->unit_id_str
		,  refp_ctx->prefix_str
	);
	va_start (args, msg_fmt);
	vsnprintf(linebuffer_runtime, sizeof(linebuffer_runtime), msg_fmt, args);
	va_end (args);
	/* prepare print strs: done */
	
	/* call msg print callback: */
	retv=refp_ctx->refp_fn_msg(refp_ctx, linebuffer_prefix, linebuffer_runtime);
	/* call msg print callback: done */
	
	return retv;
}

xc_rtdbg_scope_t xc_rtdbg_scope_itz_retv(const xc_rtdbg_ctx_t* refp_ctx, const char* fnname, const int line)
{
	xc_rtdbg_scope_t retv={0};
	
	retv.fnname=fnname;
	retv.linenr=line;
	retv.refp_ctx=refp_ctx;
	
	return retv;
}


int xc_rtdbg_msg_c(
	  xc_rtdbg_scope_t scopeInfo
	, const int level
	, const char* msg_fmt
	, ...
)
{
	int retv=0;
	va_list args;
	char linebuffer_prefix[256]={0};
	char linebuffer_runtime[256]={0};
	/* --- */
	
	/* validate params: */
	if(NULL==scopeInfo.refp_ctx) {
		return  10;
	}
	if(NULL==scopeInfo.refp_ctx->refp_fn_msg) {
		return  11;
	}
	if(NULL==msg_fmt) {
		return  20;
	}
	/* validate params: done */
	
	/* --- */
	
	/* shortcut end: */
	if(0==scopeInfo.refp_ctx->enabled) {
		return 0;
	}
	if(level > scopeInfo.refp_ctx->cur_level ) {
		return 0;
	}
	/* shortcut end: done */
	
	/* --- */
	
	/* prepare print strs: */
	snprintf(linebuffer_prefix, sizeof(linebuffer_prefix), "DBG:([%s]:[%d]):{[%s]:[%s]}:", 
		  (NULL != scopeInfo.fnname) ? scopeInfo.fnname : "<NULL!>"
		, scopeInfo.linenr
		, scopeInfo.refp_ctx->unit_id_str
		, scopeInfo.refp_ctx->prefix_str
	);
	va_start (args, msg_fmt);
	vsnprintf(linebuffer_runtime, sizeof(linebuffer_runtime), msg_fmt, args);
	va_end (args);
	/* prepare print strs: done */
	
	/* call msg print callback: */
	retv=scopeInfo.refp_ctx->refp_fn_msg(scopeInfo.refp_ctx, linebuffer_prefix, linebuffer_runtime);
	/* call msg print callback: done */
	
	return retv;
}
