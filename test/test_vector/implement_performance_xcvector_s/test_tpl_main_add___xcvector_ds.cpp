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

#include <limits.h>
/* --- */
#include "xcc/test/xcc_test_benchmark.hpp"
/* --- */
#include "abstracts_performance/test_tpl_procedures_abstract.hpp"
#include "abstracts_performance/test_tpl_scenario_abstract_add.incl.hpp"
#include "abstracts_performance/test_tpl_scenario_abstract_add_ops.incl.hpp"
/* --- */
#include "intf_xcvector_s/xcvector_ds.hpp"
/* --- */
#include "test_tpl_main_add___xcvector_ds.hpp"
/* --- */


/* --- */
/*
#define xc_csvector_test_intmax_hardcoded (2147483647)
#define xc_csvector_test_1m (1000000)

typedef xc_tcVectorT_declt(int, 32000) test_array_int_32k_t;

typedef xc_tcVectorT_declt(int, 64000) big_test_array_64k_t;
typedef xc_tcVectorT_declt(int, 128000) big_test_array_128k_t;
typedef xc_tcVectorT_declt(int, 256000) big_test_array_256k_t;
typedef xc_tcVectorT_declt(int, 512000) big_test_array_512k_t;
typedef xc_tcVectorT_declt(int, 1000000) big_test_array_1000k_t;
*/
/* --- --- --- --- */

typedef xc_tcVectorS_declt(VectorPerformanceTest::bench_dummy_item_t) big_test_array_int;

int testVectorPerformance_xcVectorDS::test_performance_add(TObjRef<xcc::test::testBenchmark01_result> ref_result)
{
	xcc_err_decl();
	
	try
	{
		if(ref_result.isNull() ) {
			xcc_err_term_unmg();
		}
		
		if(1)
		{
			if( 0 != VectorPerformanceTest_scenario_abstract::testPerformance_push_and_insert<
					  big_test_array_int
					, testXcVectorS::intf_api_s< 
						  big_test_array_int
						, VectorPerformanceTest::bench_dummy_item_t
						, xc_tcVectorS_LL_deref_t 
					> 
					, VectorPerformanceTest::bench_dummy_item_t
					, VectorPerformanceTest::itemIntf_obj
				>
				("xc_vector_S add", ref_result) 
			)
			{
				xcc_err_term_unmg();
			}
		}
		
		return 0;
	}
	catch(...)
	{
		xcc_err_handle();
		return 1;
	}
}
