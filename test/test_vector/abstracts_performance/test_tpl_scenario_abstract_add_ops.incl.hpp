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

#ifndef _TEST_TPL_SCENARIO_ABSTRACT_ADD_OPS_INCL_HPP_
#define _TEST_TPL_SCENARIO_ABSTRACT_ADD_OPS_INCL_HPP_

#include "xc/common/xc_random.h"
/* --- */
#include "xcc/common/xcc_cpp.hpp"


namespace VectorPerformanceTest_scenario_static
{


template <typename TPL_VECTORTYPE, class TPL_VECTORINTF, typename TPL_ITEMTYPE, class TPL_ITEMINTF>
class VectorPerformanceTest_action__push_from_empty: public xcc::test::testBenchmarkAction_I
{
	xcc::objPtr<TPL_VECTORTYPE> refp_vectObj;
	TPL_VECTORINTF vectorI;
	TPL_ITEMINTF itemI;
	
	public: int operation_init(const size_t operation_max_cnt)
	{
		xcc_err_decl();
		
		try
		{
			refp_vectObj.val( vectorI.alloc_init(  refp_vectObj.val() ) );
			
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			if( 0 != vectorI.init(  refp_vectObj.val(), operation_max_cnt )  ) {
				xcc_err_term_unmg();
			}
			
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}

		return 0;
	}
	
	public: int do_operation(const size_t operation_current_nr)
	{
		TPL_ITEMTYPE itemobj=itemI.itz_retv(operation_current_nr);
		
		return vectorI.push(refp_vectObj.val(), &itemobj);
	}
	
	public: int operation_deinit(void)
	{
		xcc_err_decl();
		
		try
		{
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			vectorI.dealloc( refp_vectObj.val() );
			
			refp_vectObj.val(NULL);
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}

		return 0;
	}
};


template <typename TPL_VECTORTYPE, class TPL_VECTORINTF, typename TPL_ITEMTYPE, class TPL_ITEMINTF>
class VectorPerformanceTest_action__insert_from_empty_at_zero: public xcc::test::testBenchmarkAction_I
{
	xcc::objPtr<TPL_VECTORTYPE> refp_vectObj;
	TPL_VECTORINTF vectorI;
	TPL_ITEMINTF itemI;
	
	public: int operation_init(const size_t operation_max_cnt)
	{
		xcc_err_decl();
		
		try
		{
			refp_vectObj.val( vectorI.alloc_init(  refp_vectObj.val() ) );
			
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			if( 0 != vectorI.init(  refp_vectObj.val(), operation_max_cnt )  ) {
				xcc_err_term_unmg();
			}
			
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}

		return 0;
	}
	
	public: int do_operation(const size_t operation_current_nr)
	{
		TPL_ITEMTYPE itemobj=itemI.itz_retv(operation_current_nr);
		
		return vectorI.insert_idx(refp_vectObj.val(), 0, &itemobj);
	}
	
	public: int operation_deinit(void)
	{
		xcc_err_decl();
		
		try
		{
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			vectorI.dealloc( refp_vectObj.val() );
			
			refp_vectObj.val(NULL);
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}

		return 0;
	}
};


template <typename TPL_VECTORTYPE, class TPL_VECTORINTF, typename TPL_ITEMTYPE, class TPL_ITEMINTF>
class VectorPerformanceTest_action__insert_from_empty_at_last: public xcc::test::testBenchmarkAction_I
{
	xcc::objPtr<TPL_VECTORTYPE> refp_vectObj;
	TPL_VECTORINTF vectorI;
	TPL_ITEMINTF itemI;
	
	public: int operation_init(const size_t operation_max_cnt)
	{
		xcc_err_decl();
		
		try
		{
			refp_vectObj.val( vectorI.alloc_init(  refp_vectObj.val() ) );
			
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			if( 0 != vectorI.init(  refp_vectObj.val(), operation_max_cnt )  ) {
				xcc_err_term_unmg();
			}
			
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}

		return 0;
	}
	
	public: int do_operation(const size_t operation_current_nr)
	{
		TPL_ITEMTYPE itemobj=itemI.itz_retv(operation_current_nr);
		
		xcc::tval<int> length=vectorI.get_length( refp_vectObj.val() );
		
		return vectorI.insert_idx(refp_vectObj.val(), length.val(), &itemobj);
	}
	
	public: int operation_deinit(void)
	{
		xcc_err_decl();
		
		try
		{
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			vectorI.dealloc( refp_vectObj.val() );
			
			refp_vectObj.val(NULL);
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}

		return 0;
	}
};



template <typename TPL_VECTORTYPE, class TPL_VECTORINTF, typename TPL_ITEMTYPE, class TPL_ITEMINTF>
class VectorPerformanceTest_action__insert_from_empty_at_random: public xcc::test::testBenchmarkAction_I
{
	xcc::objPtr<TPL_VECTORTYPE> refp_vectObj;
	TPL_VECTORINTF vectorI;
	TPL_ITEMINTF itemI;
	
	public: int operation_init(const size_t operation_max_cnt)
	{
		xcc_err_decl();
		
		try
		{
			refp_vectObj.val( vectorI.alloc_init(  refp_vectObj.val() ) );
			
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			if( 0 != vectorI.init(  refp_vectObj.val(), operation_max_cnt )  ) {
				xcc_err_term_unmg();
			}
			
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}

		return 0;
	}
	
	public: int do_operation(const size_t operation_current_nr)
	{
		xcc::tval<int> random_idx=0;
		TPL_ITEMTYPE itemobj=itemI.itz_retv(operation_current_nr);
		const xcc::tval<int> length=vectorI.get_length( refp_vectObj.val() );
		
		random_idx=xc_rand_range_int(0, length.val() );
		
		if( random_idx.val() >= length.val() && random_idx.val() != 0 ) { /* additional check to ensure valid idx */
			random_idx--;
		}
		
		return vectorI.insert_idx(refp_vectObj.val(), random_idx.val(), &itemobj);
	}
	
	public: int operation_deinit(void)
	{
		xcc_err_decl();
		
		try
		{
			if( refp_vectObj.isNull() ) {
				xcc_err_term_unmg();
			}
			
			vectorI.dealloc( refp_vectObj.val() );
			
			refp_vectObj.val(NULL);
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}

		return 0;
	}
};


};

#endif
