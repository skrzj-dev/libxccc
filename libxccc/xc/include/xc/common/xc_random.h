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

#ifndef _XC_RANDOM_H_
#define _XC_RANDOM_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */


int xc_rand_range_int(const int range_min, const int range_max);

unsigned int xc_rand_range_uint(const unsigned int range_min, const unsigned int range_max);


/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
