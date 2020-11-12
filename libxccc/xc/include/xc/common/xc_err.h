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
/* xc_err scope termination points: */
/* --- --- --- */

/* --- --- --- */

#define xc_err_termpt_mg() L_ERR_MG: do { xc_err_sig(); } while(0);
#define xc_err_on_mg() L_ERR_MG: do { xc_err_sig(); } while(0);
#define xc_err_handle_mg() L_ERR_MG: do { xc_err_sig(); } while(0);

/* --- --- --- */

#define xc_err_termpt_unmg() L_ERR_UNMG: do { xc_err_sig(); } while(0);
#define xc_err_on_unmg() L_ERR_UNMG: do { xc_err_sig(); } while(0);
#define xc_err_handle_unmg() L_ERR_UNMG: do { xc_err_sig(); } while(0);

/* --- --- --- */

#define xc_err_sig() do { xc_err_signalize_error(&_err_info); } while(0);

#define xc_err_retv() (_err_info.err_line)

#define xc_err_return() return xc_err_retv();

#define xc_err_panic() do { abort(); } while(0);

/* --- --- --- */

/* --- --- --- */
/* xc_err scope termination  points: done */
/* --- --- --- */

/* --- --- --- */

/* *** *** *** */
/* xc_err namespace: done */
/* *** *** *** */

#ifdef __cplusplus
}
#endif

#endif
