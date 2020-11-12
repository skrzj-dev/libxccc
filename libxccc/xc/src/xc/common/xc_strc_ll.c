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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
/* --- */
#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
#include "xc/common/xc_si.h"
#include "xc/am_seq/xc_am_seq.h"
#include "xc/common/xc_preprocessor.h"
/* --- */
#include "xc/common/xc_strc_ll.h"
/* --- */

const char xc_strc_LL_termC=0x03;

#define xc_strc_LL_length2capacity(_ARG_LENGTH_) ( (size_t)( (size_t)(_ARG_LENGTH_)+( (size_t)(2) ) ) )

/* this helper can be used only after it's valiidated that _ARG_HAYSTACK_LENGTH_ >= _ARG_NEEDLE_LENGTH_  */
#define xc_strcs_LL_POSSIBLE_OCCURENCES_NUMBER_FOR_SEARCH(_ARG_HAYSTACK_LENGTH_, _ARG_NEEDLE_LENGTH_ ) ( ( (_ARG_HAYSTACK_LENGTH_) - (_ARG_NEEDLE_LENGTH_) ) +1 )

/* this helper can be used only after it's valiidated that _ARG_HAYSTACK_LENGTH_ >= _ARG_NEEDLE_LENGTH_  */
#define xc_strcs_LL_POSSIBLE_OCCURENCES_NUMBER_FOR_SEARCH_FROMOFF(_ARG_HAYSTACK_LENGTH_, _ARG_OFF_, _ARG_NEEDLE_LENGTH_ ) ( ( (_ARG_HAYSTACK_LENGTH_) - (_ARG_OFF_) - (_ARG_NEEDLE_LENGTH_) ) +1 )


/* this intended to be private for xc_strcs_LL; user won't have result that requires such validation */
#define xc_strc_subStrInfo_isInvalid_wildcardLength(_ARG_REFP_OBJ_) ( \
	( (_ARG_REFP_OBJ_)->off < 0 ) \
)

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

static int xc_str_LL_calculate_substr_len(const int target_len, const xc_strc_subStrInfo_t* refp_info, int* result_len);

static int xc_strc_LL__isSubstrMatchNC(const xc_strcRO_t* refp_self, const int self_off, const xc_strcRO_t* refp_substr);

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

static int xc_strc_LL__isSubstrMatchNC(const xc_strcRO_t* refp_self, const int self_off, const xc_strcRO_t* refp_substr)
{
	int len=0;
	int substr_off=0;
	xc_err_decl();
	/* --- */
	
	len=refp_substr->ro_len;
	
	for( substr_off=0; substr_off<len; xc_INC(substr_off) )
	{
		char ch1=refp_self->ro_buf[self_off+substr_off];
		char ch2=refp_substr->ro_buf[substr_off];
		
		if(0 == ch1 || 0 == ch2 ) {
			xc_err_term_unmg(); /* should never happen, kept as sanity check */
		}
		
		ch1=xc_strc_LL_TOLOWER(ch1);
		ch2=xc_strc_LL_TOLOWER(ch2);
		
		if(ch1 != ch2) {
			return 0;
		}
	}
	
	return 1;
	
	xc_err_termpt_unmg();
	return 0;
}

int xc_strc_allocEmpty_fixedSize(const int length, xc_strcRW_t* result_target, size_t* result_capacity)
{
	xc_err_decl();
	/* --- */
	
	if(NULL==result_capacity) {
		xc_err_term_unmg();
	}
	if(NULL==result_target) {
		xc_err_term_unmg();
	}
	if(length<0) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* alloc buffer: */
	if(1)
	{
		const size_t capacity=xc_strc_LL_length2capacity(length);
		char* alloc_buf=NULL;
		
		alloc_buf=xc_mem_allocz_obj_array(char, capacity);
		
		if(NULL == alloc_buf ) {
			xc_err_term_unmg();
		}
		
		alloc_buf[capacity-1]=xc_strc_LL_termC;
		
		/* FINALZATION: */
		/* when everything is succesful: deinit self (if required), zero object bytes, assign new data */
		if(1)
		{
			xc_strcRW_LL_SET(result_target, length, alloc_buf);
			*result_capacity = capacity;
		}
		/* FINALZIATION: done */
	}
	/* alloc buffer: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

char xc_strc_LL_TOLOWER(char arg)
{
	return arg >= 'A'&& arg <='Z' 
		? arg + 32
		: arg;
}

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

int xc_strc_LL_eqNC(const xc_strcRO_t* cstr_1st, const xc_strcRO_t* cstr_2nd)
{
	size_t tmpsize=0;
	size_t n=0;
	
	if(cstr_1st->ro_len != cstr_2nd->ro_len ) {
		return 0;
	}
	
	if( 0 == cstr_1st->ro_len ) {
		return 1;
	}
	
	tmpsize=cstr_1st->ro_len; /* OK uint <- validated int */
	
	for(n=0; n<tmpsize; xc_INC(n) ) 
	{
		if( xc_strc_LL_TOLOWER(cstr_1st->ro_buf[n]) != xc_strc_LL_TOLOWER(cstr_2nd->ro_buf[n] ) ) {
			return 0;
		}
	}
	
	return 1;
}


int xc_strc_LL_eq(const xc_strcRO_t* cstr_1st, const xc_strcRO_t* cstr_2nd)
{
	xc_err_decl();
	
	if(NULL == cstr_1st) {
		xc_err_term_unmg();
	}
	if(NULL == cstr_2nd) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( cstr_1st->ro_len != cstr_2nd->ro_len ) {
		return 0;
	}
	
	/* optimization :
	 * now its varranted that lengths are the same; use [memcmp] instead of [str*cmp] for better performance
	 */
	if( 0 != memcmp( (const void*)cstr_1st->ro_buf, (const void*)cstr_2nd->ro_buf, cstr_1st->ro_len) ) {
		return 0;
	}
	
	return 1;
	
	xc_err_on_unmg();
	return 0;
}

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

int xc_strcs_LL_ifContainsNC(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find)
{
	xc_strc_subStrInfo_t result=xc_strc_subStrInfo_ITZ_empty();
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(0 != xc_strcs_LL_findNextNC(refp_self, 0, refp_str2find, &result) ) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_strc_subStrInfo_isInvalid(&result) ) {
		return 0;
	}
	
	return 1;
	
	xc_err_on_unmg();
	return 0;
}

int xc_strcs_LL_ifContains(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find)
{
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		if( 0 == refp_str2find->ro_len ) {
			break;
		}
		if( 0 == refp_self->ro_len ) {
			break;
		}
		/* --- */
		
		if( NULL == strstr(refp_self->ro_buf, refp_str2find->ro_buf) ) {
			break;
		}
		
		return 1;
	}
	while(0);
	
	return 0;
	
	xc_err_on_unmg();
	return 0;
}

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

int xc_strcs_LL_ifStartsWith(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find)
{
	char* found_str=NULL;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		if(refp_str2find->ro_len > refp_self->ro_len) {
			break;
		}
		if(0 == refp_str2find->ro_len) {
			break;
		}
		
		if(0 == refp_self->ro_len) {
			break;
		}
		
		if(0 != xc_mem_u_cmp_bytes(refp_str2find->ro_len, refp_self->ro_buf, refp_str2find->ro_buf) ) {
			break;
		}
		
		return 1;
	}
	while(0);
	
	return 0;
	
	xc_err_on_unmg();
	return 0;
}

int xc_strcs_LL_ifStartsWithNC(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find)
{
	char* found_str=NULL;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		if(refp_str2find->ro_len > refp_self->ro_len) {
			break;
		}
		if(0 == refp_str2find->ro_len) {
			break;
		}
		
		if(0 == refp_self->ro_len) {
			break;
		}
		
		if( 0 == xc_strc_LL__isSubstrMatchNC(refp_self, 0, refp_str2find ) ) {
			break;
		}
		
		return 1;
	}
	while(0);
	
	return 0;
	
	xc_err_on_unmg();
	return 0;
}

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */


int xc_strcs_LL_ifEndsWith(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find)
{
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		int len_off=0;
		const char* self_bytes=NULL;
		
		if( 0 == refp_str2find->ro_len ) {
			break;
		}
		if( 0 == refp_self->ro_len ) {
			break;
		}
		if(refp_str2find->ro_len > refp_self->ro_len) {
			break;
		}
		
		len_off=(refp_self->ro_len - refp_str2find->ro_len);
		self_bytes=refp_self->ro_buf+len_off;
		
		/* paranoia assert TODO remove */
		if(1)
		{
			if(len_off+refp_str2find->ro_len > refp_self->ro_len) {
				xc_err_term_unmg();
			}
		}
		/* paranoia assert TODO remove: done */
		
		if(0 != memcmp(self_bytes, refp_str2find->ro_buf, refp_str2find->ro_len ) ) {
			break;
		}
		
		return 1;
	}
	while(0);
	
	return 0;
	
	xc_err_on_unmg();
	return 0;
}


int xc_strcs_LL_ifEndsWithNC(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find)
{
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		int len_off=0;
		
		if( 0 == refp_str2find->ro_len ) {
			break;
		}
		if( 0 == refp_self->ro_len ) {
			break;
		}
		if(refp_str2find->ro_len > refp_self->ro_len) {
			break;
		}
		
		len_off=(refp_self->ro_len - refp_str2find->ro_len);
		
		/* paranoia assert TODO remove */
		if(1)
		{
			if(len_off+refp_str2find->ro_len > refp_self->ro_len) {
				xc_err_term_unmg();
			}
		}
		/* paranoia assert TODO remove: done */
		
		if(0 == xc_strc_LL__isSubstrMatchNC(refp_self, len_off, refp_str2find) ) {
			break;
		}
		
		return 1;
	}
	while(0);
	
	return 0;
	
	xc_err_on_unmg();
	return 0;
}

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */


int xc_strcs_LL_findNext(const xc_strcRO_t* refp_self, const int start_off, const xc_strcRO_t* refp_str2find, xc_strc_subStrInfo_t* refp_result)
{
	char* found_str=NULL;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	if( start_off<0) {
		xc_err_term_unmg();
	}
	if( start_off>=refp_self->ro_len) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		if( 0 == refp_str2find->ro_len ) {
			break;
		}
		if( 0 == refp_self->ro_len ) {
			break;
		}
		/* --- */
		
		/* own implementation: */
		/* no mplementation of strcasestr available */
		if(1) 
		{
			int occurence_off=0;
			int possible_occurences=0;
			
			if( refp_str2find->ro_len > refp_self->ro_len ) {
				break;
			}
	
			possible_occurences=xc_strcs_LL_POSSIBLE_OCCURENCES_NUMBER_FOR_SEARCH_FROMOFF(refp_self->ro_len, start_off, refp_str2find->ro_len);
			
			if(possible_occurences<0) {
				break;
			}
			
			for( occurence_off=0; occurence_off<possible_occurences; xc_INC(occurence_off) )
			{
				const int cur_off=occurence_off+start_off;
				const char* self_bytes=refp_self->ro_buf+cur_off;
				const char* checked_bytes=refp_str2find->ro_buf;
				const size_t checked_len=refp_str2find->ro_len;
				
				if( 0 == memcmp( (const void*)self_bytes, (const void*)checked_bytes, checked_len) ) {
					
					refp_result->off=cur_off;
					refp_result->len=refp_str2find->ro_len;
					
					return 0;
				}
				else {
					continue;
				}
			}
		}
		/* own implementation: done */
		
	}
	while(0);
	
	if(1) {
		refp_result->len=-1;
		refp_result->off=-1;
	}
	
	return 0;
	
	xc_err_on_unmg();
	if(refp_result) {
		refp_result->len=-1;
		refp_result->off=-1;
	}
	return -1;
}


int xc_strcs_LL_findNextNC(const xc_strcRO_t* refp_self, const int start_off, const xc_strcRO_t* refp_str2find, xc_strc_subStrInfo_t* refp_result)
{
	char* found_str=NULL;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( start_off<0) {
		xc_err_term_unmg();
	}
	if( start_off>=refp_self->ro_len) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		if( 0 == refp_str2find->ro_len ) {
			break;
		}
		if( 0 == refp_self->ro_len ) {
			break;
		}
		/* --- */
		
		/* own implementation: */
		/* no mplementation of strcasestr available */
		if(1) 
		{
			int occurence_off=0;
			int possible_occurences=0;
			
			if( refp_str2find->ro_len > refp_self->ro_len ) {
				break;
			}
	
			possible_occurences=xc_strcs_LL_POSSIBLE_OCCURENCES_NUMBER_FOR_SEARCH_FROMOFF(refp_self->ro_len, start_off, refp_str2find->ro_len);
			
			for( occurence_off=0; occurence_off<possible_occurences; xc_INC(occurence_off) )
			{
				const int  cur_off=occurence_off+start_off;
				if( 0 != xc_strc_LL__isSubstrMatchNC(refp_self, cur_off, refp_str2find) ) {
					refp_result->off=cur_off;
					refp_result->len=refp_str2find->ro_len;
					
					return 0;
				}
				else {
					continue;
				}
			}
		}
		/* own implementation: done */
		
	}
	while(0);
	
	if(1) {
		refp_result->len=-1;
		refp_result->off=-1;
	}
	
	return 0;
	
	xc_err_on_unmg();
	if(refp_result) {
		refp_result->len=-1;
		refp_result->off=-1;
	}
	return -1;
}


/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

int xc_strc_LL_substrInfo_isValid(const int target_length, const xc_strc_subStrInfo_t* refp_substrInfo)
{
	int target_total_len=0;
	xc_err_decl();
	/* --- */
	
	if(target_length<0) {
		xc_err_term_unmg();
	}
	if(NULL==refp_substrInfo) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != xc_strc_subStrInfo_isInvalid(refp_substrInfo) ) {
		xc_err_term_unmg();
	}
	/* --- */ 
	
	if(1)
	{
		xc_si_int_t tmp_int={0};
		
		xc_si_int_sets_intp(&tmp_int, &refp_substrInfo->len);
		xc_si_int_adds_intp(&tmp_int, &refp_substrInfo->off);
		
		if(xc_si_isError(tmp_int) ) {
			xc_err_term_unmg();
		}
		
		target_total_len=xc_si_val(tmp_int);
	}
	
	do
	{
		if(target_length < target_total_len) {
			xc_err_term_unmg();
		}
		
		return 1;
	}
	while(0);
	
	return 0;
	
	xc_err_on_unmg();
	return 0;
}

static int xc_strc_LL_substrInfo_isValidWildcardLength(const int target_length, const xc_strc_subStrInfo_t* refp_substrInfo)
{
	int target_total_len=0;
	xc_err_decl();
	/* --- */
	
	if(target_length<0) {
		xc_err_term_unmg();
	}
	if(NULL==refp_substrInfo) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != xc_strc_subStrInfo_isInvalid_wildcardLength(refp_substrInfo) ) {
		xc_err_term_unmg();
	}
	
	if( refp_substrInfo->off >= target_length && 0 != refp_substrInfo->off ) {
		xc_err_term_unmg();
	}
	
	
	/* --- */
	
	if(1)
	{
		if(refp_substrInfo->len<0) {
			if( 0 != xc_str_LL_calculate_substr_len(target_length, refp_substrInfo, &target_total_len) ) {
				xc_err_term_unmg();
			}
		}
		else {
			xc_si_int_t tmp_int={0};
			
			xc_si_int_sets_intp(&tmp_int, &refp_substrInfo->off);
			xc_si_int_adds_intp(&tmp_int, &refp_substrInfo->len);
			
			if(xc_si_isError(tmp_int) ) {
				xc_err_term_unmg();
			}
			
			target_total_len=xc_si_val(tmp_int);
		}
		
	}
	
	do
	{
		if(target_length < target_total_len) {
			xc_err_term_unmg();
		}
		
		return 1;
	}
	while(0);
	
	return 0;
	
	xc_err_on_unmg();
	return 0;
}

#if 0

int xc_strc_LL_substr(const xc_strcRO_t* refp_self, const xc_strc_subStrInfo_t* refp_substrInfo, xc_strcRW_t* refp_result)
{
	const char* src_bytes=NULL;
	size_t tmp_capacity=0;
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_substrInfo) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != xc_strcRO_isInvalid(refp_self) ) {
		xc_err_term_unmg();
	}
	if( 0 != xc_strc_subStrInfo_isInvalid(refp_substrInfo) ) {
		xc_err_term_unmg();
	}
	/* --- */

	if( 0 != xc_strc_allocEmpty_fixedSize(refp_substrInfo->len, refp_result, &tmp_capacity) ) {
		xc_err_term_unmg();
	}
	
	src_bytes=refp_self->ro_buf+refp_substrInfo->off;
	
	memcpy( (void*)refp_result->rw_buf, src_bytes, xc_si_UNCHECKED_INT2UINT(refp_substrInfo->len) );
	refp_result->rw_len=refp_substrInfo->len;
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

#endif

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */


static int xc_str_LL_calculate_substr_len(const int target_len, const xc_strc_subStrInfo_t* refp_info, int* result_len)
{
	int tmp_len=0;
	
	if(refp_info->len<0) 
	{
		if(0 == target_len) {
			tmp_len=0;
		}
		else {
			tmp_len=target_len-refp_info->off;
		}
	}
	else {
		tmp_len= refp_info->len;
	}
	
	*result_len=tmp_len;
	
	return 0;
}


int xc_strcs_LL_init_substr(const xc_strcRO_t* refp_self, const xc_strc_subStrInfo_t* refp_info, xc_strcRW_t* refp_result, size_t* result_capacity)
{
	size_t tmp_capacity=0;
	int used_len=0;
	const char* src_bytes=NULL;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_info) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	if(NULL==result_capacity) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( 0 != xc_strc_subStrInfo_isInvalid_wildcardLength(refp_info) ) {
		xc_err_term_unmg();
	}
	if( 0 == xc_strc_LL_substrInfo_isValidWildcardLength(refp_self->ro_len, refp_info) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	*result_capacity=0;
	
	xc_str_LL_calculate_substr_len(refp_self->ro_len, refp_info, &used_len);
	
	if( 0 != xc_strc_allocEmpty_fixedSize(used_len,  refp_result, &tmp_capacity) ) {
		xc_err_term_unmg();
	}
	
	src_bytes=refp_self->ro_buf+refp_info->off;
	xc_mem_cp_obj_array(char, used_len, refp_result->rw_buf, src_bytes);
	
	*result_capacity=tmp_capacity;
	
	return 0;
	
	xc_err_on_unmg();
	return -1;
}


/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#if 0

int xc_strcs_LL_findAny(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find, xc_strc_subStrInfo_t* refp_result)
{
	char* found_str=NULL;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		if( 0 == refp_str2find->ro_len ) {
			break;
		}
		if( 0 == refp_self->ro_len ) {
			break;
		}
		/* --- */
		
		/* own implementation: */
		/* no mplementation of strcasestr available */
		if(1) 
		{
			int occurence_off=0;
			int possible_occurences=0;
			
			if( refp_str2find->ro_len > refp_self->ro_len ) {
				break;
			}
	
			possible_occurences=xc_strcs_LL_POSSIBLE_OCCURENCES_NUMBER_FOR_SEARCH(refp_self->ro_len, refp_str2find->ro_len);
			
			for( occurence_off=0; occurence_off<possible_occurences; xc_INC(occurence_off) )
			{
				const char* self_bytes=refp_self->ro_buf+occurence_off;
				const char* checked_bytes=refp_str2find->ro_buf;
				const size_t checkero_len=refp_str2find->ro_len;
				
				if( 0 == memcmp( (const void*)self_bytes, (const void*)checked_bytes, checkero_len) ) {
					
					refp_result->off=occurence_off;
					refp_result->len=refp_str2find->ro_len;
					
					return 0;
				}
				else {
					continue;
				}
			}
		}
		/* own implementation: done */
		
	}
	while(0);
	
	if(1) {
		refp_result->len=-1;
		refp_result->off=-1;
	}
	
	return 0;
	
	xc_err_on_unmg();
	if(refp_result) {
		refp_result->len=-1;
		refp_result->off=-1;
	}
	return 1;
}


int xc_strcs_LL_findAnyNC(const xc_strcRO_t* refp_self, const xc_strcRO_t* refp_str2find, xc_strc_subStrInfo_t* refp_result)
{
	char* found_str=NULL;
	xc_err_decl();
	
	if(NULL==refp_self) {
		xc_err_term_unmg();
	}
	if(NULL==refp_str2find) {
		xc_err_term_unmg();
	}
	if(NULL==refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == refp_self->ro_buf ) {
		xc_err_term_unmg();
	}
	if( NULL == refp_str2find->ro_buf ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	do
	{
		if( 0 == refp_str2find->ro_len ) {
			break;
		}
		if( 0 == refp_self->ro_len ) {
			break;
		}
		/* --- */
		
		/* own implementation: */
		/* no mplementation of strcasestr available */
		if(1) 
		{
			int occurence_off=0;
			int possible_occurences=0;
			
			if( refp_str2find->ro_len > refp_self->ro_len ) {
				break;
			}
	
			possible_occurences=xc_strcs_LL_POSSIBLE_OCCURENCES_NUMBER_FOR_SEARCH(refp_self->ro_len, refp_str2find->ro_len);
			
			for( occurence_off=0; occurence_off<possible_occurences; xc_INC(occurence_off) )
			{
				if( 0 != xc_strc_LL__isSubstrMatchNC(refp_self, occurence_off, refp_str2find) ) {
					refp_result->off=occurence_off;
					refp_result->len=refp_str2find->ro_len;
					
					return 0;
				}
				else {
					continue;
				}
			}
		}
		/* own implementation: done */
		
	}
	while(0);
	
	if(1) {
		refp_result->len=-1;
		refp_result->off=-1;
	}
	
	return 0;
	
	xc_err_on_unmg();
	if(refp_result) {
		refp_result->len=-1;
		refp_result->off=-1;
	}
	return 1;
}

#endif

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */
