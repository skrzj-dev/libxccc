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

#ifndef _XC_RTDBG_H_
#define _XC_RTDBG_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

#include <stdarg.h>

typedef struct xc_rtdbg_ctx_t xc_rtdbg_ctx_t;

#define xc_rtdbg_BUFSIZE 128

struct xc_rtdbg_ctx_t
{
	int enabled;
	int cur_level;
	char unit_id_str[xc_rtdbg_BUFSIZE];
	char prefix_str[xc_rtdbg_BUFSIZE];
	int (*refp_fn_msg)(const xc_rtdbg_ctx_t* refp_ctx, const char* str_prefix, const char* str_msg);
	
};

typedef struct xc_rtdbg_scope_t
{
	const xc_rtdbg_ctx_t* refp_ctx;
	const char* fnname;
	int linenr;
}  xc_rtdbg_scope_t;


xc_rtdbg_scope_t xc_rtdbg_scope_itz_retv(const xc_rtdbg_ctx_t* refp_ctx, const char* fnname, const int line);


#define xc_rtdbg_scope(_ARG_REFP_RTDBG_CTX_) xc_rtdbg_scope_itz_retv(_ARG_REFP_RTDBG_CTX_, __FUNCTION__, __LINE__)


int xc_rtdbg_msg_LL(
	  const xc_rtdbg_ctx_t* refp_ctx
	, const char* fnname
	, const int linenr
	, const int level
	, const char* msg_fmt
	, ...
) __attribute__( (format(printf, 5, 6) ) );


/* to be used in  ANSI-C as : xc_rtdbg_msg_c( xc_rtdbg_scope(&user_ctx), "user msg fmt", user fmt params)*/

int xc_rtdbg_msg_c(
	  xc_rtdbg_scope_t scopeInfo
	, const int level
	, const char* msg_fmt
	, ...
) __attribute__( (format(printf, 3, 4) ) );


#if 0 /* C99 todo */
#define xc_rtdbg_msg_u(_ARG_REFP_RTDBG_CTX_, _ARG_LEVELNR_, _ARG_MSGFMT_, ...) xc_rtdbg_msg_LL(\
		  (_ARG_REFP_RTDBG_CTX_)\
		, __FUNCTION__\
		, __LINE__\
		, (_ARG_LEVELNR_)\
		, _ARG_MSGFMT,##__VA_ARGS__\
	)
#endif


/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
