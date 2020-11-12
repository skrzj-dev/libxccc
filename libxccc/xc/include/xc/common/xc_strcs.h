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

#ifndef _XC_STRCS_H_
#define _XC_STRCS_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

#include <stdarg.h>
#include <string.h>
/* --- */
#include "xc/common/xc_initcheck.h"
#include "xc/common/xc_hash.h"
#include "xc_strc_ll_types.h"
/* --- */

/* --- --- --- */

typedef struct xc_strcs_private_t
{
	xc_initc_anyscopeNZ_t initcheck;
	xc_hash_val32_t hash32;
	int strcs_len;
	size_t strcs_capacity;
	char* strcs_buf;
	
} xc_strcs_private_t;

typedef struct xc_strcs_t
{
	xc_strcs_private_t private_data;
	
} xc_strcs_t;

typedef struct xc_strcsa_t
{
	xc_strcs_t obj;
	
} xc_strcsa_t;

/* --- --- --- */

int xc_strcs_isInit(const xc_strcs_t* refp_self);
int xc_strcs_from_init(xc_strcs_t* refp_self, const xc_strcs_t* refp_src);
int xc_strcs_fromVfmt_init(xc_strcs_t* refp_self, const char* fmt, va_list arg_va);
int xc_strcs_fromFmt_init(xc_strcs_t* refp_self, const char* fmt, ...);
int xc_strcs_fromCstr_init(xc_strcs_t* refp_self, const char* fmt);

int xc_strcs_deinit(xc_strcs_t* refp_self);

int xc_strcs_isInit(const xc_strcs_t* refp_src);

int xc_strcs_LL_DIAG_verifyIntegrity(const xc_strcs_t* refp_target);

int xc_strcs_get_length(const xc_strcs_t* refp_self);
size_t xc_strcs_get_capacity(const xc_strcs_t* refp_self);
const char* xc_strcs_get_cstr(const xc_strcs_t* refp_self);

/* --- --- --- */

xc_strcsa_t* xc_strcs_from_alloc(const xc_strcs_t* refp_src);
xc_strcsa_t* xc_strcs_fromVfmt_alloc(const char* fmt, va_list arg_va);
xc_strcsa_t* xc_strcs_fromFmt_alloc(const char* fmt, ...);
xc_strcsa_t* xc_strcs_fromCstr_alloc(const char* fmt);

int xc_strcs_dealloc(xc_strcsa_t* refp_self);

/* --- --- --- */

int xc_strcs_eq(const xc_strcs_t* refp_self, const xc_strcs_t* refp_target);
int xc_strcs_eqNC(const xc_strcs_t* refp_self, const xc_strcs_t* refp_target);

int xc_strcs_eq_cstr(const xc_strcs_t* refp_self, const char* refp_target_str);
int xc_strcs_eqNC_cstr(const xc_strcs_t* refp_self, const char* refp_target_str);

/* --- --- --- */

int xc_strcs_ifContains(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find);
int xc_strcs_ifContainsNC(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find);
int xc_strcs_ifContains_cstr(const xc_strcs_t* refp_self, const char* str2find);
int xc_strcs_ifContainsNC_cstr(const xc_strcs_t* refp_self, const char* cstr_str2find);

/* --- --- --- */

int xc_strcs_ifStartsWith(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find);
int xc_strcs_ifStartsWithNC(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find);
int xc_strcs_ifStartsWith_cstr(const xc_strcs_t* refp_self, const char* str2find);
int xc_strcs_ifStartsWithNC_cstr(const xc_strcs_t* refp_self, const char* str2find);

/* --- --- --- */

int xc_strcs_ifEndsWith(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find);
int xc_strcs_ifEndsWithNC(const xc_strcs_t* refp_self, const xc_strcs_t* refp_str2find);
int xc_strcs_ifEndsWith_cstr(const xc_strcs_t* refp_self, const char* str2find);
int xc_strcs_ifEndsWithNC_cstr(const xc_strcs_t* refp_self, const char* str2find);

/* --- --- --- */

int xc_strcs_findNext(const xc_strcs_t* refp_self, const int start_off, const xc_strcs_t* refp_str2find, xc_strc_subStrInfo_t* refp_result);
int xc_strcs_findNextNC(const xc_strcs_t* refp_self, const int start_off, const xc_strcs_t* refp_str2find, xc_strc_subStrInfo_t* refp_result);

int xc_strcs_findNext_cstr(const xc_strcs_t* refp_self, const int start_off, const char* cstr2find, xc_strc_subStrInfo_t* refp_result);
int xc_strcs_findNextNC_cstr(const xc_strcs_t* refp_self, const int start_off, const char* cstr2find, xc_strc_subStrInfo_t* refp_result);

/* --- --- --- */

int xc_strcs_substr_init(const xc_strcs_t* refp_self, const xc_strc_subStrInfo_t* refp_info, xc_strcs_t* refp_result);

/* --- --- --- */

#if 0
int xc_strcs_toUpper(xc_strcs_t* refp_result, const xc_strcs_t* refp_src);
int xc_strcs_toUpper_cstr(xc_strcs_t* refp_result, const char* cstr_src);

int xc_strcs_toLower(xc_strcs_t* refp_result, const xc_strcs_t* refp_src);
int xc_strcs_toLower_cstr(xc_strcs_t* refp_result, const char* cstr_src);

int xc_strcs_toReversed(xc_strcs_t* refp_result, const xc_strcs_t* refp_src);
int xc_strcs_toReversed_cstr(xc_strcs_t* refp_result, const char* cstr_src);
#endif

/* --- --- --- */

#if 0
int xc_strcs_concat(xc_strcs_t* refp_result, const xc_strcs_t* refp_str1st, const xc_strcs_t* refp_str2nd);
int xc_strcs_concat_cstr2(xc_strcs_t* refp_result, const char* cstr1st, const char* cstr2nd);

xc_strcs_t* xc_strcs_concatNew(const xc_strcs_t* refp_self, const xc_strcs_t* refp_src);
xc_strcs_t* xc_strcs_concatNew_cstr2(const char* refp_self, const char* refp_src);
#endif


#if 0 /* TODO */

int xc_strcs_substr(const xc_strcs_t* refp_self, xc_strcs_t* refp_result, const int off, const int len);

int xc_strcs_strsubst_cstr(const xc_strcs_t* refp_self, xc_strcs_t* refp_result, const char* cstr_tosubst, const char* cstr_substitution);
 
typedef struct xc_strcs_fragments_t
{
	int array1d_capacity;
	xc_strcs_t* array1d;
	
} xc_strcs_fragments_t;

int xc_strcs_fragments_dealloc(xc_strcs_fragments_t* refp_target);

xc_strcs_fragments_t* xc_strcs_splitNew(const xc_strcs_t* refp_self, const char* str_delim);
xc_strcs_t* xc_strcs_joinNew(const xc_strcs_t* refp_self, const char* str_delim);

#endif

/* --- --- --- */


/* --- --- --- */

#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
