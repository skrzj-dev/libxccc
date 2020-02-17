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
#include "xc/common/xc_mem.h"
#include "xc/common/xc_tc_common.h"
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "test_xc_tc.hpp"
/* --- */

int test_tc_overflow(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("test_tc_overflow");
	
	do
	{
		xcc_test2_case("[e.1.1]");
		
		if(1)
		{
			xcc_test2_expect( 0 != xc_tc_calc_overflow(0, 0, NULL) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("[e.1.2]");
		
		if(1)
		{
			xcc_test2_expect( 0 != xc_tc_calc_overflow(0, 0, NULL) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("[e.1.3]");
		
		if(1)
		{
			xcc_test2_expect( 0 != xc_tc_calc_overflow(1, 2, NULL) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("[1.1.1]-[zero dest == src]");
		
		if(1)
		{
			size_t result=0;
			
			xcc_test2_expect( 0 == xc_tc_calc_overflow(0, 0, &result) );
			xcc_test2_expect_eq_t(size_t, 0, result );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("[1.1.1]-[nonzero dest == nonzero src]");
		
		if(1)
		{
			size_t result=0;
			
			xcc_test2_expect( 0 == xc_tc_calc_overflow(1000, 1000, &result) );
			xcc_test2_expect_eq_t(size_t, 0, result );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("[1.1.1]-[zero dest < nonzero src]");
		
		if(1)
		{
			size_t result=0;
			
			xcc_test2_expect( 0 == xc_tc_calc_overflow(0, 1000, &result) );
			xcc_test2_expect_eq_t(size_t, 1000, result );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("[1.1.1]-[nonzero dest < nonzero src]");
		
		if(1)
		{
			size_t result=0;
			
			xcc_test2_expect( 0 == xc_tc_calc_overflow(55, 100, &result) );
			xcc_test2_expect_eq_t(size_t, 45, result );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("[1.1.1]-[nonzero dest > zero src]");
		
		if(1)
		{
			size_t result=0;
			
			xcc_test2_expect( 0 == xc_tc_calc_overflow(55, 0, &result) );
			xcc_test2_expect_eq_t(size_t, 0, result );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("[1.1.1]-[nonzero dest > nonzero src]");
		
		if(1)
		{
			size_t result=0;
			
			xcc_test2_expect( 0 == xc_tc_calc_overflow(55, 33, &result) );
			xcc_test2_expect_eq_t(size_t, 0, result );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}
