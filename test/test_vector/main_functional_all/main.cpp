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
#include <functional>
/* --- */
#include "xcc/common/xcc_err.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "test_allocator_seq_chunk/test_xc_alc.hpp"
#include "test_allocator_seq_chunk/test_xc_tc.hpp"
#include "test_allocator_seq_chunk/test_allocatorctl_seq_chunk.hpp"
/* --- */
#include "implement_functional_xcvector_d/xcvector_d_main.hpp"
/* --- */
#include "implement_functional_xcvector_s/xcvector_ds_main.hpp"
/* --- */
#include "implement_functional_xcvector_t/xcvector_st_main.hpp"
/* --- */
#include "implement_functional_xcpool_s/xcpool_ds_main.hpp"
/* --- */


int main(int argc, char **argv)
{
	xcc_err_decl();
	
	try
	{
		
		try
		{
			xcc_test2_wrapper testrun_tc_overflow=xcc_test2_wrapper("xc_tc_overflow", std::function<int(xcc_test2_testParamObj_t)>(test_tc_overflow) );
			xcc_test2_wrapper testrun_alc_shift_right=xcc_test2_wrapper("test_alc_shift_right", std::function<int(xcc_test2_testParamObj_t)>(test_alc_shift_right) );
			xcc_test2_wrapper testrun_allocator_length_to_chunk=xcc_test2_wrapper("test_allocator_length_to_chunk", std::function<int(xcc_test2_testParamObj_t)>(test_allocator_length_to_chunk) );
			xcc_test2_wrapper testrun_allocator=xcc_test2_wrapper("test_allocator", std::function<int(xcc_test2_testParamObj_t)>(test_allocator) );
			
			testrun_tc_overflow.run_throwErr();
			testrun_alc_shift_right.run_throwErr();
			testrun_allocator_length_to_chunk.run_throwErr();
			testrun_allocator.run_throwErr();

			testrun_tc_overflow.summary();
			testrun_alc_shift_right.summary();
			testrun_allocator_length_to_chunk.summary();
			testrun_allocator.summary();
			
		}
		catch(...)
		{
			xcc_err_term_unmg();
			return 1;
		}
		
		try
		{
			if(1)
			{
				try
				{
					if(0!=test_xcPoolDS_x() ) {
						xcc_err_term_unmg();
					}
				}
				catch(...) {
					xcc_err_handle();
					return 1;
				}
			}
			
			if(0)
			{
				try
				{
					if(0)
					{
						if(0!=test_seqST_x() ) {
							xcc_err_term_unmg();
						}
					}
					if(0)
					{
						if(0!=test_seqD_x() ) {
							xcc_err_term_unmg();
						}
					}
					if(1) 
					{
						if(0!=test_seqDS_x() ) {
							xcc_err_term_unmg();
						}
					}
				}
				catch(...) {
					xcc_err_handle();
					return 1;
				}
			}
			
		}
		catch(...)
		{
			xcc_err_term_unmg();
			return 1;
		}

		fprintf(stdout, "*** ALL TESTS DONE OK ***\n");
		
		return 0;
	}
	catch(...)
	{
		xcc_err_handle();
		return 1;
	}
}
