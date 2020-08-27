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
#include "implement_functional_xcpool_t/xcpool_ts_main.hpp"
/* --- */

int main(int argc, char **argv)
{
	xcc_err_decl();
	
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
	
	fprintf(stdout, "*** ALL TESTS DONE OK ***\n");
	
	return 0;
}
