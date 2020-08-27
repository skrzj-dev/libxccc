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
#include "xc/am_seq/xc_am_seq.h"
/* --- */
#include "abstracts_functional_any/vector_test_tpl___param_evaluation_check.hpp"

#include "xc/tcvector_d/xc_tcvector_d.h"
/* --- */
#include "_xcvector_d_param_evaluation.hpp"

#include "intf_xcvector_d/_xcvector_d_api_i_hlp.hpp"



#define embedd_01() \
	test_ObjReference_Refcounter<seq_dummyItem_t> vec_dummy_ref=test_ObjReference_Refcounter<seq_dummyItem_t>();\
	test_ObjReference_Refcounter<dummyItem_t> item_dummy_ref=test_ObjReference_Refcounter<dummyItem_t>();\
	test_ObjReference_Refcounter<int> idx_dummy_ref=test_ObjReference_Refcounter<int>();\
	seq_dummyItem_t* vec=NULL;\
	dummyItem_t tmpi={1, "x.aa.11"};\
	int dummy_idx=0;\
	xcc_test2_expect( NULL != ( vec = xc_tcVectorD_u_alloc_init(seq_dummyItem_t, vec) ) );\
	/**/\
	vec_dummy_ref.init(vec);\
	item_dummy_ref.init(&tmpi);\
	idx_dummy_ref.init(&dummy_idx);\


#define embedd_01_done() \
	xcc_test2_expect( 0 == xc_tcVectorD_u_dealloc(vec) );


static int test_push(xcc_test2_param_list);
static int test_pop(xcc_test2_param_list);
static int test_remove(xcc_test2_param_list);
static int test_insert(xcc_test2_param_list);

static int test_push(xcc_test2_param_list)
{
	xcc_test2_scope("param evaulation test: push");
	
	do
	{
		xcc_test2_case("param-evaulation-push-u");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 == xc_tcVectorD_u_push( vec_dummy_ref.get_refp(), item_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_neq_t(unsigned int, 0, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_neq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
			
			xcc_test2_expect_neq_t(unsigned int, 0, item_dummy_ref.get_cnter() );
			xcc_test2_expect_neq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("param-evaulation-push-s");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 == xc_tcVectorD_s_push( vec_dummy_ref.get_refp(), item_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_eq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("param-evaulation-push-i");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 == seq_dummyItem_t_I.push( vec_dummy_ref.get_refp(), item_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_eq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	xcc_test2_scope_end();
}



static int test_pop(xcc_test2_param_list)
{
	xcc_test2_scope("param evaulation test: pop");
	
	do
	{
		xcc_test2_case("param-evaulation-pop-u");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 != xc_tcVectorD_u_pop( vec_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_neq_t(unsigned int, 0, vec_dummy_ref.get_cnter() );
			
			//xcc_test2_expect_neq_t(unsigned int, 0, item_dummy_ref.get_cnter() );
			//xcc_test2_expect_neq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("param-evaulation-pop-s");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 != xc_tcVectorD_s_pop( vec_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_eq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("param-evaulation-pop-i");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 != seq_dummyItem_t_I.pop( vec_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_eq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	xcc_test2_scope_end();
}


static int test_remove(xcc_test2_param_list)
{
	xcc_test2_scope("param evaulation test: remove");
	
	do
	{
		xcc_test2_case("param-evaulation-remove-u");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 != xc_tcVectorD_u_remove_idx( vec_dummy_ref.get_refp(), idx_dummy_ref.get_val() ) );
			
			xcc_test2_expect_neq_t(unsigned int, 0, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_neq_t(unsigned int, 0, idx_dummy_ref.get_cnter() );
			
			//xcc_test2_expect_neq_t(unsigned int, 0, item_dummy_ref.get_cnter() );
			//xcc_test2_expect_neq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("param-evaulation-remove-s");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 != xc_tcVectorD_s_remove_idx( vec_dummy_ref.get_refp(), idx_dummy_ref.get_val() ) );
			
			xcc_test2_expect_eq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 1, idx_dummy_ref.get_cnter() );
			//xcc_test2_expect_eq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("param-evaulation-remove-i");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 != seq_dummyItem_t_I.remove_idx( vec_dummy_ref.get_refp(), idx_dummy_ref.get_val() ) );
			
			xcc_test2_expect_eq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 1, idx_dummy_ref.get_cnter() );
			//xcc_test2_expect_eq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	xcc_test2_scope_end();
}


static int test_insert(xcc_test2_param_list)
{
	xcc_test2_scope("param evaulation test: insert");
	
	do
	{
		xcc_test2_case("param-evaulation-insert-u");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 == xc_tcVectorD_u_insert( vec_dummy_ref.get_refp(), 0, item_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_neq_t(unsigned int, 0, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_neq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
			
			xcc_test2_expect_neq_t(unsigned int, 0, item_dummy_ref.get_cnter() );
			xcc_test2_expect_neq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("param-evaulation-insert-s");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 == xc_tcVectorD_s_insert( vec_dummy_ref.get_refp(), 0, item_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_eq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("param-evaulation-insert-i");
		
		embedd_01();
		
		if(1)
		{
			
			xcc_test2_expect( 0 == seq_dummyItem_t_I.insert( vec_dummy_ref.get_refp(), 0, item_dummy_ref.get_refp() ) );
			
			xcc_test2_expect_eq_t(unsigned int, 1, vec_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
		}
		
		embedd_01_done();
		
		xcc_test2_case_end();
	
	} while(0);
	
	
	xcc_test2_scope_end();
}


int test_paramEvaluationCnt_xcVectorD_main(xcc_test2_param_list)
{
	xcc_test2_scope("param evaulation test: main");
	
	do
	{
		xcc_test2_case("initial");
		
		test_ObjReference_Refcounter<dummyItem_t> item_dummy_ref=test_ObjReference_Refcounter<dummyItem_t>();
		dummyItem_t tmpi={1, "x.aa.11"};
		item_dummy_ref.init(&tmpi);
		
		if(1)
		{
			xcc_test2_expect_eq_t(unsigned int, 0, item_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 0, item_dummy_ref.get_cnter() );
			
			item_dummy_ref.get_refp();
			
			xcc_test2_expect_eq_t(unsigned int, 1, item_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 1, item_dummy_ref.get_cnter() );

			item_dummy_ref.get_refp();
			
			xcc_test2_expect_eq_t(unsigned int, 2, item_dummy_ref.get_cnter() );
			xcc_test2_expect_eq_t(unsigned int, 2, item_dummy_ref.get_cnter() );
		}
		
		xcc_test2_case_end();
	
	} while(0);
	
	xcc_test2_expect( 0 == test_push( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == test_pop( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == test_insert( xcc_test2_param_internal_embedded()) );
	xcc_test2_expect( 0 == test_remove( xcc_test2_param_internal_embedded() ) );
	
	
	xcc_test2_scope_end();
}
