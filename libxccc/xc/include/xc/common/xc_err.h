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

#ifndef _XC_C_ERR_H_
#define _XC_C_ERR_H_


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>


/* *** *** *** */
/* non- xc_err namespace: */
/* *** *** *** */

/*
 * The simplest implementation possible:
 * 
 * #define ERR_DECL() int _err_line_=1;
 * 
 * #define ERR_TERM(_ARG_LABEL_) do { _err_line_=__LINE__; goto _ARG_LABEL_; } while(0);
 *
 * #define ERR_HANDLE() do { fprintf(stderr,  "<ERR>[%s]:[%s]:[%d]: error termination </ERR>\n", __FILE__, __FUNCTION__, _err_line_); } while(0);
 *
 */

#define ERR_DECL() xc_err_scopeInfo_t _err_info={ __FILE__, __FUNCTION__, 1 };
 
#define ERR_TERM(_ARG_LABEL_) do { _err_info.err_line=__LINE__; goto _ARG_LABEL_; } while(0);

#define ERR_HANDLE() do { fprintf(stderr, "<ERR>[%s]:[%d]: error termination!</ERR>\n", _err_info.fnname, _err_info.err_line); } while(0);

#define ERR_TERM_POINT(_LABEL_NAME_, _STMT_) \
	_LABEL_NAME_:\
	ERR_HANDLE();\
	_STMT_;\
	;


#define RET_RETV_OK() return 0;


#define RET_RETV_ERR() return 1;


/* *** *** *** */
/* non- xc_err namespace: done */
/* *** *** *** */

/* --- --- --- --- */

/* *** *** *** */
/* xc_err namespace:  */
/* *** *** *** */

/* --- --- --- */
/* xc_err scope data: */
/* --- --- --- */

typedef struct xc_err_scopeInfo_t
{ 
	const char* filename;
	const char* fnname;
	int err_line; 
} xc_err_scopeInfo_t;


#define xc_err_decl() xc_err_scopeInfo_t _err_info={ __FILE__, __FUNCTION__, 1 };

/* --- --- --- */
/* xc_err scope data: done */
/* --- --- --- */

/* --- --- --- */

/* --- --- --- */
/* xc_err low level setup API: */
/* --- --- --- */


void xc_err_setup_errorHandler( void (*refp_fn_signalize)(const xc_err_scopeInfo_t* refp_err_info) );


void xc_err_setup_errorHandler_default(void);


void xc_err_signalize_error(const xc_err_scopeInfo_t* refp_err_info);

/* --- --- --- */
/* xc_err low level setup API: done */
/* --- --- --- */

/* --- --- --- */

/* --- --- --- */
/* xc_err scope termination: */
/* --- --- --- */


#define xc_err_term(_ARG_LABEL_) do { _err_info.err_line=__LINE__; goto _ARG_LABEL_; } while(0);


#define xc_err_term_mg() do { _err_info.err_line=__LINE__; goto L_ERR_MG; } while(0);


#define xc_err_term_unmg() do { _err_info.err_line=__LINE__; goto L_ERR_UNMG; } while(0);

/* --- --- --- */
/* xc_err scope termination: done */
/* --- --- --- */

/* --- --- --- */

/* --- --- --- */
/* xc_err scope end points: */
/* --- --- --- */

/* --- --- --- */

#define xc_err_on_mg() L_ERR_MG: do { xc_err_signalize_error(&_err_info); } while(0);

#define xc_err_handle_mg() L_ERR_MG: do { xc_err_signalize_error(&_err_info); } while(0);

/* --- --- --- */

#define xc_err_on_unmg() L_ERR_UNMG: do { xc_err_signalize_error(&_err_info); } while(0);

#define xc_err_handle_unmg() L_ERR_UNMG: do { xc_err_signalize_error(&_err_info); } while(0);

/* --- --- --- */

#define xc_err_sig() do { xc_err_signalize_error(&_err_info); } while(0);


#define xc_err_retv() (_err_info.err_line)


#define xc_err_return() return xc_err_retv();

#define xc_err_panic() do { abort(); } while(0);

/* --- --- --- */

/* --- --- --- */
/* xc_err scope end points: done */
/* --- --- --- */

/* --- --- --- */

/* *** *** *** */
/* xc_err namespace: done */
/* *** *** *** */



#ifdef __cplusplus
}
#endif

#endif
