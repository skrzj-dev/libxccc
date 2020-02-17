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
#include "abstracts_performance/test_tpl_scenario_abstract_rem.incl.hpp"
#include "abstracts_performance/test_tpl_scenario_abstract_rem_ops.incl.hpp"
/* --- */
#include "intf_xcvector_s/_xcvector_ds_api_u.hpp"
#include "intf_xcvector_s/_xcvector_ds_api_s.hpp"
/* --- */
#include "test_tpl_main_rem___xcvector_ds.hpp"
/* --- */


/* --- */

/* --- --- --- --- */

typedef xc_tcVectorS_declt(VectorPerformanceTest::bench_dummy_item_t) big_test_array_int;

int testVectorPerformance_xcVectorDS::test_performance_rem(TObjRef<xcc::test::testBenchmark01_result> ref_result)
{
	xcc_err_decl();
	
	try
	{
		if(ref_result.isNull() ) {
			xcc_err_term_unmg();
		}
		
		if(1)
		{
			if( 0 != VectorPerformanceTest_scenario_abstract::testPerformance_pop_and_remove<
					  big_test_array_int
					, xcc_tplTestVector_vectorIntf__xcVectorDS_s< 
						  big_test_array_int
						, VectorPerformanceTest::bench_dummy_item_t
						, xc_tcVectorS_LL_deref_t 
					> 
					, VectorPerformanceTest::bench_dummy_item_t
					, VectorPerformanceTest::itemIntf_obj
				>
				("xc_vector_S remove/pop", ref_result) 
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
