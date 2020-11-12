/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2020 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */
 
#ifndef _XC_STRC_LL_H_
#define _XC_STRC_LL_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

/*
 * File content:
 * Low Levvel (LL) interface to work with strings, immutable modifying operations and read- only operations
 * 
 * Namespace prefix: xc_strc*
 * 
 * This interface is NOT intended to be used in user context; it is intended to be used INTERNALLY in xc_str* components.
 *
 */

#include "xc_strc_ll_types.h"

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

extern const char xc_strc_LL_termC;

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

int xc_strc_allocEmpty_fixedSize(const int length, xc_strcRW_t* result_target, size_t* result_capacity);

char xc_strc_LL_TOLOWER(char arg);

int xc_strc_LL_eqNC(const xc_strcRO_t* cstr_1st, const xc_strcRO_t* cstr_2nd);
int xc_strc_LL_eq(const xc_strcRO_t* cstr_1st, const xc_strcRO_t* cstr_2nd);

int xc_strcs_LL_ifContainsNC(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find);
int xc_strcs_LL_ifContains(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find);

int xc_strcs_LL_findNext(const xc_strcRO_t* refp_self, const int start_off, const xc_strcRO_t* refp_str2find, xc_strc_subStrInfo_t* refp_result);
int xc_strcs_LL_findNextNC(const xc_strcRO_t* refp_self, const int start_off, const xc_strcRO_t* refp_str2find, xc_strc_subStrInfo_t* refp_result);

int xc_strcs_LL_ifEndsWith(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find);
int xc_strcs_LL_ifEndsWithNC(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find);

int xc_strcs_LL_ifStartsWith(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find);
int xc_strcs_LL_ifStartsWithNC(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find);

int xc_strc_LL_substrInfo_isValid(const int target_length, const xc_strc_subStrInfo_t* refp_substrInfo);
int xc_strc_LL_substr(const xc_strcRO_t* refp_self, const xc_strc_subStrInfo_t* refp_substrInfo, xc_strcRW_t* refp_result);

int xc_strcs_LL_init_substr(const xc_strcRO_t* refp_self, const xc_strc_subStrInfo_t* refp_info, xc_strcRW_t* refp_result, size_t* result_capacity);

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
