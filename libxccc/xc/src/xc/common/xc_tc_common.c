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

#include <stddef.h>
#include <limits.h>
#include <stdint.h>
/* --- */
#include "xc/common/xc_tc_common.h"
/* --- */


int xc_tc_validate_arrayStaticSize(const size_t capacity, const size_t item_bytesize)
{
	size_t max_possible_capacity=0;
	
	if(0 == item_bytesize) {
		return 101;
	}
	if(0 == capacity) {
		return 102;
	}
	
	/* 1) CAPACITY must be indexable with INT_MAX: */
	if( 0 == xc_tc_isValid_capacity_staticRange_uint(capacity) ) {
		return 200;
	}
	
	/* I assume that if ITEMSIZE exceeds max possible CAPACITY, then we deal with something really wrong */
	
	if( 0 == xc_tc_isValid_capacity_staticRange_uint(item_bytesize) ) { 
		return 300;
	}
	/* 1) all variables must be inside INT_MAX: done */
	
	/* 2) requested capacity MUST NOT exceed MAX POSSIBLE CAPACITY (using MAX for capacity size_t) : */
	max_possible_capacity=SIZE_MAX/item_bytesize; /* check max possible count of items of size {item_bytesize} */
	if( capacity > max_possible_capacity ) {
		return 400;
	}
	/* 2) requested capacity MUST NOT exceed MAX POSSIBLE CAPACITY (using MAX for capacity size_t) : done */
	
	return 0;
}


int xc_tc_calc_overflow(const size_t dest_initial_capacity, const size_t src_length, size_t* refp_result)
{
	size_t diff=0;
	
	if(NULL!=refp_result)
	{
		if( src_length > dest_initial_capacity ) {
			diff=src_length-dest_initial_capacity;
		}
		else 
		if( src_length < dest_initial_capacity ) {
			diff=0; /* no need to export anything */
		}
		else {
			diff=0;
		}
		
		*refp_result=diff;
	}
	else
	{
		return 1;
	}
	
	return 0;
}

xc_tc_LLII_idx_t xc_tc_LLII_idx_itz(const int idx0)
{
	xc_tc_LLII_idx_t retv={0};
	
	retv.idx0=idx0;
	
	return retv;
}
