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
#include "test_strcs.hpp"

/* --- */

int main(int argc, char **argv)
{
	xcc_test2_procedure testResult_s=xcc_test2_procedure();
	xcc_err_decl();
	
	try
	{
		if(0 != test_xcStringS_all( xcc_test2_param_public_result(&testResult_s) ) ) {
			testResult_s.print_summary("TODO");
			xcc_err_term_unmg();
		}
		
		testResult_s.print_summary("TODO");
		
	}
	catch(...) {
		xcc_err_handle();
		return 1;
	}
	
	fprintf(stdout, "*** ALL TESTS DONE OK ***\n");
	
	return 0;
}
