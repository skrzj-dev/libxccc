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

#ifndef _TEST_TPL_SCENARIO_ABSTRACT_REM_OPS_INCL_HPP_
#define _TEST_TPL_SCENARIO_ABSTRACT_REM_OPS_INCL_HPP_

#include "xc/common/xc_random.h"
/* --- */
#include "xcc/common/xcc_cpp.hpp"


namespace VectorPerformanceTest_scenario_static
{


template <typename TPL_VECTORTYPE, class TPL_VECTORINTF, typename TPL_ITEMTYPE, class TPL_ITEMINTF>
class VectorPerformanceTest_action__pop_from_max: public xcc::test::testBenchmarkAction_I
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
			
			TVal<size_t> operation_current_nr=0;
			
			for(operation_current_nr=0; operation_current_nr.val() < operation_max_cnt; operation_current_nr++)
			{
				TPL_ITEMTYPE itemobj=itemI.itz_retv(operation_current_nr.val() );
				
				if( 0 != vectorI.push(refp_vectObj.val(), &itemobj) ) {
					xcc_err_term_unmg();
				}
			}
			
			if( operation_max_cnt != vectorI.get_capacity( refp_vectObj.val() ) ) {
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
		return vectorI.pop( refp_vectObj.val() );
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
class VectorPerformanceTest_action__rem_from_max_at_zero: public xcc::test::testBenchmarkAction_I
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
			
			TVal<int> operation_current_nr=0;
			
			for(operation_current_nr=0; operation_current_nr.val() < operation_max_cnt; operation_current_nr++)
			{
				TPL_ITEMTYPE itemobj=itemI.itz_retv(operation_current_nr.val() );
				
				if( 0 != vectorI.push(refp_vectObj.val(), &itemobj) ) {
					xcc_err_term_unmg();
				}
			}
			
			if( operation_max_cnt != vectorI.get_capacity( refp_vectObj.val() ) ) {
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
		return vectorI.remove_idx(refp_vectObj.val(), 0);
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
class VectorPerformanceTest_action__rem_from_max_at_last: public xcc::test::testBenchmarkAction_I
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
			
			TVal<int> operation_current_nr=0;
			
			for(operation_current_nr=0; operation_current_nr.val() < operation_max_cnt; operation_current_nr++)
			{
				TPL_ITEMTYPE itemobj=itemI.itz_retv(operation_current_nr.val() );
				
				if( 0 != vectorI.push(refp_vectObj.val(), &itemobj) ) {
					xcc_err_term_unmg();
				}
			}
			
			if( operation_max_cnt != vectorI.get_capacity( refp_vectObj.val() ) ) {
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
		TVal<int> length=vectorI.get_length( refp_vectObj.val() )-1;
		
		return vectorI.remove_idx(refp_vectObj.val(), length.val() );
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
class VectorPerformanceTest_action__rem_from_max_at_random: public xcc::test::testBenchmarkAction_I
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
			
			TVal<size_t> operation_current_nr=0;
			
			for(operation_current_nr=0; operation_current_nr.val() < operation_max_cnt; operation_current_nr++)
			{
				TPL_ITEMTYPE itemobj=itemI.itz_retv(operation_current_nr.val() );
				
				if( 0 != vectorI.push(refp_vectObj.val(), &itemobj) ) {
					xcc_err_term_unmg();
				}
			}
			
			if( operation_max_cnt != vectorI.get_capacity( refp_vectObj.val() ) ) {
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
		TVal<int> random_idx=0;
		const TVal<int> length=vectorI.get_length( refp_vectObj.val() );
		
		random_idx=xc_rand_range_int(0, length.val() );
		
		if( random_idx.val() >= length.val() && random_idx.val() != 0 ) { /* additional check to ensure valid idx */
			random_idx--;
		}
		
		return vectorI.remove_idx(refp_vectObj.val(), random_idx.val() );
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
