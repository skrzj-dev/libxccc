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
#include "test_allocator_seq_chunk/test_xc_tc.hpp"
/* --- */

int main(int argc, char **argv)
{
	xcc_err_decl();
	
	try
	{
		xcc_test2_wrapper testrun_tc_overflow=xcc_test2_wrapper("xc_tc_overflow", std::function<int(xcc_test2_testParamObj_t)>(test_tc_overflow) );
		
		testrun_tc_overflow.run_throwErr();
		
		testrun_tc_overflow.summary();
		
	}
	catch(...)
	{
		return 1;
	}
	
	return 0;
}
