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
xcc_tplTestVector_dynamic_method(int) test_get(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");

	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		
		xcc_test2_case("GET-1.01.01-[expect valid results;]");
		
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
						  &vector_obj
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
				
				if(1)
				{
					TPL_ITEM_TYPE* result_get_ref=NULL;
					TPL_ITEM_TYPE result_get_val_cp;
					TPL_ITEM_TYPE* result_get_direct_ptr=NULL;
					
					xcc_test2_expect( 0 == vector_I.get_idx_cp(vector_ref, 0, &result_get_val_cp) );
					
					result_get_ref=vector_I.get_idx_refp(vector_ref, 0);
					xcc_test2_expect(NULL!=result_get_ref);
					
					TPL_ITEM_TYPE& result_get_direct=vector_I.get_idx_val(vector_ref, 0);
					result_get_direct_ptr=&result_get_direct;
					
					xcc_test2_expect( result_get_ref == result_get_direct_ptr );
					xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_ITEM_TYPE, result_get_ref, &result_get_val_cp) );
					xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_ITEM_TYPE, result_get_ref, result_get_direct_ptr) );
					
					if(1) {
						const TPL_ITEM_TYPE tmp_expected_item=LLII_I.item_obj(1, "v:001");
						xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_ITEM_TYPE, result_get_ref, &tmp_expected_item ) );
					}
					
				}
			}
			
			
		}
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		int n=0;
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_ref=&vector_obj;
		std::vector<TPL_ITEM_TYPE> tmp_expected_vec=std::vector<TPL_ITEM_TYPE>();
		
		xcc_test2_case("GET-1.01.02-[expect valid results;]");
		
		xcc_test2_expect( 0 == vector_I.init(vector_ref) );
		
		/* prepare state: */
		if(1)
		{
			xcc_test2_case_step_annotate("creater state by push item");
			
			for(n=0;n<256;n++)
			{
				char tmpb[256]={0};
				
				snprintf(tmpb, sizeof(tmpb), "v:%03d", n);
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, tmpb);
				xcc_test2_expect( 0 == vector_I.push(vector_ref, &tmp_item) );
				tmp_expected_vec.push_back(tmp_item);
			}
		}
		/* prepare state: done */
		

		xcc_test2_case_step_annotate("verify item values against predefined vector");
		if(1) {
			const size_t expected_length=256;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
					  vector_ref
					, expected_length
					, tmp_expected_vec
				)
			);
		}

		/* verify content: done */
		
		
		/* verify state: */
		if(1)
		{
			xcc_test2_case_step_annotate("verify all items by value in iteration <0..length>");
			
			for(n=0; n<vector_I.get_length(vector_ref); n++)
			{
				char tmpb[256]={0};
				
				snprintf(tmpb, sizeof(tmpb), "item at [%d]:", n);
				xcc_test2_case_step_annotate(tmpb);
				
				if(1)
				{
					TPL_ITEM_TYPE* result_get_ref=NULL;
					TPL_ITEM_TYPE result_get_val_cp;
					TPL_ITEM_TYPE* result_get_direct_ptr=NULL;
					
					xcc_test2_expect( 0 == vector_I.get_idx_cp(vector_ref, n, &result_get_val_cp) );
					
					result_get_ref=vector_I.get_idx_refp(vector_ref, n);
					xcc_test2_expect(NULL!=result_get_ref);
					
					TPL_ITEM_TYPE& result_get_direct=vector_I.get_idx_val(vector_ref, n);
					result_get_direct_ptr=&result_get_direct;
					
					xcc_test2_expect( result_get_ref == result_get_direct_ptr );
					xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_ITEM_TYPE, result_get_ref, &result_get_val_cp) );
					xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_ITEM_TYPE, result_get_ref, result_get_direct_ptr) );
					
					
					xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_ITEM_TYPE, result_get_ref, &tmp_expected_vec[n] ) );
					xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_ITEM_TYPE, &result_get_val_cp, &tmp_expected_vec[n] ) );
					xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_ITEM_TYPE, result_get_direct_ptr, &tmp_expected_vec[n] ) );
					
				}
				
				snprintf(tmpb, sizeof(tmpb), "item at [%d]: done OK", n);
				xcc_test2_case_step_annotate(tmpb);
			}
		}
		/* verify state: */
		
		xcc_test2_expect( 0 == vector_I.deinit(vector_ref) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	
	
	xcc_test2_scope_end();
}
