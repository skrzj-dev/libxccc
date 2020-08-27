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
#include "./xc/am_seq/xc_am_seq.h"
/* --- */
#include "test_allocator_seq_chunk/test_xc_alc.hpp"
/* --- */

#define xc_mem_objPtr_to_ptr2ptr(_ARG_TYPE_, _TARGET_PTR_) ( \
		( \
			( ( (_ARG_TYPE_*)(void*)NULL)==(_TARGET_PTR_) ) \
				? ( (_ARG_TYPE_**)(&(_TARGET_PTR_)) ) \
				: ( (_ARG_TYPE_**)(&(_TARGET_PTR_)) ) \
		) \
	)


int test_alc_shift_right(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	do
	{
		/* [1.1]: shift  */
		xcc_test2_case("1111]");
		
		if(1)
		{
			int prealloc_int_array[8+1]={1,2,3,4,5,6,-1,-1, 666};
			int prealloc_int_array_expected[8+1]={1,0,2,3,4,5,6,-1, 666};
			
			if(1)
			{
				xc_am_seq_cfg_t tmp_cfg={0};
				xc_am_seq_state_t tmp_state={0};
				
				tmp_cfg.cnt_items_in_chunk=8;
				tmp_cfg.item_bytesize=sizeof(int);
				
				tmp_state.capacity=8;
				tmp_state.length=6;
				int* x1=prealloc_int_array;
				tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
				

				xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
						  &tmp_cfg
						, &tmp_state
						, 1
						, 1
					) 
				);
				
				xcc_test2_expect_eq_t(int, 8, tmp_state.capacity);
				xcc_test2_expect_eq_t(int, 7, tmp_state.length);
			}
			
			xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 8+1, prealloc_int_array, prealloc_int_array_expected) );
		}
	
		xcc_test2_case_end();
		
	} while(0);


	do
	{
		/* [1.1]: shift  */
		xcc_test2_case("1111]");
		
		if(1)
		{
			int prealloc_int_array[16+1]={
				    1,  2,  3,  4,  5,  6, -1, -1 
				 , -1, -1, -1, -1, -1, -1, -1, -1
				 , 666
			};
			int prealloc_int_array_expected[16+1]={
				   1, 0,  0,  0,  0,  2,  3,  4
				 , 5, 6, -1, -1, -1, -1, -1, -1
				 , 666
			};
			
			if(1)
			{
				xc_am_seq_cfg_t tmp_cfg={0};
				xc_am_seq_state_t tmp_state={0};
				
				tmp_cfg.cnt_items_in_chunk=16;
				tmp_cfg.item_bytesize=sizeof(int);
				
				tmp_state.capacity=16;
				tmp_state.length=6;
				int* x1=prealloc_int_array;
				tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
				
				xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
						  &tmp_cfg
						, &tmp_state
						, 1
						, 4
					) 
				);
				
				xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
				xcc_test2_expect_eq_t(int, 10, tmp_state.length);
			}
			
			xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16+1, prealloc_int_array, prealloc_int_array_expected) );
		}
	
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		/* [1.1]: shift  */
		xcc_test2_case("1111]");
		
		if(1)
		{
			int prealloc_int_array[16+1]={
				   1,  2,  3,  4,  5,  6, -1, -1
				 ,-1, -1, -1, -1, -1, -1, -1, -1
 				 , 666
			};
			int prealloc_int_array_expected[16+1]={
				    0,  1,  2,  3,  4,  5,  6, -1
				 , -1, -1, -1, -1, -1, -1, -1, -1
				 , 666
			};
			
			if(1)
			{
				xc_am_seq_cfg_t tmp_cfg={0};
				xc_am_seq_state_t tmp_state={0};
				
				tmp_cfg.cnt_items_in_chunk=16;
				tmp_cfg.item_bytesize=sizeof(int);
				
				tmp_state.capacity=16;
				tmp_state.length=6;
				int* x1=prealloc_int_array;
				tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
				

				xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
						  &tmp_cfg
						, &tmp_state
						, 0
						, 1
					) 
				);
				
				xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
				xcc_test2_expect_eq_t(int, 7, tmp_state.length);
			}
			
			xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16+1, prealloc_int_array, prealloc_int_array_expected) );
		}
	
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		/* [1.1]: shift  */
		xcc_test2_case("[1.3.11]");
		
		if(1)
		{
			int prealloc_int_array[16+1]={
				    1,  2,  3,  4,  5 , 6, -1, -1
				 , -1, -1, -1, -1, -1, -1, -1, -1
				 , 666
			};
			int prealloc_int_array_expected[16+1]={
				  0, 0,  0,  0,  1,  2,  3,  4
				 ,5, 6, -1, -1, -1, -1, -1, -1
				 , 666
			};
			
			if(1)
			{
				xc_am_seq_cfg_t tmp_cfg={0};
				xc_am_seq_state_t tmp_state={0};
				
				tmp_cfg.cnt_items_in_chunk=16;
				tmp_cfg.item_bytesize=sizeof(int);
				
				tmp_state.capacity=16;
				tmp_state.length=6;
				int* x1=prealloc_int_array;
				tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
				

				xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
						  &tmp_cfg
						, &tmp_state
						, 0
						, 4
					) 
				);
				
				xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
				xcc_test2_expect_eq_t(int, 10, tmp_state.length);
			}
			
			xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16+1, prealloc_int_array, prealloc_int_array_expected) );
		}
	
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		/* 1.4.1 last item by 1 */
		xcc_test2_case("[1.4.1:1]");
		
		if(1)
		{
			int prealloc_int_array[16+1]={
				   1,  2,  3,  4,  5,  6, -1, -1 
				, -1, -1, -1, -1, -1, -1, -1, -1 
				, 666
			};
			int prealloc_int_array_expected[16+1]={
				   1,  2,  3,  4,  5,  0,  6, -1 
				, -1, -1, -1, -1, -1, -1, -1, -1 
				, 666
			};
			
			if(1)
			{
				xc_am_seq_cfg_t tmp_cfg={0};
				xc_am_seq_state_t tmp_state={0};
				
				tmp_cfg.cnt_items_in_chunk=16;
				tmp_cfg.item_bytesize=sizeof(int);
				
				tmp_state.capacity=16;
				tmp_state.length=6;
				int* x1=prealloc_int_array;
				tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
				

				xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
						  &tmp_cfg
						, &tmp_state
						, 5
						, 1
					) 
				);
				
				xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
				xcc_test2_expect_eq_t(int, 7, tmp_state.length);
			}
			
			xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16, prealloc_int_array, prealloc_int_array_expected) );
		}
	
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		/* 1.4.1 last item by N */
		xcc_test2_case("[1.4.1:2]");
		
		if(1)
		{
			int prealloc_int_array[16+1]={
				   1,  2,  3,  4,  5,  6, -1, -1 
				, -1, -1, -1, -1, -1, -1, -1, -1 
				, 666
			};
			int prealloc_int_array_expected[16+1]={
				   1,  2,  3,  4,  0,  0,  0,  0 
				,  5,  6, -1, -1, -1, -1, -1, -1 
				, 666
			};
			
			if(1)
			{
				xc_am_seq_cfg_t tmp_cfg={0};
				xc_am_seq_state_t tmp_state={0};
				
				tmp_cfg.cnt_items_in_chunk=16;
				tmp_cfg.item_bytesize=sizeof(int);
				
				tmp_state.capacity=16;
				tmp_state.length=6;
				int* x1=prealloc_int_array;
				tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
				

				xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
						  &tmp_cfg
						, &tmp_state
						, 4
						, 4
					) 
				);
				
				xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
				xcc_test2_expect_eq_t(int, 10, tmp_state.length);
			}
			
			xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16, prealloc_int_array, prealloc_int_array_expected) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
		
	do
	{
		/* 1.4.1 last item by N */
		xcc_test2_case("[1.4.1:2]");
		
		if(1)
		{
			int prealloc_int_array[16+1]={
				   1,  2,  3,  4,  5,  6, -1, -1 
				, -1, -1, -1, -1, -1, -1, -1, -1 
				 , 666
			};
			int prealloc_int_array_expected[16+1]={
				   1,  2,  3,  4,  5,  0,  0,  0 
				,  0,  6, -1, -1, -1, -1, -1, -1 
				 , 666

			};
			
			if(1)
			{
				xc_am_seq_cfg_t tmp_cfg={0};
				xc_am_seq_state_t tmp_state={0};
				
				tmp_cfg.cnt_items_in_chunk=16;
				tmp_cfg.item_bytesize=sizeof(int);
				
				tmp_state.capacity=16;
				tmp_state.length=6;
				int* x1=prealloc_int_array;
				tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
				

				xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
						  &tmp_cfg
						, &tmp_state
						, 5
						, 4
					) 
				);
				
				xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
				xcc_test2_expect_eq_t(int, 10, tmp_state.length);
			}
			
			xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16, prealloc_int_array, prealloc_int_array_expected) );
		}
	
	
		xcc_test2_case_end();
		
	} while(0);
	
	if(1)
	{
		
		do
		{
			/* 1.6.1:1 to +1 from idx 0, length 1 */
			xcc_test2_case("[1.6.1:1]");
			
			if(1)
			{
				int prealloc_int_array[16+1]={
					   1,  -1, -1, -1, -1, -1, -1, -1
					, -1,  -1, -1, -1, -1, -1, -1, -1 
					, 666
				};
				int prealloc_int_array_expected[16+1]={
					   0,   1, -1, -1, -1, -1, -1, -1
					, -1,  -1, -1, -1, -1, -1, -1, -1 
					, 666
				};
				
				if(1)
				{
					xc_am_seq_cfg_t tmp_cfg={0};
					xc_am_seq_state_t tmp_state={0};
					
					tmp_cfg.cnt_items_in_chunk=16;
					tmp_cfg.item_bytesize=sizeof(int);
					
					tmp_state.capacity=16;
					tmp_state.length=1;
					int* x1=prealloc_int_array;
					tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
					

					xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
							  &tmp_cfg
							, &tmp_state
							, 1-1
							, 1
						) 
					);
					
					xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
					xcc_test2_expect_eq_t(int, 2, tmp_state.length);
				}
				
				xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16+1, prealloc_int_array, prealloc_int_array_expected) );
			}
		
		
			xcc_test2_case_end();
			
		} while(0);
	}
	
	
	if(1)
	{
		/* corner cases: fill to capacity-1 */
		
		do
		{
			/* 1.5.1: to capacity-1 from 0 idx */
			xcc_test2_case("[1.5.1:1]");
			
			if(1)
			{
				int prealloc_int_array[16+1]={
					   1,  2,  3,  4,  5,  6, -1, -1 
					, -1, -1, -1, -1, -1, -1, -1, -1 
					, 666
				};
				int prealloc_int_array_expected[16+1]={
					  0,  0,  0,  0,  0,  0,  0,  0
					, 0,  1,  2,  3,  4,  5,  6, -1
					, 666
				};
				
				if(1)
				{
					xc_am_seq_cfg_t tmp_cfg={0};
					xc_am_seq_state_t tmp_state={0};
					
					tmp_cfg.cnt_items_in_chunk=16;
					tmp_cfg.item_bytesize=sizeof(int);
					
					tmp_state.capacity=16;
					tmp_state.length=6;
					int* x1=prealloc_int_array;
					tmp_state.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(x1);
					

					xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
							  &tmp_cfg
							, &tmp_state
							, 0
							, 9
						) 
					);
					
					xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
					xcc_test2_expect_eq_t(int, 15, tmp_state.length);
				}
				
				xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16+1, prealloc_int_array, prealloc_int_array_expected) );
			}
		
		
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			/* 1.5.1: to capacity-1 from last-1 idx */
			xcc_test2_case("[1.5.1:2]");
			
			if(1)
			{
				int prealloc_int_array[16+1]={
					   1,  2,  3,  4,  5,  6, -1, -1 
					, -1, -1, -1, -1, -1, -1, -1, -1 
					, 666
				};
				int prealloc_int_array_expected[16+1]={
					   1,  2,  3,  4,  0,  0, 0,  0 
					,  0,  0,  0,  0,  0,  5, 6, -1 
					, 666
				};
				
				if(1)
				{
					xc_am_seq_cfg_t tmp_cfg={0};
					xc_am_seq_state_t tmp_state={0};
					
					tmp_cfg.cnt_items_in_chunk=16;
					tmp_cfg.item_bytesize=sizeof(int);
					
					tmp_state.capacity=16;
					tmp_state.length=6;
					int* x1=prealloc_int_array;
					tmp_state.refp_itemArray_byteptr.Refp2BtPtr=(unsigned char**)&x1;
					

					xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
							  &tmp_cfg
							, &tmp_state
							, 4
							, 9
						) 
					);
					
					xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
					xcc_test2_expect_eq_t(int, 15, tmp_state.length);
				}
				
				xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16+1, prealloc_int_array, prealloc_int_array_expected) );
			}
		
		
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			/* 1.5.1: to capacity-1 from last idx */
			xcc_test2_case("[1.5.1:3]");
			
			if(1)
			{
				int prealloc_int_array[16+1]={
					   1,  2,  3,  4,  5,  6, -1, -1 
					, -1, -1, -1, -1, -1, -1, -1, -1 
					, 666
				};
				int prealloc_int_array_expected[16+1]={
					   1,  2,  3,  4,  5,  0, 0,  0 
					,  0,  0,  0,  0,  0,  0, 6, -1  
					, 666
				};
				
				if(1)
				{
					xc_am_seq_cfg_t tmp_cfg={0};
					xc_am_seq_state_t tmp_state={0};
					
					tmp_cfg.cnt_items_in_chunk=16;
					tmp_cfg.item_bytesize=sizeof(int);
					
					tmp_state.capacity=16;
					tmp_state.length=6;
					int* x1=prealloc_int_array;
					tmp_state.refp_itemArray_byteptr.Refp2BtPtr=(unsigned char**)&x1;
					

					xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
							  &tmp_cfg
							, &tmp_state
							, 5
							, 9
						) 
					);
					
					xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
					xcc_test2_expect_eq_t(int, 15, tmp_state.length);
				}
				
				xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16+1, prealloc_int_array, prealloc_int_array_expected) );
			}
		
		
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			/* 1.5.2: to capacity-1 from last-1 idx */
			xcc_test2_case("[1.5.1:4]");
			
			if(1)
			{
				int prealloc_int_array[16+1]={
					   1,  2,  3,  4,  5,  6,  7,  8 
					,  9, 10, 11, 12, 13, 14, -1, -1 
					, 666
				};
				int prealloc_int_array_expected[16+1]={
					   1,  2,  3,  4,  5,  6,  7,  8 
					,  9, 10, 11, 12, 13, 0, 14, -1 
					, 666
				};
				
				if(1)
				{
					xc_am_seq_cfg_t tmp_cfg={0};
					xc_am_seq_state_t tmp_state={0};
					
					tmp_cfg.cnt_items_in_chunk=16;
					tmp_cfg.item_bytesize=sizeof(int);
					
					tmp_state.capacity=16;
					tmp_state.length=14;
					int* x1=prealloc_int_array;
					tmp_state.refp_itemArray_byteptr.Refp2BtPtr=(unsigned char**)&x1;
					

					xcc_test2_expect( 0 == xc_am_seq_tStatic_shiftRight(
							  &tmp_cfg
							, &tmp_state
							, 14-1
							, 1
						) 
					);
					
					xcc_test2_expect_eq_t(int, 16, tmp_state.capacity);
					xcc_test2_expect_eq_t(int, 15, tmp_state.length);
				}
				
				xcc_test2_expect(  0 == xc_mem_u_cmp_obj_array(int, 16+1, prealloc_int_array, prealloc_int_array_expected) );
			}
		
		
			xcc_test2_case_end();
			
		} while(0);
		
		/* corner cases: fill to capacity-1: done */
	}
	
	xcc_test2_scope_end();
}
