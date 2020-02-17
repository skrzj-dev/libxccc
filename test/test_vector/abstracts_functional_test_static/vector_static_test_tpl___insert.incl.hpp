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
/* --- */
/* --- */




xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_insert_idx___0_err(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	if(1)
	{
		/* 0.1-e-1.1: //null vobj, valid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			xcc_test2_case("0.1-e-1.1: //null vobj, valid index EXPECT FAIL");
			
			xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, 0, NULL) );
			
			xcc_test2_case_end();
			
		} while(0);


		/* 0.1-e-1.2: null vobj, invalid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			xcc_test2_case("0.1-e-1.2: //null vobj, valid index EXPECT FAIL");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(NULL, 0, &tmp_item) );
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		/* 0.1-e-1.2: null vobj, invalid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			xcc_test2_case("0.1-e-1.3: //null vobj, valid index EXPECT FAIL");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(NULL, 0, NULL) );
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		/* 0.1-e-1.2: null vobj, invalid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			xcc_test2_case("0.1-e-1.4: //null vobj, valid index EXPECT FAIL");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, 0, &tmp_item) );
			}
			
			xcc_test2_case_end();
			
		} while(0);

		/* 0.1-e-2.1: uninit zero vobj, invalid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			xcc_test2_case("0.1-e-2.1: //null vobj, valid index EXPECT FAIL");
			
			xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, 0, NULL) );
			}
			
			/* cleanup: */
			xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
			/* cleanup: done */

			xcc_test2_case_end();
			
		} while(0);

		/* 0.1-e-2.2: uninit zero vobj, valid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			xcc_test2_case("0.1-e-2.2: //null vobj, valid index EXPECT FAIL");
			
			xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, -1, &tmp_item) );
			}
			
			/* cleanup: */
			xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
			/* cleanup: done */

			xcc_test2_case_end();
			
		} while(0);
		
		/* 0.1-e-2.3: uninit zero vobj, valid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			xcc_test2_case("0.1-e-2.3: //null vobj, valid index EXPECT FAIL");
			
			xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, 65535, &tmp_item) );
			}
			
			/* cleanup: */
			xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
			/* cleanup: done */

			xcc_test2_case_end();
			
		} while(0);
		
	}
	
	if(1)
	{
		/* 0.1-e-3.1: uninit nonempty vobj, invalid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			memset(&vector_obj, 1, sizeof(TPL_VTYPE) );
			
			xcc_test2_case("0.1-e-3.1: //null vobj, valid index EXPECT FAIL");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, 65535, &tmp_item) );
			}

			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, -1, &tmp_item) );
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		/* 0.1-e-3.2: uninit nonempty vobj, valid index EXPECT FAIL */
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_ITEM_TYPE tmp_item;
			
			memset(&vector_obj, 1, sizeof(TPL_VTYPE) );
			
			xcc_test2_case("0.1-e-3.2");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, 0, &tmp_item) );
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
	}
	
	xcc_test2_scope_end();
}

xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_insert_idx___1_start(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	/* 1.1.1.0 */
	do
	{
		const TPL_ITEM_TYPE tmp_item_array_all[]={
			  LLII_I.item_obj( 8, "v:008")
			, LLII_I.item_obj( 7, "v:007")
			, LLII_I.item_obj( 6, "v:006")
			, LLII_I.item_obj( 5, "v:005")
			, LLII_I.item_obj( 4, "v:004")
			, LLII_I.item_obj( 3, "v:003")
			, LLII_I.item_obj( 2, "v:002")
			, LLII_I.item_obj( 1, "v:001")
		};
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE * vector_ref=&vector_obj;
		
		xcc_test2_case("[1.1.1.0]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 1/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[1-1]) );
			}
			
			if(1) {
				const size_t expected_length=1;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 2/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[2-1]) );
			}
			
			
			if(1) {
				const size_t expected_length=2;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 3/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[3-1]) );
			}
			
			
			if(1) {
				const size_t expected_length=3;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
		}
		
		
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 4/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[4-1]) );
			}
			
			if(1) {
				const size_t expected_length=4;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 5/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[5-1]) );
			}
			
			if(1) {
				const size_t expected_length=5;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 6/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[6-1]) );
			}
			
			if(1) {
				const size_t expected_length=6;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 3, "v:003")
								, LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 7/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[7-1]) );
			}
			
			
			if(1) {
				const size_t expected_length=7;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 2, "v:002")
								, LLII_I.item_obj( 3, "v:003")
								, LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 8/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[8-1]) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 1, "v:001")
								, LLII_I.item_obj( 2, "v:002")
								, LLII_I.item_obj( 3, "v:003")
								, LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
		}
		
		
		if(1)
		{
			xcc_test2_case_step_annotate("[1.1.1.0] 9 / 1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[1-1]) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 1, "v:001")
								, LLII_I.item_obj( 2, "v:002")
								, LLII_I.item_obj( 3, "v:003")
								, LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	xcc_test2_scope_end();
}


xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_insert_idx___2_end(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	
	/* 1.2.1.0 */
	do
	{
		const TPL_ITEM_TYPE tmp_item_array_all[]={
			  LLII_I.item_obj( 8, "v:008")
			, LLII_I.item_obj( 7, "v:007")
			, LLII_I.item_obj( 6, "v:006")
			, LLII_I.item_obj( 5, "v:005")
			, LLII_I.item_obj( 4, "v:004")
			, LLII_I.item_obj( 3, "v:003")
			, LLII_I.item_obj( 2, "v:002")
			, LLII_I.item_obj( 1, "v:001")
		};
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE * vector_ref=&vector_obj;
		
		xcc_test2_case("[1.2.1.0]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 1/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 0, &tmp_item_array_all[1-1]) );
			}
			
			if(1) {
				const size_t expected_length=1;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
							}
						) 
					)
				);
			}
			
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 2/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 1, &tmp_item_array_all[2-1]) );
			}
			
			if(1) {
				const size_t expected_length=2;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
								, LLII_I.item_obj( 7, "v:007")
							}
						) 
					)
				);
			}
			
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 3/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 2, &tmp_item_array_all[3-1]) );
			}
			
			if(1) {
				const size_t expected_length=3;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 6, "v:006")
							}
						) 
					)
				);
			}
			
		}
		
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 4/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 3, &tmp_item_array_all[4-1]) );
			}
			
			
			if(1) {
				const size_t expected_length=4;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 5, "v:005")
							}
						) 
					)
				);
			}
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 5/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 4, &tmp_item_array_all[5-1]) );
			}
			
			if(1) {
				const size_t expected_length=5;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 4, "v:004")
							}
						) 
					)
				);
			}
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 6/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 5, &tmp_item_array_all[6-1]) );
			}
			
			
			if(1) {
				const size_t expected_length=6;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 3, "v:003")
							}
						) 
					)
				);
			}
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 7/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 6, &tmp_item_array_all[7-1]) );
			}
			
			if(1) {
				const size_t expected_length=7;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 3, "v:003")
								, LLII_I.item_obj( 2, "v:002")
							}
						) 
					)
				);
			}
			
		}
		
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 8/1CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 == vector_I.insert_idx(&vector_obj, 7, &tmp_item_array_all[8-1]) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 3, "v:003")
								, LLII_I.item_obj( 2, "v:002")
								, LLII_I.item_obj( 1, "v:001")
							}
						) 
					)
				);
			}
			
		}
		if(1)
		{
			xcc_test2_case_step_annotate("[1.2.1.0] 9/2CHUNK");
			/* --- */
			
			if(1) {
				xcc_test2_expect( 0 != vector_I.insert_idx(&vector_obj, 8, &tmp_item_array_all[5-1]) );
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, vector_I.DIAG_get_expected_capacity_for_length(expected_length)
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj( 8, "v:008")
								, LLII_I.item_obj( 7, "v:007")
								, LLII_I.item_obj( 6, "v:006")
								, LLII_I.item_obj( 5, "v:005")
								, LLII_I.item_obj( 4, "v:004")
								, LLII_I.item_obj( 3, "v:003")
								, LLII_I.item_obj( 2, "v:002")
								, LLII_I.item_obj( 1, "v:001")
							}
						) 
					)
				);
			}
			
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	/* N/A */
	
	xcc_test2_scope_end();
}


xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_insert_idx___3_middle_N2(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	/* N/A */
	
	xcc_test2_scope_end();
}


xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_insert_idx___3_middle_N1(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	/* N/A */
	
	xcc_test2_scope_end();
}




xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_insert_idx(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("[TEST:INSERT AT IDX]");
	
	do
	{
		xcc_test2_case("[TEST:INSERT AT IDX]");
		
		if(1) {
			xcc_test2_expect( 0 == test_insert_idx___0_err( xcc_test2_param_internal_embedded() ) );
		}
		
		if(1) {
			xcc_test2_expect( 0 == test_insert_idx___1_start( xcc_test2_param_internal_embedded() ) );
		}

		if(1) {
			xcc_test2_expect( 0 == test_insert_idx___2_end( xcc_test2_param_internal_embedded() ) );
		}

		if(1) {
			xcc_test2_expect( 0 == test_insert_idx___3_middle_N2( xcc_test2_param_internal_embedded() ) );
		}

		if(1) {
			xcc_test2_expect( 0 == test_insert_idx___3_middle_N1( xcc_test2_param_internal_embedded() ) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}
