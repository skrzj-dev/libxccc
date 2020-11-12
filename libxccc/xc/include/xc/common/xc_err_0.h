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

#ifndef _XC_ERR_0_H_
#define _XC_ERR_0_H_

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

#define ERR_TERMPT(_LABEL_NAME_, _STMT_) \
	_LABEL_NAME_:\
	ERR_HANDLE();\
	_STMT_;\
	;


#define RET_RETV_OK() return 0;


#define RET_RETV_ERR() return 1;


/* *** *** *** */
/* non- xc_err namespace: done */
/* *** *** *** */

#ifdef __cplusplus
}
#endif

#endif

#endif
