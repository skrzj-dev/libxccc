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

#include <cstdio>
#include <exception>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cstdlib>
/* --- */
#include "main.hpp"
/* --- */

int main(int argc, char **argv)
{
	xcc_err_decl();
	
	fprintf(stdout, "*** ALL PERFORMANCE TESTS: ***\n");
	
	try
	{
		if(0)
		{
			xcc::test::testBenchmark01_result result_add=xcc::test::testBenchmark01_result();
			
			if( 0 != test_performance_malloc::test_smallAllocations(result_add) ) {
				xcc_err_term_unmg();
			}
			
			result_add.print_summary_toFilename("./test_performance_malloc.txt");
		}
		
		if(0)
		{
			xcc::test::testBenchmark01_result result_add=xcc::test::testBenchmark01_result();
			
			if( 0 != test_performance_chunkedRealloc::test_smallAllocations(result_add) ) {
				xcc_err_term_unmg();
			}
			
			result_add.print_summary_toFilename("./test_performance_chunkrealloc-01.txt");
		}
		
		if(1)
		{
			xcc::test::testBenchmark01_result result_add=xcc::test::testBenchmark01_result();
			
			if( 0 != test_performance_chunkList::test_smallAllocations(result_add) ) {
				xcc_err_term_unmg();
			}
			
			result_add.print_summary_toFilename("./test_performance_chunklist01.txt");
		}
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
