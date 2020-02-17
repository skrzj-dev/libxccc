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

#ifndef _XCC_VECTOR_TEST_TPL___PARAM_EVALUATION_CHECK_HPP_
#define _XCC_VECTOR_TEST_TPL___PARAM_EVALUATION_CHECK_HPP_

template<typename TPL_OBJ_TYPE>
class test_ObjReference_Refcounter
{
	public: test_ObjReference_Refcounter() noexcept
	{
		this->obj_psh=NULL;
		this->refp_cnter=0;
	}
	
	public: ~test_ObjReference_Refcounter() noexcept
	{
	}
	
	public: int init(TPL_OBJ_TYPE* psh_obj) noexcept
	{
		this->obj_psh=psh_obj;
		this->refp_cnter=0;
		
		return 0;
	}
	
	public: TPL_OBJ_TYPE* get_refp() noexcept
	{
		this->refp_cnter++;
		
		return this->obj_psh;
	}
	
	public: TPL_OBJ_TYPE get_val() noexcept
	{
		this->refp_cnter++;
		
		return *this->obj_psh;
	}
	
	public: int get_cnter() noexcept
	{
		return this->refp_cnter;
	}
	
	private: TPL_OBJ_TYPE* obj_psh;
	private: unsigned int refp_cnter;
	
};

#endif
