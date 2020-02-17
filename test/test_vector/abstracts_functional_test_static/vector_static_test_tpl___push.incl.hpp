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

#include <vector>
/* --- */
#include "xc/common/xc_mem.h"
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
/* --- */



xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_push(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("[fixed size vector]:[push]");
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
		TPL_ITEM_TYPE* tmp_item_ref=NULL;
		
		xcc_test2_case_descr("[PUSH]:[0.1.1]",
			"[expect error;all params value NULL;]"
		);

		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			TPL_VTYPE* vector_refp_tmpnull=NULL;
			xcc_test2_expect( 0 != vector_I.push(NULL, NULL) );
		}
		
		if(1) {
			const size_t expected_length=0;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02_uninitZero( xcc_test2_case_refer_customFailInfo(),
					  vector_ref
					, expected_length
					, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  
						}
					) 
				)
			);
		}

		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);


	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
		
		xcc_test2_case_descr("PUSH-0.02", "[expect error;all params ptr NULL;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			TPL_ITEM_TYPE* tmp_item_ref=NULL;
			TPL_VTYPE* vector_refp_tmpnull=NULL;
			
			xcc_test2_expect( 0 != vector_I.push(vector_refp_tmpnull, tmp_item_ref) );
		}
		
		
		if(1) {
			const size_t expected_length=0;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02_uninitZero( xcc_test2_case_refer_customFailInfo(),
					  vector_ref
					, expected_length
					, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  
						}
					) 
				)
			);
		}

		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);


	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
		TPL_ITEM_TYPE* tmp_item_ref=NULL;

		
		xcc_test2_case_descr("PUSH-0.03", "[expect error;self value NULL;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.push(NULL, &tmp_item) );
		}
		
		if(1) {
			const size_t expected_length=0;
			xcc_test2_expect_eq_t(int, 0, TMP_TEST_INTERNAL_02_uninitZero( xcc_test2_case_refer_customFailInfo(),
					  vector_ref
					, expected_length
					, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  
						}
					) 
				)
			);
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
		TPL_ITEM_TYPE* tmp_item_ref=NULL;
		
		xcc_test2_case_descr("PUSH-0.04", "[expect error;self ptr NULL;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			TPL_VTYPE* vector_refp_tmpnull=NULL;
			xcc_test2_expect( 0 != vector_I.push(vector_refp_tmpnull, &tmp_item) );
		}
		
		if(1) {
			const size_t expected_length=0;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02_uninitZero( xcc_test2_case_refer_customFailInfo(),
					  vector_ref
					, expected_length
					, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  
						}
					) 
				)
			);
		}

		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
		
		xcc_test2_case_descr("PUSH-0.04", "[expect error;item value NULL;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			TPL_VTYPE* vector_refp_tmpnull=NULL;
			TPL_ITEM_TYPE* tmp_item_ref=NULL;

			xcc_test2_expect( 0 != vector_I.push(vector_ref, NULL) );
		}
		
		if(1) {
			const size_t expected_length=0;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02_uninitZero( xcc_test2_case_refer_customFailInfo(),
					  vector_ref
					, expected_length
					, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  
						}
					) 
				)
			);
		}

		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
		
		xcc_test2_case_descr("PUSH-0.04", "[expect error;item ptr NULL;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			TPL_VTYPE* vector_refp_tmpnull=NULL;
			TPL_ITEM_TYPE* tmp_item_ref=NULL;

			xcc_test2_expect( 0 != vector_I.push(vector_ref, NULL) );
		}
		
		if(1) {
			const size_t expected_length=0;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02_uninitZero( xcc_test2_case_refer_customFailInfo(),
				  vector_ref
				, expected_length
				, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
				, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  
						}
					) 
				)
			);
		}

		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	/* --- --- --- */
	
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case_descr("PUSH-1.00", "[expect ok;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=1;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
							}
						) 
					)
				);
			}
			
			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case_descr("PUSH-1.02", "[expect ok;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=2;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  LLII_I.item_obj(1, "v:001")
									, LLII_I.item_obj(2, "v:002")
							}
						)
					)
				);
			}
			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case_descr("PUSH-1.02", "[expect ok;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(3, "v:003");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(4, "v:004");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=4;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
					  vector_ref
					, expected_length
					, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
							}
						)
					)
				);
			}
			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case_descr("PUSH-1.07", "[push until (length==capacity-1)][expect ok;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(3, "v:003");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(4, "v:004");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(5, "v:005");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(6, "v:006");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(7, "v:007");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			

			if(1) {
				const size_t expected_length=7;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
							}
						)
					)
				);
			}
			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case_descr("PUSH-1.08", "[push until (length==capacity)][expect ok;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(3, "v:003");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(4, "v:004");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(5, "v:005");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(6, "v:006");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(7, "v:007");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(8, "v:008");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
							}
						) 
					)
				);
			}
			
			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case_descr("PUSH-1.01.01", "[push until (length==capacity)][expect ok;][push +1][expect error and no changes]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(3, "v:003");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(4, "v:004");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(5, "v:005");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(6, "v:006");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(7, "v:007");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(8, "v:008");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
							}
						) 
					)
				);
			}
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(11, "v:011");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
							}
						) 
					)
				);
			}
			
			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case_descr("PUSH-1.01.01", "[expect ok;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(3, "v:003");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(4, "v:004");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(5, "v:005");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(6, "v:006");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(7, "v:007");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(8, "v:008");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
							}
						) 
					)
				);
			}
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(11, "v:011");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(12, "v:012");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(13, "v:013");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(14, "v:014");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(15, "v:015");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(16, "v:016");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(17, "v:017");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
							}
						) 
					)
				);
			}

		
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case_descr("PUSH-1.01.01", "[expect ok;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		if(1)
		{
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(3, "v:003");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(4, "v:004");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(5, "v:005");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(6, "v:006");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(7, "v:007");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(8, "v:008");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
							}
						) 
					)
				);
			}
			
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(11, "v:011");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(12, "v:012");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(13, "v:013");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(14, "v:014");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(15, "v:015");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(16, "v:016");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(17, "v:017");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(18, "v:018");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			if(1) {
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(21, "v:021");
				xcc_test2_expect( 0 != vector_I.push(vector_ref, &tmp_item) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
							}
						) 
					)
				);
			}

			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	xcc_test2_scope_end();
}
