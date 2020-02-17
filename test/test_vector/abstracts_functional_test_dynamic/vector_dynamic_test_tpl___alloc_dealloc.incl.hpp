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

#define verify_deallocated(ARG) (0)

#if 0
int verify_deallocated(const void* ptr);
int verify_deallocated(conat void* ptr)
{
	return 0;
}
#endif

xcc_tplTestVector_dynamic_hdr()
xcc_tplTestVector_dynamic_method(int) test_raii_alloc_init(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("@raii_alloc_init");
	
	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		
		xcc_test2_case("ALLOC_INIT-0.1");
		
		vector_obj_ptr=vector_I.alloc_init(vector_obj_ptr);
		xcc_test2_expect( NULL != vector_obj_ptr );
		
		/* cleanup: */
		xcc_test2_expect( 0 == vector_I.dealloc(vector_obj_ptr) );
		xcc_test2_expect( 0 == verify_deallocated( vector_obj_ptr ) );
		/* cleanup: done */

		xcc_test2_case_end();
		
	} while(0);

	do
	{
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		TPL_VTYPE* vector_obj_ptr=NULL;
		
		xcc_test2_case("ALLOC_INIT-0.1-E");
		
		vector_obj_ptr=vector_I.alloc_init(NULL);
		xcc_test2_expect( NULL != vector_obj_ptr );
		
		derefer_obj = vector_I.derefer_retv(vector_obj_ptr);
		xcc_test2_expect( 0 == vector_I.derefer_validate_integrity(vector_obj_ptr, &derefer_obj) );
		
		/* cleanup: */
		xcc_test2_expect( 0 == vector_I.dealloc(vector_obj_ptr) );
		/* cleanup: done */
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		TPL_VTYPE* vector_obj_ptr2=NULL;
		
		xcc_test2_case("ALLOC_INIT-0.1-E2");
		
		vector_obj_ptr=vector_I.alloc_init(vector_obj_ptr2);
		xcc_test2_expect( NULL != vector_obj_ptr );
		
		/* cleanup: */
		xcc_test2_expect( 0 == vector_I.dealloc(vector_obj_ptr) );
		/* cleanup: done */
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		
		xcc_test2_case("ALLOC_INIT-DEREFER-0.1");
		
		vector_obj_ptr=vector_I.alloc_init(vector_obj_ptr);
		xcc_test2_expect( NULL != vector_obj_ptr );
		
		derefer_obj = vector_I.derefer_retv( vector_obj_ptr ) ;
		xcc_test2_expect( 0 == vector_I.derefer_validate_integrity( vector_obj_ptr, &derefer_obj ) );
		
		/* cleanup: */
		xcc_test2_expect( 0 == vector_I.dealloc( vector_obj_ptr ) );
		xcc_test2_expect( 0 == verify_deallocated( vector_obj_ptr ) );
		/* cleanup: done */
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		
		xcc_test2_case("ALLOC_INIT-STATE-1.0");
		
		vector_obj_ptr=vector_I.alloc_init(vector_obj_ptr);
		xcc_test2_expect( NULL != vector_obj_ptr );
		
		derefer_obj = vector_I.derefer_retv( vector_obj_ptr );
		xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsNumbers(vector_obj_ptr, 8, 0) );
		xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsIntegrity(vector_obj_ptr, 8, 0) );
		xcc_test2_case_end();
		
	} while(0);
	
	
	xcc_test2_scope_end();
}


xcc_tplTestVector_dynamic_hdr()
xcc_tplTestVector_dynamic_method(int) test_raii_dealloc(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("@raii_dealloc");
	
	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		
		xcc_test2_case("DEALLOC-1.0-e-zero-null");
		
		xcc_test2_expect( 0 != vector_I.dealloc(vector_obj_ptr) ); 
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		
		xcc_test2_case("DEALLOC-1.0-e-zero-uninit");
		
		vector_obj_ptr=xc_mem_allocz_obj(TPL_VTYPE);
		xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, vector_obj_ptr, &vector_obj_empty) );
		/*xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty) );*/
		
		xcc_test2_expect( 0 != vector_I.dealloc(vector_obj_ptr) ); 
		xcc_test2_expect( 0 != vector_I.dealloc(vector_obj_ptr) ); 
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		
		xcc_test2_case("DEALLOC-1.0-init");
		
		vector_obj_ptr=vector_I.alloc_init(vector_obj_ptr);
		xcc_test2_expect( NULL != vector_obj_ptr );

		xcc_test2_expect( 0 == vector_I.dealloc(vector_obj_ptr) );
		xcc_test2_expect( 0 == verify_deallocated( vector_obj_ptr ) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		
		xcc_test2_case("DEALLOC-1.0-ALLOC_INIT-doubleDeinit");
		
		vector_obj_ptr=vector_I.alloc_init(vector_obj_ptr);
		xcc_test2_expect( NULL != vector_obj_ptr );

		xcc_test2_expect( 0 == vector_I.dealloc( vector_obj_ptr ) );
		xcc_test2_expect( 0 == verify_deallocated( vector_obj_ptr ) );
		
		xcc_test2_expect( 0 != vector_I.dealloc( vector_obj_ptr ) );
		xcc_test2_expect( 0 == verify_deallocated( vector_obj_ptr ) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE* vector_obj_ptr=NULL;
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		
		xcc_test2_case("ALLOC_INIT-DEALLOC-1.0-e2");
		
		vector_obj_ptr=vector_I.alloc_init(vector_obj_ptr);
		xcc_test2_expect( NULL != vector_obj_ptr );
		
		xcc_test2_expect( 0 == vector_I.dealloc( vector_obj_ptr ) );
		xcc_test2_expect( 0 == verify_deallocated( vector_obj_ptr ) );
		
		xcc_test2_expect( 0 != vector_I.dealloc( vector_obj_ptr ) );
		xcc_test2_expect( 0 == verify_deallocated( vector_obj_ptr ) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}
