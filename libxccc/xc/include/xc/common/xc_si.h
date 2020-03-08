/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2019 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */

#ifndef _XC_INT_H_
#define _XC_INT_H_

#include <stdint.h>

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

/* --- --- --- --- --- --- --- --- */

/* mark unchecked operations */
#define xc_si_UNCHECKED(_ARG_STMT_) (_ARG_STMT_)

typedef enum xc_si_retv_t
{
	  xc_si_retv_ok=0
	, xc_si_retv_nullParam=1
	, xc_si_retv_overflow=12
	, xc_si_retv_underflow=16
	, xc_si_retv_divByZero=20
	
} xc_si_retv_t;

typedef struct xc_si_uint_t xc_si_uint_t;
typedef struct xc_si_int_t xc_si_int_t;
typedef struct xc_si_size_t_t xc_si_size_t_t;
typedef struct xc_si_uintptr_t_t xc_si_uintptr_t_t;

/* --- --- --- --- --- --- --- --- */

#define xc_si_isError(_ARG_VAL_TARGET_) ( xc_si_retv_ok != (_ARG_VAL_TARGET_)._private_err )

#define xc_si_getStatus(_ARG_VAL_TARGET_) ( (const xc_si_retv_t)(_ARG_VAL_TARGET_)._private_err )

#define xc_si_isOk(_ARG_VAL_TARGET_) ( xc_si_retv_ok == (_ARG_VAL_TARGET_)._private_err )

#define xc_si_val(_ARG_VAL_TARGET_) ( (_ARG_VAL_TARGET_)._private_val )

/* --- --- --- --- --- --- --- --- */

/* --- --- --- --- */
/* int : */
/* --- --- --- --- */

struct xc_si_int_t
{
	xc_si_retv_t _private_err;
	int _private_val;
};

#define xc_si_int_val(_ARG_VAL_TARGET_) ( (const int)(_ARG_VAL_TARGET_)._private_val )

xc_si_int_t xc_si_int(const xc_si_int_t val);
xc_si_int_t xc_si_int_p(const int* val);
xc_si_int_t xc_si_int_v(const int val);

xc_si_int_t xc_si_int_add(const xc_si_int_t param, const xc_si_int_t val);
xc_si_int_t xc_si_int_sub(const xc_si_int_t param, const xc_si_int_t val);
xc_si_int_t xc_si_int_div(const xc_si_int_t param, const xc_si_int_t val);
xc_si_int_t xc_si_int_mul(const xc_si_int_t param, const xc_si_int_t val);

xc_si_int_t xc_si_int_from_uint(const xc_si_uint_t param);
xc_si_int_t xc_si_int_from_size_t(const xc_si_size_t_t param);
xc_si_int_t xc_si_int_from_uintptr_t(const xc_si_uintptr_t_t target_val);

/* --- --- --- --- */
/* int : done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- --- */

/* --- --- --- --- */
/* uint : */
/* --- --- --- --- */

struct xc_si_uint_t
{
	xc_si_retv_t _private_err;
	unsigned int _private_val;
};

#define xc_si_uint_val(_ARG_VAL_TARGET_) ( (const unsigned int)(_ARG_VAL_TARGET_)._private_val )

xc_si_uint_t xc_si_uint_from_int(const xc_si_int_t param);
xc_si_uint_t xc_si_uint_from_size_t(const xc_si_size_t_t param);

/* --- --- --- --- */
/* uint : done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- --- */

/* --- --- --- --- */
/* size_t : */
/* --- --- --- --- */

struct xc_si_size_t_t
{
	xc_si_retv_t _private_err;
	size_t _private_val;
};

#define xc_si_size_t_val(_ARG_VAL_TARGET_) ( (const size_t)(_ARG_VAL_TARGET_)._private_val )

xc_si_size_t_t xc_si_size_t_from_int(const xc_si_int_t param);
xc_si_size_t_t xc_si_size_t_from_uint(const xc_si_uint_t param);

/* --- --- --- --- */
/* size_t : done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- --- */

/* --- --- --- --- */
/* uintptr_t : */
/* --- --- --- --- */

struct xc_si_uintptr_t_t
{
	xc_si_retv_t _private_err;
	uintptr_t _private_val;
};

#define xc_si_uintptr_t_t_val(_ARG_VAL_TARGET_) ( (const uintptr_t)(_ARG_VAL_TARGET_)._private_val )

xc_si_uintptr_t_t xc_si_uintptr_t_p(const uintptr_t* param);
xc_si_uintptr_t_t xc_si_uintptr_t_v(const uintptr_t param);
xc_si_size_t_t xc_si_uintptr_t_from_int(const xc_si_int_t param);
xc_si_size_t_t xc_si_uintptr_t_from_uint(const xc_si_uint_t param);

/* --- --- --- --- */
/* uintptr_t : done */
/* --- --- --- --- */

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
