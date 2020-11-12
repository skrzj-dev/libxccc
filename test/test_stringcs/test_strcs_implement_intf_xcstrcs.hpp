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

#ifndef _TEST_STRINGCS_STATIC_INTF_CSTRD_HPP_
#define _TEST_STRINGCS_STATIC_INTF_CSTRD_HPP_

#include "test_strcs_functional_abstracts.hpp"

#include "test_strcs_internal.hpp"

template<typename TPL_STR_T>
class test_xcStringS_I_cstrd: public test_xcStringS_I_abstract<TPL_STR_T>
{
	
	
	public: test_xcStringS_I_cstrd()
	{
		this->init_fmt=xc_strcs_fromFmt_init;
	}
	
	public: int init_sameObj(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_from_init(refp_self, refp_src);
	}
	
	public: int init_cstr(TPL_STR_T* refp_self, const char* refp_src)
	{
		return xc_strcs_fromCstr_init(refp_self, refp_src);
	}
	
	public: int cmpEq_sameObj(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_eq(refp_self, refp_src);
	}
	
	public: int cmpEq_cstr(TPL_STR_T* refp_self, const char* refp_src)
	{
		return xc_strcs_eq_cstr(refp_self, refp_src);
	}


	public: int cmpEq_sameObj_NOCASE(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_eqNC(refp_self, refp_src);
	}
	
	public: int cmpEq_cstr_NOCASE(TPL_STR_T* refp_self, const char* refp_src)
	{
		return xc_strcs_eqNC_cstr(refp_self, refp_src);
	}

	
	public: int deinit(TPL_STR_T* refp_self)
	{
		return xc_strcs_deinit(refp_self);
	}
	
	public: int get_length(const TPL_STR_T* refp_self)
	{
		return xc_strcs_get_length(refp_self);
	}
	
	public: size_t get_capacity(const TPL_STR_T* refp_self)
	{
		return xc_strcs_get_capacity(refp_self);
	}
	
	public: const char* cstr(const TPL_STR_T* refp_self)
	{
		return xc_strcs_get_cstr(refp_self);
	}
	
	public: int TEST_produceUninitNotZero(TPL_STR_T* refp_target)
	{
		if(NULL == refp_target) {
			return 1;
		}
		
		memset(refp_target, 0x99, sizeof(TPL_STR_T) );
		return 0;
	}
	
	public: int contains_obj(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_ifContains(refp_self, refp_src);
	}
	
	public: int containsNC_obj(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_ifContainsNC(refp_self, refp_src);
	}
	
	public: int contains_cstr(TPL_STR_T* refp_self, const char* cstr2)
	{
		return xc_strcs_ifContains_cstr(refp_self, cstr2);
	}
	
	public: int containsNC_cstr(TPL_STR_T* refp_self, const char* cstr2)
	{
		return xc_strcs_ifContainsNC_cstr(refp_self, cstr2);
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int startsWith(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_ifStartsWith(refp_self, refp_src);
	}
	
	public: int startsWithNC(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_ifStartsWithNC(refp_self, refp_src);
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */

	public: int ifEndsWith(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_ifEndsWith(refp_self, refp_src);
	}
	
	public: int ifEndsWithNC(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)
	{
		return xc_strcs_ifEndsWithNC(refp_self, refp_src);
	}
	
	public: int ifEndsWith_cstr(TPL_STR_T* refp_self, const char* refp_src)
	{
		return xc_strcs_ifEndsWith_cstr(refp_self, refp_src);
	}
	
	public: int ifEndsWithNC_cstr(TPL_STR_T* refp_self, const char* refp_src)
	{
		return xc_strcs_ifEndsWithNC_cstr(refp_self, refp_src);
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */

	public: int findNext(TPL_STR_T* refp_self, const int off, const TPL_STR_T* refp_src, test_xcStringS_I_findResult* result)
	{
		int retv=0;
		xc_strc_subStrInfo_t tmp={0};
		xc_strc_subStrInfo_t* refp_tmp=NULL;
		
		if(NULL == result) {
			refp_tmp=NULL;
		}
		else {
			refp_tmp=&tmp;
			retv=xc_strcs_findNext(refp_self, off, refp_src, refp_tmp);
		}
		
		if(NULL!=result  && NULL!=refp_tmp) {
			result->len=refp_tmp->len;
			result->off=refp_tmp->off;
		}
		
		return retv;
	}
	
	public: int findNextNC(TPL_STR_T* refp_self, const int off, const TPL_STR_T* refp_src, test_xcStringS_I_findResult* result)
	{
		int retv=0;
		xc_strc_subStrInfo_t tmp={0};
		xc_strc_subStrInfo_t* refp_tmp=NULL;
		
		if(NULL == result) {
			refp_tmp=NULL;
		}
		else {
			refp_tmp=&tmp;
		}
		
		retv=xc_strcs_findNextNC(refp_self, off, refp_src, refp_tmp);
		
		if(NULL!=result  && NULL!=refp_tmp) {
			result->len=refp_tmp->len;
			result->off=refp_tmp->off;
		}
		
		return retv;
	}
	
	
	public: int findNext_cstr(TPL_STR_T* refp_self, const int off, const char* refp_src, test_xcStringS_I_findResult* result)
	{
		int retv=0;
		xc_strc_subStrInfo_t tmp={0};
		xc_strc_subStrInfo_t* refp_tmp=NULL;
		
		if(NULL == result) {
			refp_tmp=NULL;
		}
		else {
			refp_tmp=&tmp;
		}
		
		retv=xc_strcs_findNext_cstr(refp_self, off, refp_src, refp_tmp);
		
		if(NULL!=result  && NULL!=refp_tmp) {
			result->len=refp_tmp->len;
			result->off=refp_tmp->off;
		}
		
		return retv;
	}
	
	public: int findNextNC_cstr(TPL_STR_T* refp_self, const int off, const char* refp_src, test_xcStringS_I_findResult* result)
	{
		int retv=0;
		xc_strc_subStrInfo_t tmp={0};
		xc_strc_subStrInfo_t* refp_tmp=NULL;
		
		if(NULL == result) {
			refp_tmp=NULL;
		}
		else {
			refp_tmp=&tmp;
		}
		
		retv=xc_strcs_findNextNC_cstr(refp_self, off, refp_src, refp_tmp);
		
		if(NULL!=result  && NULL!=refp_tmp) {
			result->len=refp_tmp->len;
			result->off=refp_tmp->off;
		}
		
		return retv;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int substr_init(TPL_STR_T* target, test_xcStringS_I_findResult* info, TPL_STR_T* result)
	{
		int retv=0;
		xc_strc_subStrInfo_t tmp={0};
		xc_strc_subStrInfo_t* refp_tmp=NULL;
		
		if(NULL == result) {
			refp_tmp=NULL;
		}
		else {
			refp_tmp=&tmp;
			refp_tmp->len=info->len;
			refp_tmp->off=info->off;
		}
		
		retv=xc_strcs_substr_init(target, refp_tmp, result);
		
		return retv;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */

};

#endif
