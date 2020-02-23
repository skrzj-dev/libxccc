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
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
/* --- */
#include "xc/am_seq/xc_ammo_seq.h"
#include "test_allocatorctl_seq_chunk.hpp"
/* --- */


static int test_allocator_emptyNullArgs(xcc_test2_param_list, const size_t expected_size);

static int test_allocator_empty_grow(xcc_test2_param_list);

template<typename TPL_ITEMTYPE>
static int test_allocator_empty_grow_to_N(xcc_test2_param_list, const size_t arg_new_required_length, const size_t arg_itemcnt_chunk);

template<typename TPL_ITEMTYPE>
static int test_allocator_empty_grow_zero(xcc_test2_param_list);


static int test_allocator_emptyNullArgs(xcc_test2_param_list, const size_t expected_size)
{
	xcc_test2_scope("emptyNullArgs");
	
	do
	{
		xcc_test2_case("`1.0-empty");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(&cfg, &initial, &result, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	do
	{
		xcc_test2_case("`1.0-e-null-000");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(NULL, NULL, NULL, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	do
	{
		xcc_test2_case("`1.0-e-null-001");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(NULL, NULL, &result, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);

	do
	{
		xcc_test2_case("`1.0-e-null-010");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(NULL, &initial, NULL, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	do
	{
		xcc_test2_case("`1.0-e-null-011");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(NULL, &initial, &result, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);
	

	do
	{
		xcc_test2_case("`1.0-e-null-100");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(&cfg, NULL, NULL, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	do
	{
		xcc_test2_case("`1.0-e-null-101");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(&cfg, NULL, &result, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	do
	{
		xcc_test2_case("`1.0-e-null-110");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(&cfg, &initial, NULL, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);

	
	do
	{
		xcc_test2_case("`1.0-e-empty-00");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(&cfg, &initial, &result, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	do
	{
		xcc_test2_case("`1.0-e-empty-10");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		if(1)
		{
			initial.capacity=8;
			initial.length=1;
			void* deadptr=(void*)0xDEAD;
			initial.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw( deadptr );
		}
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(&cfg, &initial, &result, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);

	do
	{
		xcc_test2_case("`1.0-e-empty-10");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		
		if(1)
		{
			cfg.cnt_items_in_chunk=8;
			cfg.item_bytesize=32;
		}
		
		xcc_test2_expect_neq_t(int, 0, xc_ammo_seq_tChunkC_realloc(&cfg, &initial, &result, expected_size) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
		
		xcc_test2_case_end();
	
	} while(0);

	xcc_test2_scope_end();
}



int test_allocator_length_to_chunk(xcc_test2_param_list)
{
	xcc_test2_scope("");
	
	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=0;
		const size_t arg_itemcnt_chunk=0;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-0.1");
		
		xcc_test2_expect( 0 != xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(int, 0, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);

	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=1;
		const size_t arg_itemcnt_chunk=0;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-0.2");
		
		xcc_test2_expect( 0 != xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(int, 0, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);

	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=3;
		const size_t arg_itemcnt_chunk=0;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-0.3");
		
		xcc_test2_expect( 0 != xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(int, 0, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);
	

	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=0;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=arg_itemcnt_chunk;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=0 capacity=8");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(int, 8, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);


	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=1;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=1 capacity=8");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, 8, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=2;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=2 capacity=8");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, 8, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=7;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=7 capacity=8");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, 8, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=8;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=8 capacity=8");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, arg_itemcnt_chunk*1, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=9;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=9 capacity=8*2");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, arg_itemcnt_chunk*2, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);

	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=10;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=10 capacity=8*2");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, arg_itemcnt_chunk*2, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);


	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=15;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=15 capacity=8*2");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, arg_itemcnt_chunk*2, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=16;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=16 capacity=8*2");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, arg_itemcnt_chunk*2, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);

	
	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=17;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=17 capacity=8*3");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, arg_itemcnt_chunk*3, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	do
	{
		const size_t prev_capacity=0;
		const size_t arg_expected_length=18;
		const size_t arg_itemcnt_chunk=8;
		size_t tmp_expected_capacity=0;
		
		xcc_test2_case("LENGTH2CHUNK-1.0-length=18 capacity=8*3");
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
				  arg_expected_length
				, prev_capacity
				, arg_itemcnt_chunk
				, &tmp_expected_capacity
			) 
		);
		xcc_test2_expect_eq_t(size_t, arg_itemcnt_chunk*3, tmp_expected_capacity);
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	xcc_test2_scope_end();
}



template<typename TPL_ITEMTYPE>
int test_allocator_empty_grow_to_N(xcc_test2_param_list, const size_t arg_expected_length, const size_t arg_itemcnt_chunk)
{
	xcc_test2_scope("");
	
	do
	{
		char tmp[128]={0};
		xcc_test2_case("GROW-1.0-zero2[lessThanChunkLimiit(N)]");
		snprintf(tmp, sizeof(tmp), "expected_length=[%u] itemcnt_chunk=[%u]", (unsigned int)arg_expected_length, (unsigned int)arg_itemcnt_chunk);
		xcc_test2_case_step_annotate(tmp);
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		TPL_ITEMTYPE* ptr2alloc=NULL;
		
		if(1)
		{
			cfg.cnt_items_in_chunk=arg_itemcnt_chunk;
			cfg.item_bytesize=sizeof(TPL_ITEMTYPE);
		}
		
		if(1)
		{
			initial.capacity=0;
			initial.length=0;
			initial.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(ptr2alloc);
		}
		
		xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_realloc(&cfg, &initial, &result, arg_expected_length) );
		
		if(1)
		{
			const size_t tmp_input_capacity=0;
			size_t tmp_expected_capacity=0;
			
			xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(
					  arg_expected_length
					, tmp_input_capacity
					, arg_itemcnt_chunk
					, &tmp_expected_capacity
				) 
			);
			
			xcc_test2_trap_set(1);
			xcc_test2_expect( 0 != xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
			xcc_test2_expect_eq_t(int, tmp_expected_capacity, result.capacity );
			xcc_test2_expect_eq_t(int, arg_expected_length, result.length );
			xcc_test2_expect( xc_p_refp2pBytes_castFrom_raw(ptr2alloc) == result.refp_itemArray_byteptr.Refp2BtPtr );
			if(1)
			{
				xc_p_pBytes_t tmpbp=xc_p_pBytes_from_ref2pBytes(result.refp_itemArray_byteptr);
				xcc_test2_expect( xc_p_pBytes_castFrom_raw(ptr2alloc) == tmpbp.BtPtr );
			}
			xcc_test2_trap_set(0);
			
		}
		
		xcc_test2_case_end();
	
	} while(0);


	xcc_test2_scope_end();
}


	
template<typename TPL_ITEMTYPE>
int test_allocator_empty_grow_zero(xcc_test2_param_list)
{
	xcc_test2_scope("");
	
	do
	{
		xcc_test2_case("GROW-1.0-zero2zero");
		
		xc_ammo_seq_cfg_t cfg={0};
		xc_ammo_seq_state_t initial={0};
		xc_ammo_seq_state_t result={0};
		xc_ammo_seq_state_t state_empty={0};
		TPL_ITEMTYPE* ptr2alloc=NULL;
		size_t expected_size=0;
		
		if(1)
		{
			cfg.cnt_items_in_chunk=8;
			cfg.item_bytesize=sizeof(TPL_ITEMTYPE);
		}
		
		if(1)
		{
			initial.capacity=0;
			initial.length=0;
			
			initial.refp_itemArray_byteptr.Refp2BtPtr=xc_p_refp2pBytes_castFrom_raw(ptr2alloc);
		}
		
		expected_size=0;
		xcc_test2_expect_eq_t(int, 0, xc_ammo_seq_tChunkC_realloc(&cfg, &initial, &result, expected_size) );
		
		if(1)
		{
			size_t tmp_expected_capacity=0;
			
			xcc_test2_expect( 0 != xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &initial) );
			
			
			xcc_test2_expect( 0 == xc_ammo_seq_tChunkC_length2capacity(0, initial.capacity, 8, &tmp_expected_capacity) );
			
			xcc_test2_trap_set(1);
			xcc_test2_expect( 0 != xc_mem_u_cmp_obj(xc_ammo_seq_state_t, &result, &state_empty) );
			xcc_test2_expect_eq_t(int,  tmp_expected_capacity, result.capacity );
			xcc_test2_expect_eq_t(int,  0, result.length );
			xcc_test2_expect( xc_p_pBytes_castFrom_raw(ptr2alloc) == xc_p_pBytes_from_ref2pBytes(result.refp_itemArray_byteptr).BtPtr );
			xcc_test2_trap_set(0);

		}
		
		xcc_test2_case_end();
	
	} while(0);
	
	xcc_test2_scope_end();
}


int test_allocator(xcc_test2_param_list)
{
	xcc_test2_scope("test-allocator-all");
	
	if(1)
	{
		do
		{
			xcc_test2_case("invalid args: for size 0");
			
			xcc_test2_expect(  0 == test_allocator_emptyNullArgs(xcc_test2_param_internal_embedded(), 0) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			xcc_test2_case("invalid args: for size 4");
			
			xcc_test2_expect(  0 == test_allocator_emptyNullArgs(xcc_test2_param_internal_embedded(), 4) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			xcc_test2_case("invalid args: for size 8");
			
			xcc_test2_expect(  0 == test_allocator_emptyNullArgs(xcc_test2_param_internal_embedded(), 8) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			xcc_test2_case("invalid args: for size 11");
			
			xcc_test2_expect(  0 == test_allocator_emptyNullArgs(xcc_test2_param_internal_embedded(), 11) );
			
			xcc_test2_case_end();
			
		} while(0);
	}
	
	
	if(1)
	{
		
		do
		{
			xcc_test2_case("grow from zero to zero: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_zero<int>(xcc_test2_param_internal_embedded() ) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			xcc_test2_case("grow from zero to zero to N (0): ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 1, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 1, 8) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 2, 8) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 3, 8) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 3, 8) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 7, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 8, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 9, 8) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 10, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 14, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 15, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 16, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 17, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 1024, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 1999, 8) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		
		
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 0, 1) );
			
			xcc_test2_case_end();
			
		} while(0);
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 1, 1) );
			
			xcc_test2_case_end();
			
		} while(0);
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 2, 1) );
			
			xcc_test2_case_end();
			
		} while(0);
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 3, 1) );
			
			xcc_test2_case_end();
			
		} while(0);
		do
		{
			xcc_test2_case("grow from zero to zero to N: ");
			
			xcc_test2_expect(  0 == test_allocator_empty_grow_to_N<int>(xcc_test2_param_internal_embedded(), 10, 1) );
			
			xcc_test2_case_end();
			
		} while(0);
	}
	
	xcc_test2_scope_end();
}
