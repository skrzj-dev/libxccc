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
xcc_tplTestVector_dynamic_method(int) test_set(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	if(1)
	{
		do
		{
			const TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
			TPL_VTYPE* vector_ref=NULL;
			
			xcc_test2_case("SET-1.01.e-[expect error handling; NULL vector]");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.set(vector_ref, 0, &tmp_item) );
			}

			if(1)
			{
				xcc_test2_expect( 0 != vector_I.set(vector_ref, 0, NULL) );
			}
			
			xcc_test2_case_end();
			
		} while(0);


		do
		{
			const TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
			TPL_VTYPE vector_obj=TPL_VTYPE();
			const TPL_VTYPE vector_obj_empty_nonInit=TPL_VTYPE();
			TPL_VTYPE* vector_ref=&vector_obj;
			
			xcc_test2_case("SET-1.01.e.xxx.01-[expect error handling; non- init vector]");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.set(vector_ref, 0, &tmp_item) );
			}
			
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty_nonInit) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		
		do
		{
			const TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
			TPL_VTYPE vector_obj=TPL_VTYPE();
			const TPL_VTYPE vector_obj_empty_nonInit=TPL_VTYPE();
			TPL_VTYPE* vector_ref=&vector_obj;
			
			xcc_test2_case("SET-1.01.e.xxx.02-[expect error handling; non- init vector]");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.set(vector_ref, -1, &tmp_item) );
			}
			
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty_nonInit) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
			TPL_VTYPE vector_obj=TPL_VTYPE();
			const TPL_VTYPE vector_obj_empty_nonInit=TPL_VTYPE();
			TPL_VTYPE* vector_ref=&vector_obj;
			
			xcc_test2_case("SET-1.01.e.xxx.03-[expect error handling; non- init vector]");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.set(vector_ref, 1, &tmp_item) );
			}
			
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty_nonInit) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
			TPL_VTYPE vector_obj=TPL_VTYPE();
			const TPL_VTYPE vector_obj_empty_nonInit=TPL_VTYPE();
			TPL_VTYPE* vector_ref=&vector_obj;
			
			xcc_test2_case("SET-1.01.e.xxx.04-[expect error handling; non- init vector]");
			
			if(1)
			{
				xcc_test2_expect( 0 != vector_I.set(vector_ref, 65535, &tmp_item) );
			}
			
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty_nonInit) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		
		do
		{
			const TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
			TPL_VTYPE vector_obj;
			TPL_VTYPE* vector_ref=&vector_obj;
			
			xcc_test2_case("SET-1.01.e-[expect error handling; valid  empty vector, invalid idx access]");
			
			xcc_test2_expect( 0 == vector_I.init(vector_ref) );
			
			if(1)
			{
				xcc_test2_case_step_annotate("init non- empty obj, invalid item, access at valid idx: idx [0]");
				xcc_test2_expect( 0 != vector_I.set(vector_ref, 0, &tmp_item) );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  
								}
							) 
						)
					);
				}
				
			}

			if(1)
			{
				xcc_test2_case_step_annotate("init non- empty obj, invalid item, access at valid idx: idx [-1]");
				xcc_test2_expect( 0 != vector_I.set(vector_ref, -1, &tmp_item) );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  
								}
							) 
						)
					);
				}
				
			}

			if(1)
			{
				xcc_test2_case_step_annotate("init non- empty obj, invalid item, access at valid idx: idx [1]");
				xcc_test2_expect( 0 != vector_I.set(vector_ref, 1, &tmp_item) );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  
								}
							) 
						)
					);
				}
				
			}
			
			if(1)
			{
				const int cur_capacity=vector_I.get_capacity(vector_ref);
				
				xcc_test2_expect( cur_capacity > 0);
				
				xcc_test2_case_step_annotate("init non- empty obj, invalid item, access at valid idx: idx ==cur_capacity");
				xcc_test2_expect( 0 != vector_I.set(vector_ref, cur_capacity, &tmp_item) );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  
								}
							) 
						)
					);
				}
				
			}
			
			if(1)
			{
				int cur_capacity=vector_I.get_capacity(vector_ref);
				
				xcc_test2_expect( cur_capacity > 0);
				
				cur_capacity=cur_capacity-1;
				
				xcc_test2_case_step_annotate("init non- empty obj, invalid item, access at valid idx: idx ==cur_capacity-1");
				xcc_test2_expect( 0 != vector_I.set(vector_ref, cur_capacity, &tmp_item) );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  
								}
							) 
						)
					);
				}
				
			}
			
			if(1)
			{
				int cur_capacity=vector_I.get_capacity(vector_ref);
				
				
				xcc_test2_expect( cur_capacity > 0);
				
				cur_capacity=cur_capacity+1;
				
				xcc_test2_case_step_annotate("init non- empty obj, invalid item, access at valid idx: idx ==cur_capacity+1");
				xcc_test2_expect( 0 != vector_I.set(vector_ref, cur_capacity, &tmp_item) );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  
								}
							) 
						)
					);
				}

			}
			
			if(1)
			{
				int cur_capacity=vector_I.get_capacity(vector_ref);
				
				xcc_test2_expect( cur_capacity > 0);
				
				cur_capacity=cur_capacity+100;
				
				xcc_test2_case_step_annotate("init non- empty obj, invalid item, access at valid idx: idx >cur_capacity");
				xcc_test2_expect( 0 != vector_I.set(vector_ref, cur_capacity, &tmp_item) );
				
				if(1) {
					const size_t expected_length=0;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  
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
			
			xcc_test2_case("SET-1.01.e-[expect error handling; valid vector, invalid access]");
			
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
					TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(11, "v:011");
					xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
				}
				
				
				if(1) {
					const size_t expected_length=9;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  LLII_I.item_obj(1, "v:001")
									, LLII_I.item_obj(2, "v:002")
									, LLII_I.item_obj(3, "v:003")
									, LLII_I.item_obj(4, "v:004")
									, LLII_I.item_obj(5, "v:005")
									, LLII_I.item_obj(6, "v:006")
									, LLII_I.item_obj(7, "v:007")
									, LLII_I.item_obj(8, "v:008")
									, LLII_I.item_obj(11, "v:011")
								}
							) 
						)
					);
				}
				
				if(1)
				{
					xcc_test2_case_step_annotate("init non- empty obj, invalid item, access at valid idx");
					if(1)
					{
						xcc_test2_expect( 0 != vector_I.set(vector_ref, 1, NULL) );
						
					}
					
					if(1) {
						const size_t expected_length=9;
						xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
								  vector_ref
								, expected_length
								, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
										  LLII_I.item_obj(1, "v:001")
										, LLII_I.item_obj(2, "v:002")
										, LLII_I.item_obj(3, "v:003")
										, LLII_I.item_obj(4, "v:004")
										, LLII_I.item_obj(5, "v:005")
										, LLII_I.item_obj(6, "v:006")
										, LLII_I.item_obj(7, "v:007")
										, LLII_I.item_obj(8, "v:008")
										, LLII_I.item_obj(11, "v:011")
									}
								) 
							)
						);
					}
					
				}
			}
			
			xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			TPL_VTYPE vector_obj=TPL_VTYPE();
			TPL_VTYPE* vector_ref=&vector_obj;
			
			xcc_test2_case("SET-1.01.e-[expect error handling; valid vector, invalid access]");
			
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
					TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(11, "v:011");
					xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
				}
				
				
				if(1) {
					const size_t expected_length=9;
					xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
							  vector_ref
							, expected_length
							, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
									  LLII_I.item_obj(1, "v:001")
									, LLII_I.item_obj(2, "v:002")
									, LLII_I.item_obj(3, "v:003")
									, LLII_I.item_obj(4, "v:004")
									, LLII_I.item_obj(5, "v:005")
									, LLII_I.item_obj(6, "v:006")
									, LLII_I.item_obj(7, "v:007")
									, LLII_I.item_obj(8, "v:008")
									, LLII_I.item_obj(11, "v:011")
								}
							) 
						)
					);
				}
				
				if(1)
				{
					xcc_test2_case_step_annotate("init non- empty obj, valid item, access at invalid idx <0");
					if(1)
					{
						const TPL_ITEM_TYPE tmp_item2set=LLII_I.item_obj(1005, "v:1005");
						
						xcc_test2_expect( 0 != vector_I.set(vector_ref, -1, &tmp_item2set) );
						
					}
					
					
					if(1) {
						const size_t expected_length=9;
						xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
								  vector_ref
								, expected_length
								, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
										  LLII_I.item_obj(1, "v:001")
										, LLII_I.item_obj(2, "v:002")
										, LLII_I.item_obj(3, "v:003")
										, LLII_I.item_obj(4, "v:004")
										, LLII_I.item_obj(5, "v:005")
										, LLII_I.item_obj(6, "v:006")
										, LLII_I.item_obj(7, "v:007")
										, LLII_I.item_obj(8, "v:008")
										, LLII_I.item_obj(11, "v:011")
									}
								) 
							)
						);
					}
				}

				if(1)
				{
					xcc_test2_case_step_annotate("init non- empty obj, valid item, access at invalid idx >=length");
					if(1)
					{
						const TPL_ITEM_TYPE tmp_item2set=LLII_I.item_obj(1005, "v:1005");
						
						xcc_test2_expect( 0 != vector_I.set(vector_ref, 9, &tmp_item2set) );
						
					}
					
					
					if(1) {
						const size_t expected_length=9;
						xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
								  vector_ref
								, expected_length
								, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
										  LLII_I.item_obj(1, "v:001")
										, LLII_I.item_obj(2, "v:002")
										, LLII_I.item_obj(3, "v:003")
										, LLII_I.item_obj(4, "v:004")
										, LLII_I.item_obj(5, "v:005")
										, LLII_I.item_obj(6, "v:006")
										, LLII_I.item_obj(7, "v:007")
										, LLII_I.item_obj(8, "v:008")
										, LLII_I.item_obj(11, "v:011")
									}
								) 
							)
						);
					}
					
				}
				
				if(1)
				{
					xcc_test2_case_step_annotate("init non- empty obj, valid item, access at invalid idx > length < capacity");
					if(1)
					{
						const TPL_ITEM_TYPE tmp_item2set=LLII_I.item_obj(1005, "v:1005");
						
						xcc_test2_expect( 0 != vector_I.set(vector_ref, 10, &tmp_item2set) );
						
					}
					
					if(1) {
						const size_t expected_length=9;
						xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
								  vector_ref
								, expected_length
								, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
										  LLII_I.item_obj(1, "v:001")
										, LLII_I.item_obj(2, "v:002")
										, LLII_I.item_obj(3, "v:003")
										, LLII_I.item_obj(4, "v:004")
										, LLII_I.item_obj(5, "v:005")
										, LLII_I.item_obj(6, "v:006")
										, LLII_I.item_obj(7, "v:007")
										, LLII_I.item_obj(8, "v:008")
										, LLII_I.item_obj(11, "v:011")
									}
								) 
							)
						);
					}
					
				}
				
				if(1)
				{
					xcc_test2_case_step_annotate("init non- empty obj, valid item, access at invalid idx >capacity");
					if(1)
					{
						const TPL_ITEM_TYPE tmp_item2set=LLII_I.item_obj(1005, "v:1005");
						
						xcc_test2_expect( 0 != vector_I.set(vector_ref, 65535, &tmp_item2set) );
						
					}
					
					
					if(1) {
						const size_t expected_length=9;
						xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
								  vector_ref
								, expected_length
								, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
										  LLII_I.item_obj(1, "v:001")
										, LLII_I.item_obj(2, "v:002")
										, LLII_I.item_obj(3, "v:003")
										, LLII_I.item_obj(4, "v:004")
										, LLII_I.item_obj(5, "v:005")
										, LLII_I.item_obj(6, "v:006")
										, LLII_I.item_obj(7, "v:007")
										, LLII_I.item_obj(8, "v:008")
										, LLII_I.item_obj(11, "v:011")
									}
								) 
							)
						);
					}

				}
				
			}
			
			xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
			
			xcc_test2_case_end();
			
		} while(0);
		
	}
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case("SET-1.01.01-[expect valid results;]");
		
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
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(11, "v:011");
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
			}
		}
		
		if(1)
		{
			
			if(1) {
				const size_t expected_length=9;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(5, "v:005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
								, LLII_I.item_obj(11, "v:011")
							}
						) 
					)
				);
			}
			
		}
		
		if(1)
		{
			xcc_test2_case_step_annotate("set at idx #5");
			if(1)
			{
				const TPL_ITEM_TYPE tmp_item2set=LLII_I.item_obj(1005, "v:1005");
				
				xcc_test2_expect( 0 == vector_I.set(vector_ref, 5-1, &tmp_item2set) );
				
			}
			
			if(1) {
				const size_t expected_length=9;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(1005, "v:1005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
								, LLII_I.item_obj(11, "v:011")
							}
						) 
					)
				);
			}

		}
		
		
		if(1)
		{
			xcc_test2_case_step_annotate("set at idx #1");
			if(1)
			{
				const TPL_ITEM_TYPE tmp_item2set=LLII_I.item_obj(1001, "v:1001");
				
				xcc_test2_expect( 0 == vector_I.set(vector_ref, 1-1, &tmp_item2set) );
				
			}
			
			
			if(1) {
				const size_t expected_length=9;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1001, "v:1001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(1005, "v:1005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
								, LLII_I.item_obj(11, "v:011")
							}
						) 
					)
				);
			}

		}
		
		
		
		if(1)
		{
			xcc_test2_case_step_annotate("set at idx #9");
			if(1)
			{
				const TPL_ITEM_TYPE tmp_item2set=LLII_I.item_obj(1111, "v:1111");
				
				xcc_test2_expect( 0 == vector_I.set(vector_ref, 9-1, &tmp_item2set) );
				
			}
			
			if(1) {
				const size_t expected_length=9;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  vector_ref
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1001, "v:1001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
								, LLII_I.item_obj(4, "v:004")
								, LLII_I.item_obj(1005, "v:1005")
								, LLII_I.item_obj(6, "v:006")
								, LLII_I.item_obj(7, "v:007")
								, LLII_I.item_obj(8, "v:008")
								, LLII_I.item_obj(1111, "v:1111")
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
