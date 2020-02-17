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

#ifndef _XC_HASHFN_H_
#define _XC_HASHFN_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

#include <stdint.h>
#include <string.h>
#include <inttypes.h>

typedef struct xc_hash_inputBytes_t
{
	size_t bytesize;
	const unsigned char* bytes;
	
} xc_hash_inputBytes_t;


typedef struct xc_hash_val32_t
{
	union {
		unsigned int val;
		unsigned char bytes[4];
	} v;
	
} xc_hash_val32_t;

typedef struct xc_hash_val64_t
{
	union {
		uint64_t val64;
		unsigned char bytes[8];
	} v;
	
} xc_hash_val64_t;

xc_hash_inputBytes_t xc_hash_inputBytes(const size_t arg_bytesize, const unsigned char* arg_bytePtr);

xc_hash_inputBytes_t xc_hash_inputBytes_fromCstr(const char* arg_str);

int xc_hash_x65599_32(const xc_hash_inputBytes_t arg_input, xc_hash_val32_t* refp_result);

int xc_hash_x65599_64(const xc_hash_inputBytes_t arg_input, xc_hash_val64_t* refp_result);

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
