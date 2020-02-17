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

/* --- */
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test_benchmark.hpp"
/* --- */
#include "abstracts_performance/test_tpl_procedures_abstract.hpp"
#include "abstracts_performance/test_tpl_scenario_abstract_add.incl.hpp"
#include "abstracts_performance/test_tpl_scenario_abstract_add_ops.incl.hpp"
/* --- */
/* --- */
#include "intf_stlvector_d/xcvector_stlvector_api.hpp"
#include "intf_stlvector_static/xcvector_stlvector_static_api.hpp"
/* --- */
#include "test_tpl_main_add___stlvector_reserved.hpp"
/* --- */

int testVectorPerformance_stlVectorStatic::test_performance_add(TObjRef<xcc::test::testBenchmark01_result> ref_result)
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
					  std::vector<VectorPerformanceTest::bench_dummy_item_t>
					, xcc_tplTestVector_vectorIntf__stlVector_static< 
						  std::vector<VectorPerformanceTest::bench_dummy_item_t>
						, VectorPerformanceTest::bench_dummy_item_t
						, void* 
					> 
					, VectorPerformanceTest::bench_dummy_item_t
					, VectorPerformanceTest::itemIntf_obj
				>
				("stl vector S add", ref_result) 
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

