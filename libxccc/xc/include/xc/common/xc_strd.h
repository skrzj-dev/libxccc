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

#ifndef _XC_STRD_H_
#define _XC_STRD_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

#include <stdarg.h>
#include <string.h>
/* --- */
#include "xc/common/xc_initcheck.h"
/* --- */

typedef struct xc_strd_private_t xc_strd_private_t;

typedef struct xc_strd_t
{
	xc_initc_anyscopeNZ_t d_inits;
	xc_strd_private_t* d_private;
	
} xc_strd_t;


typedef struct xc_str_substrOffs_t
{
	int off;
	int length;
	int overflow;
	
} xc_str_substrOffs_t;


typedef struct xc_strd_finds_t
{
	int entry_arrayLen;
	xc_str_substrOffs_t* entry_array;
	
} xc_strd_finds_t;

const char* xc_strd_cstr(const xc_strd_t* refp_self);

int xc_strd_isInit(const xc_strd_t* refp_self);
int xc_strd_init(xc_strd_t* refp_self);
int xc_strd_init_vfmt(xc_strd_t* refp_self, const char* fmt, va_list arg_va);
int xc_strd_init_fmt(xc_strd_t* refp_self, const char* fmt, ...) __attribute__( (format(printf, 2, 3) ) );
int xc_strd_deinit(xc_strd_t* refp_Self);

int xc_strd_getLength(const xc_strd_t* refp_self);
int xc_strd_getLastOff(const xc_strd_t* refp_self);

int xc_strd_set(xc_strd_t* refp_self, const xc_strd_t* refp_str);
int xc_strd_set_fmt(xc_strd_t* refp_self, const char* fmt, ...) __attribute__( (format(printf, 2, 3) ) );
int xc_strd_set_vfmt(xc_strd_t* refp_self, const char* fmt, va_list args);

int xc_strd_append(xc_strd_t* refp_self, const xc_strd_t* refp_str);
int xc_strd_append_sub(xc_strd_t* refp_self, const xc_strd_t* refp_str, const xc_str_substrOffs_t range);
int xc_strd_append_fmt(xc_strd_t* refp_self, const char* fmt, ...) __attribute__( (format(printf, 2, 3) ) );
int xc_strd_append_vfmt(xc_strd_t* refp_self, const char* fmt, va_list args);

int xc_strd_appendLn(xc_strd_t* refp_self, const xc_strd_t* refp_str);
int xc_strd_appendLn_sub(xc_strd_t* refp_self, const xc_strd_t* refp_str, const xc_str_substrOffs_t range);
int xc_strd_appendLn_fmt(xc_strd_t* refp_self, const char* fmt, ...) __attribute__( (format(printf, 2, 3) ) );
int xc_strd_appendLn_vfmt(xc_strd_t* refp_self, const char* fmt, va_list args);

int xc_strd_prepend(xc_strd_t* refp_self, const xc_strd_t* refp_str);
int xc_strd_prepend_fmt(xc_strd_t* refp_self, const char* fmt, ...) __attribute__( (format(printf, 2, 3) ) );
int xc_strd_prepend_vfmt(xc_strd_t* refp_self, const char* fmt, va_list args);

int xc_strd_insert(xc_strd_t* refp_self, const int target_off, const xc_strd_t* refp_str);
int xc_strd_insert_sub(xc_strd_t* refp_self, const int target_off, const xc_strd_t* refp_str, const xc_str_substrOffs_t offs);
int xc_strd_insert_fmt(xc_strd_t* refp_self, const int target_off, const char* fmt, ...);
int xc_strd_insert_vfmt(xc_strd_t* refp_self, const int target_off, const char* fmt, va_list args);

int xc_strd_remSubstr(xc_strd_t* refp_self);
int xc_strd_remSubstr_fmt(xc_strd_t* refp_self, const char* fmt, ...) __attribute__( (format(printf, 2, 3) ) );
int xc_strd_remSubstr_vfmt(xc_strd_t* refp_self, const char* fmt, va_list args);

int xc_strd_remOffLen(xc_strd_t* refp_self, const int off, const int len);
int xc_strd_remOffRange(xc_strd_t* refp_self, const int off1, const int off2);

int xc_strd_replaceSubstr_cstr(xc_strd_t* refp_self, const char* str_replaced, const char* str_replacing);

int xc_strd_overwrOff(xc_strd_t* refp_self, const int target_off, const xc_strd_t* refp_str);
int xc_strd_overwrOff_fmt(xc_strd_t* refp_self, const int target_off, const char* fmt, ...) __attribute__( (format(printf, 3, 4) ) );
int xc_strd_overwrOff_vfmt(xc_strd_t* refp_self, const int target_off, const char* fmt, va_list arg_va);

int xc_strd_findNext_off(const xc_strd_t* refp_self, xc_str_substrOffs_t* refp_result, const int off, const char* str_to_find);
int xc_strd_findAll_alloc(const xc_strd_t* refp_self, xc_strd_finds_t* refp_result, const char* str_to_find);

int xc_strd_substrOffLen_alloc(const xc_strd_t* refp_self, const int off, const int len, xc_strd_t* refp_result);
int xc_strd_substrOffRange_alloc(const xc_strd_t* refp_self, const int off1, const int off2, xc_strd_t* refp_result);

int xc_strd_toUpper(xc_strd_t* refp_self);
int xc_strd_toLower(xc_strd_t* refp_self);

int xc_strd_finds_deinit(xc_strd_finds_t* refp_result);

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
