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
#include <exception>
#include <stdexcept>
#include <vector>
/* --- */
#include "xcc/common/xcc_err.hpp"
/* --- */
#include "implement_performance_xcvector_s/test_tpl_main_rem___xcvector_ds.hpp"
#include "xcc/test/xcc_test_benchmark.hpp"
/* --- */

int main(int argc, char **argv)
{
	xcc::test::testBenchmark01_result result_rem=xcc::test::testBenchmark01_result();
	xcc_err_decl();
	
	fprintf(stdout, "*** ALL PERFORMANCE TESTS: ***\n");
	
	try
	{
		if(1)
		{
			if(0!=testVectorPerformance_xcVectorDS::test_performance_rem(&result_rem) ) {
				xcc_err_term_unmg();
			}
		}
		
		result_rem.print_summary(stdout);
		result_rem.print_summary_toFilename("./xcvector_s_rem.txt");
	}
	catch(...)
	{
		xcc_err_handle();
		fprintf(stdout, "*** ALL PERFORMANCE TESTS: FAILURE ***\n");
		return 1;
	}
	
	fprintf(stdout, "*** ALL PERFORMANCE TESTS: DONE OK ***\n");
	
	return 0;
	
}
