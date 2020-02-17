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

/* --- --- --- --- */

#include "xcc/common/xcc_err.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_tpl_main___hlp.hpp"
#include "test_tpl_procedures_abstract.hpp"
#include "test_tpl_scenario_abstract_add_ops.incl.hpp"
/* --- */


namespace VectorPerformanceTest_scenario_abstract
{


template <typename TPL_VECTORTYPE, class TPL_VECTORINTF, typename TPL_ITEMTYPE, class TPL_ITEMINTF>
int testPerformance_push_and_insert(std::string test_label, TObjRef<xcc::test::testBenchmark01_result> ref_result)
{
	xcc_err_decl();
	
	try
	{
		xcc::test::testBenchmark01_result test_result=xcc::test::testBenchmark01_result();
		xcc::test::testBenchmark01_result test_push_from_empty_result=xcc::test::testBenchmark01_result();
		xcc::test::testBenchmark01_result test_insert_from_empty_at_zero_result=xcc::test::testBenchmark01_result();
		xcc::test::testBenchmark01_result test_insert_from_empty_at_random_result=xcc::test::testBenchmark01_result();
		xcc::test::testBenchmark01_result test_insert_from_empty_at_last_result=xcc::test::testBenchmark01_result();
		
		if(ref_result.isNull()){
			xcc_err_term_unmg();
		}
		
		if(1)
		{
			VectorPerformanceTest_scenario_static::VectorPerformanceTest_action__push_from_empty<
				  TPL_VECTORTYPE
				, TPL_VECTORINTF
				, TPL_ITEMTYPE
				, TPL_ITEMINTF
			> test_push_from_empty;
			
			if( 0 != xc_svector_test_performance_abstract_power2short_to64K(
					  "[power2short] push from empty to max"
					, &test_push_from_empty
					, &test_push_from_empty_result
				) 
			) {
				xcc_err_term_unmg();
			}
		
		}
		
		if(1)
		{
			VectorPerformanceTest_scenario_static::VectorPerformanceTest_action__insert_from_empty_at_random<
				  TPL_VECTORTYPE
				, TPL_VECTORINTF
				, TPL_ITEMTYPE
				, TPL_ITEMINTF
			> test_insert_from_empty_at_random;
			
			if( 0 != xc_svector_test_performance_abstract_power2short_to64K(
					  "[power2short] insert from empty to max at random idx"
					, &test_insert_from_empty_at_random
					, &test_insert_from_empty_at_random_result
				) 
			) {
				xcc_err_term_unmg();
			}
			
		}
		
		if(1)
		{
			VectorPerformanceTest_scenario_static::VectorPerformanceTest_action__insert_from_empty_at_zero<
				  TPL_VECTORTYPE
				, TPL_VECTORINTF
				, TPL_ITEMTYPE
				, TPL_ITEMINTF
			> test_insert_from_empty_at_zero;

			if( 0 != xc_svector_test_performance_abstract_power2short_to64K(
					  "[power2short] insert from empty to max at zero idx"
					, &test_insert_from_empty_at_zero
					, &test_insert_from_empty_at_zero_result
				) 
			) {
				xcc_err_term_unmg();
			}
			
		}
		
		if(1)
		{
			VectorPerformanceTest_scenario_static::VectorPerformanceTest_action__insert_from_empty_at_last<
				  TPL_VECTORTYPE
				, TPL_VECTORINTF
				, TPL_ITEMTYPE
				, TPL_ITEMINTF
			> test_insert_from_empty_at_last;
			
			if( 0 != xc_svector_test_performance_abstract_power2short_to64K(
					  "[power2short] insert from empty to max at last idx"
					, &test_insert_from_empty_at_last
					, &test_insert_from_empty_at_last_result
				) 
			) {
				xcc_err_term_unmg();
			}
			
		}
		
		if(0)
		{
			if( 0 != test_push_from_empty_result.print_summary(stdout) ) {
				xcc_err_term_unmg();
			}
			if( 0 != test_insert_from_empty_at_zero_result.print_summary(stdout) ) {
				xcc_err_term_unmg();
			}
			if( 0 != test_insert_from_empty_at_random_result.print_summary(stdout) ) {
				xcc_err_term_unmg();
			}
			if( 0 != test_insert_from_empty_at_last_result.print_summary(stdout) ) {
				xcc_err_term_unmg();
			}
		}
		
		if(1)
		{
			if( 0 != test_result.result_append_from( &test_push_from_empty_result) ) {
				xcc_err_term_unmg();
			}
			if( 0 != test_result.result_append_from( &test_insert_from_empty_at_zero_result) ) {
				xcc_err_term_unmg();
			}
			if( 0 != test_result.result_append_from( &test_insert_from_empty_at_random_result) ) {
				xcc_err_term_unmg();
			}
			if( 0 != test_result.result_append_from( &test_insert_from_empty_at_last_result) ) {
				xcc_err_term_unmg();
			}
			
			ref_result.ref()=test_result;
			ref_result.ref().test_label_set(test_label);
		}
		
		return 0;
	}
	catch(...)
	{
		xcc_err_handle();
		return 1;
	}

}

};
