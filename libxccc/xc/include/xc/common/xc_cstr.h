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

#ifndef _XC_CSTR_H_
#define _XC_CSTR_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

#include <stdarg.h>
#include <string.h>
/* --- */

typedef struct xc_cstrd_t
{
	int d_len;
	int d_capacity;
	char* d_buf;
	
} xc_cstrd_t;

typedef struct xc_cstrRo_t
{
	int ro_len;
	const char* ro_buf;
	
} xc_cstrRo_t;

xc_cstrRo_t xc_cstrRo(const char* str);

int xc_cstrd_vfmt(xc_cstrd_t* refp_self, const char* fmt, va_list arg_va);

int xc_cstrd_deinit(xc_cstrd_t* refp_self);

#define xc_TXT(_ARG_LITERAL_TXT_) ""_ARG_LITERAL_TXT_""

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
