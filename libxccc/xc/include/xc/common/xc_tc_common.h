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

#ifndef _XC_TC_COMMON_H_
#define _XC_TC_COMMON_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

#include <limits.h>
#include <stddef.h>


#define xc_tc_isValid_idx_staticRange(_VAL_PUBLIC_IDX_) ( ( (_VAL_PUBLIC_IDX_) >= 0 ) && ( (_VAL_PUBLIC_IDX_) < INT_MAX ) )


#define xc_tc_isValid_capacity_staticRange_int(_VAL_PUBLIC_IDX_) ( ( (_VAL_PUBLIC_IDX_) > 0 ) && ( (_VAL_PUBLIC_IDX_) <= INT_MAX ) )


#define xc_tc_isValid_capacity_staticRange_uint(_VAL_PUBLIC_IDX_) ( ( (_VAL_PUBLIC_IDX_) > 0 ) && ( (_VAL_PUBLIC_IDX_) <= INT_MAX ) )


int xc_tc_validate_arrayStaticSize(const size_t capacity, const size_t item_bytesize);


int xc_tc_calc_overflow(const size_t dest_initial_capacity, const size_t src_length, size_t* refp_result);

typedef struct xc_tc_LLII_idx_t
{
	int idx0;
} xc_tc_LLII_idx_t;

#define xc_tc_LLII_idx_itz_invalid() {-1}

xc_tc_LLII_idx_t xc_tc_LLII_idx_itz(const int idx0 );

#define xc_tc_LLII_idx_isInvalid(_REFP_SELF_) ( -1 == (_REFP_SELF_)->idx0 )

/* --- --- --- */


/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
