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
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "test_allocator_seq_chunk/test_xc_alc.hpp"
#include "test_allocator_seq_chunk/test_allocatorctl_seq_chunk.hpp"

/* --- */


int main(int argc, char **argv)
{
	xcc_test2_procedure testResult_alc_shift_right=xcc_test2_procedure();
	xcc_test2_procedure testResult_alc_length_to_chunk=xcc_test2_procedure();
	xcc_test2_procedure testResult_test_allocator=xcc_test2_procedure();
	xcc_err_decl();
	
	try
	{
		if(0 != test_alc_shift_right( xcc_test2_param_public_result(&testResult_alc_shift_right) ) ) {
			testResult_alc_shift_right.print_summary("test_alc_shift_right");
			xcc_err_term_unmg();
		}
		
		if(0 != test_allocator_length_to_chunk( xcc_test2_param_public_result(&testResult_alc_length_to_chunk) ) ) {
			testResult_alc_length_to_chunk.print_summary("test_allocator_length_to_chunk");
			xcc_err_term_unmg();
		}
		
		if(0 != test_allocator( xcc_test2_param_public_result(&testResult_test_allocator) ) ) {
			testResult_test_allocator.print_summary("test_allocator");
			xcc_err_term_unmg();
		}
		
		testResult_alc_shift_right.print_summary("test_alc_shift_right");
		testResult_alc_length_to_chunk.print_summary("test_allocator_length_to_chunk");
		testResult_test_allocator.print_summary("test_allocator");
		
	}
	catch(...) {
		xcc_err_handle();
		return 1;
	}
	
	fprintf(stdout, "*** ALL TESTS DONE OK ***\n");
	
	return 0;
}
