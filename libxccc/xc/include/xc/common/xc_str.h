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

#ifndef _XC_STR_H_
#define _XC_STR_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

typedef char xc_str_char_t;
#define xc_str_npos (-1)
#define xc_str_is_npos(_ARG_X_) ( (_ARG_X_) < 0 ) 

int xc_str_calc_overflow_offLen(const int orig_capacity, const int orig_len, const int target_off, const int addedlen, int* result_overflow);

int xc_str_offLen_validLenBound(const int capacity, const int len, const int tested_off, const int tested_len, int* result_len);

int xc_str_off_validLenBound(const int capacity, const int len, const int tested_off);

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
