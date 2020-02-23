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
#include "vector_dynamic_test_tpl.hpp"
/* --- */

xcc_tplTestVector_dynamic_hdr()
xcc_tplTestVector_dynamic_method(int) test_rem_idx(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	/* 0.1-e-1.1: null vobj, valid index EXPECT FAIL */
	do
	{
		TPL_VTYPE* vector_refp_null=NULL;
		xcc_test2_case("REM-[0.1-e-1.1]");
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.remove_idx(NULL, 0) );
			xcc_test2_expect( 0 != vector_I.remove_idx(vector_refp_null, 0) );
		}
		
		xcc_test2_case_end();
		
	} while(0);


	/* 0.1-e-1.2: null vobj, invalid index EXPECT FAIL */
	do
	{
		TPL_VTYPE* vector_refp_null=NULL;
		xcc_test2_case("REM-[0.1-e-1.2]");
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.remove_idx(NULL, -1) );
			xcc_test2_expect( 0 != vector_I.remove_idx(vector_refp_null, -1) );
			
			xcc_test2_expect( 0 != vector_I.remove_idx(NULL, INT_MAX) );
			xcc_test2_expect( 0 != vector_I.remove_idx(vector_refp_null, INT_MAX) );

		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	/* 0.1-e-2.1: uninit zero vobj, invalid index EXPECT FAIL */
	do
	{
		TPL_VTYPE vector_refp_uninit_zero={0};
		xcc_test2_case("REM-[0.1-e-2.1]");
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_refp_uninit_zero, -1) );
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_refp_uninit_zero, INT_MAX) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	/* 0.1-e-2.2: uninit zero vobj, valid index EXPECT FAIL */
	do
	{
		TPL_VTYPE vector_refp_uninit_zero={0};
		xcc_test2_case("REM-[0.1-e-2.1]");
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_refp_uninit_zero, 0) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	/* 0.1-e-3.1: uninit nonempty vobj, invalid index EXPECT FAIL */
	/* 0.1-e-3.2: uninit nonempty vobj, valid index EXPECT FAIL */


	/* 0.1-e-3.1: uninit init empty vobj, invalid index <0 EXPECT FAIL */
	do
	{
		TPL_VTYPE vector_obj;
		xcc_test2_case("REM-[0.1-e-3.1]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, -1) );
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, INT_MAX) );
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	/* 0.1-e-3.2: uninit init empty vobj, valid inaccessible index <0;length> EXPECT FAIL */
	do
	{
		TPL_VTYPE vector_obj;
		xcc_test2_case("REM-[0.1-e-3.2]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, 0) );
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		
		xcc_test2_case_end();
		
	} while(0);

	/* 0.1-e-3.3: uninit init empty vobj, valid inaccessible index <length; capacity> EXPECT FAIL */
	do
	{
		TPL_VTYPE vector_obj;
		xcc_test2_case("REM-[0.1-e-3.3]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, 1) );
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, 7) );
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		
		xcc_test2_case_end();
		
	} while(0);

	
	/* 0.1-e-3.4: uninit init empty vobj, valid inaccessible index <capacity; +> EXPECT FAIL */
	do
	{
		TPL_VTYPE vector_obj;
		xcc_test2_case("REM-[0.1-e-3.4]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, 8) );
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, 9) );
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, 10000) );
			xcc_test2_expect( 0 != vector_I.remove_idx(&vector_obj, INT_MAX) );
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		
		xcc_test2_case_end();
		
	} while(0);

	
	/* --- --- --- */
	
	/* 1.1.1: remove at 0 until empty; state: init, full <1 chunk>; EXPECT SUCCESS */
	do
	{
		TPL_VTYPE vector_obj;
		xcc_test2_case("REM-[1.1.1]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );

		if(1) 
		{
			if(1)
			{
				const size_t expected_length=8;
				const TPL_ITEM_TYPE tmp_expected_item_array[]={
					  LLII_I.item_obj( 1, "v:001")
					, LLII_I.item_obj( 2, "v:002")
					, LLII_I.item_obj( 3, "v:003")
					, LLII_I.item_obj( 4, "v:004")
					, LLII_I.item_obj( 5, "v:005")
					, LLII_I.item_obj( 6, "v:006")
					, LLII_I.item_obj( 7, "v:007")
					, LLII_I.item_obj( 8, "v:008")
				};
				std::vector<TPL_ITEM_TYPE> expected_items=_TMP_VECTOR_INIT(tmp_expected_item_array);
				
				
				xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[0]) );
				xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[1]) );
				xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[2]) );
				xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[3]) );
				xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[4]) );
				xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[5]) );
				xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[6]) );
				xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[7]) );
				
				if(1) {
					const size_t expected_length=8;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
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
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				
				if(1) {
					const size_t expected_length=7;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
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
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				
				if(1) {
					const size_t expected_length=6;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
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
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				
				
				
				if(1) {
					const size_t expected_length=5;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
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
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				
				if(1) {
					const size_t expected_length=4;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
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
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				
				if(1) {
					const size_t expected_length=3;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
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
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				
				if(1) {
					const size_t expected_length=2;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
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
				
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				
				if(1) {
					const size_t expected_length=1;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
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
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  
								}
							) 
						)
					);
				}
				
			}
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	/* 1.1.2: remove at 0 until empty; state: init, full <2 chunks>; EXPECT SUCCESS */
	do
	{
		size_t n=0;
		TPL_VTYPE vector_obj;
		const TPL_ITEM_TYPE tmp_expected_item_array[]={
			  LLII_I.item_obj( 1, "v:001")
			, LLII_I.item_obj( 2, "v:002")
			, LLII_I.item_obj( 3, "v:003")
			, LLII_I.item_obj( 4, "v:004")
			, LLII_I.item_obj( 5, "v:005")
			, LLII_I.item_obj( 6, "v:006")
			, LLII_I.item_obj( 7, "v:007")
			, LLII_I.item_obj( 8, "v:008")
			, LLII_I.item_obj( 11, "v:011")
			, LLII_I.item_obj( 12, "v:012")
			, LLII_I.item_obj( 13, "v:013")
			, LLII_I.item_obj( 14, "v:014")
			, LLII_I.item_obj( 15, "v:015")
			, LLII_I.item_obj( 16, "v:016")
			, LLII_I.item_obj( 17, "v:017")
			, LLII_I.item_obj( 18, "v:018")
		};
		std::vector<TPL_ITEM_TYPE> expected_items=_TMP_VECTOR_INIT(tmp_expected_item_array);
		
		xcc_test2_case("REM-[1.1.2]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		for(n=0;n<16;n++)
		{
			xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[n]) );
		}
		
		if(1)
		{
			if(1) {
				const size_t expected_length=16;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, expected_items
					)
				);
			}
		}
		
		if(1)
		{
			size_t n=0;
			
			for(n=1;n<8;n++)
			{
				
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				expected_items.erase( expected_items.begin() );
				
				
				if(1) {
					const size_t expected_length=16-n;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
							, expected_items
						)
					);
				}
				
			}
		}

		if(1)
		{
			
			if(1) {
				const size_t expected_length=9;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, expected_items
					)
				);
			}

		}
		
		if(1)
		{
			size_t n=0;
			
			for(n=0;n<8;n++)
			{
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				expected_items.erase( expected_items.begin() );
				
				if(1) {
					const size_t expected_length=8-n;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
							, expected_items
						)
					);
				}
				
				
			}
			
		}
		
		if(1)
		{
		
			if(1) {
				const size_t expected_length=1;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, expected_items
					)
				);
			}

		}
		
		if(1)
		{
			size_t n=0;
			
			for(n=1;n<=1;n++)
			{
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, 0) );
				expected_items.erase( expected_items.begin() );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
							, expected_items
						)
					);
				}
				
			}
		}
		
		if(1)
		{
			
			if(1) {
				const size_t expected_length=0;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  
							}
						) 
					)
				);
			}
			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	/* 1.2.1: remove at last until empty; state: init, full <2 chunks>; EXPECT SUCCESS */
	do
	{
		size_t n=0;
		TPL_VTYPE vector_obj;
		const TPL_ITEM_TYPE tmp_expected_item_array[]={
			  LLII_I.item_obj( 1, "v:001")
			, LLII_I.item_obj( 2, "v:002")
			, LLII_I.item_obj( 3, "v:003")
			, LLII_I.item_obj( 4, "v:004")
			, LLII_I.item_obj( 5, "v:005")
			, LLII_I.item_obj( 6, "v:006")
			, LLII_I.item_obj( 7, "v:007")
			, LLII_I.item_obj( 8, "v:008")
			, LLII_I.item_obj( 11, "v:011")
			, LLII_I.item_obj( 12, "v:012")
			, LLII_I.item_obj( 13, "v:013")
			, LLII_I.item_obj( 14, "v:014")
			, LLII_I.item_obj( 15, "v:015")
			, LLII_I.item_obj( 16, "v:016")
			, LLII_I.item_obj( 17, "v:017")
			, LLII_I.item_obj( 18, "v:018")
		};
		std::vector<TPL_ITEM_TYPE> expected_items=_TMP_VECTOR_INIT(tmp_expected_item_array);
		
		xcc_test2_case("REM-[1.2.1]");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		for(n=0;n<16;n++)
		{
			xcc_test2_expect( 0 == vector_I.push(&vector_obj, &tmp_expected_item_array[n]) );
		}
		
		if(1)
		{
			
			
			if(1) {
				const size_t expected_length=16;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, expected_items
					)
				);
			}

		}
		
		if(1)
		{
			size_t n=0;
			
			for(n=1;n<8;n++)
			{
				const size_t last_idx=16-n;
				
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, last_idx) );
				expected_items.erase( expected_items.end()-1 );
				
				
				if(1) {
					const size_t expected_length=16-n;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
							, expected_items
						)
					);
				}

			}
		}

		if(1)
		{

			if(1) {
				const size_t expected_length=9;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, expected_items
					)
				);
			}
			
		}

		if(1)
		{
			size_t n=0;
			
			for(n=1;n<=1;n++)
			{
				const size_t last_idx=8;
				
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, last_idx) );
				expected_items.erase( expected_items.end()-1 );
				
				if(1) {
					const size_t expected_length=8;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
							, expected_items
						)
					);
				}

			}
		}
		
		if(1)
		{
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, expected_items
					)
				);
			}
			
		}
		
		if(1)
		{
			size_t n=0;
			
			for(n=1;n<8;n++)
			{
				const size_t last_idx=8-n;
				
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, last_idx) );
				expected_items.erase( expected_items.end()-1 );
				
				if(1) {
					const size_t expected_length=8-n;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
							, expected_items
						)
					);
				}

			}
		}
		
		if(1)
		{
			/* just verify initial state */

			if(1) {
				const size_t expected_length=1;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, expected_items
					)
				);
			}

		}
		
		if(1)
		{
			size_t n=0;
			
			for(n=1;n<=1;n++)
			{
				const size_t expected_length=0;
				const size_t last_idx=0;
				
				xcc_test2_expect( 0 == vector_I.remove_idx(&vector_obj, last_idx) );
				expected_items.erase( expected_items.end()-1 );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  &vector_obj
							, expected_length
							, expected_items
						)
					);
				}

			}
		}
		
		if(1)
		{
			/* just verify initial state */
			if(1) {
				const size_t expected_length=0;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  
							}
						) 
					)
				);
			}

		}
		
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	/* 1.3.1: remove at %2==0 until empty; state: init, full <1 chunk>; EXPECT SUCCESS */
	/* 1.3.2: remove at %2==0 until empty; state: init, full <2 chunks>; EXPECT SUCCESS */

	/* 1.4.1: remove at %2==1 until empty; state: init, full <1 chunk>; EXPECT SUCCESS */
	/* 1.4.2: remove at %2==1 until empty; state: init, full <2 chunks>; EXPECT SUCCESS */
	
	xcc_test2_scope_end();
}
