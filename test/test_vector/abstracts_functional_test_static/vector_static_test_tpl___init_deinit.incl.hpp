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

xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_init(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		
		xcc_test2_case("INIT-0.1");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		
		/* cleanup: */
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		/* cleanup: done */

		xcc_test2_case_end();
		
	} while(0);

	do
	{
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		TPL_VTYPE vector_obj=TPL_VTYPE();
		
		xcc_test2_case("INIT-0.1-E");
		
		xcc_test2_expect( 0 != vector_I.init(NULL) ); 
		derefer_obj = vector_I.derefer_retv(&vector_obj);
		xcc_test2_expect( 0 == vector_I.derefer_validate_integrity(&vector_obj, &derefer_obj) );
		
		/* cleanup: */
		xcc_test2_expect( 0 != vector_I.deinit(&vector_obj) );
		/* cleanup: done */
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_obj_ref=NULL;
		
		xcc_test2_case("INIT-0.1-E2");
		
		xcc_test2_expect( 0 != vector_I.init(vector_obj_ref) );

		/* cleanup: */
		xcc_test2_expect( 0 != vector_I.deinit(&vector_obj) );
		/* cleanup: done */
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		
		xcc_test2_case("INIT-DEREFER-0.1");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		derefer_obj = vector_I.derefer_retv(&vector_obj);
		xcc_test2_expect( 0 == vector_I.derefer_validate_integrity(&vector_obj, &derefer_obj) );
		
		/* cleanup: */
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		/* cleanup: done */
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		
		xcc_test2_case("INIT-STATE-1.0");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		derefer_obj = vector_I.derefer_retv(&vector_obj);
		xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsNumbers(&vector_obj, 8, 0) );
		xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsIntegrity(&vector_obj, 8, 0) );
		xcc_test2_case_end();
		
	} while(0);
	
	
	xcc_test2_scope_end();
}


xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_deinit(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		
		xcc_test2_case("DEINIT-1.0-e-zero-uninit");
		
		xcc_test2_expect( 0 != vector_I.deinit(&vector_obj) ); 
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		
		xcc_test2_case("DEINIT-1.0-init");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		
		xcc_test2_case("DEINIT-1.0-init-doubleDeinit");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty) );
		xcc_test2_expect( 0 != vector_I.deinit(&vector_obj) );
		xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty) );
		
		xcc_test2_expect_eq_t(int, 0, xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE vector_obj_empty=TPL_VTYPE();
		
		xcc_test2_case("INIT-DEINIT-1.0-e2");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty) );
		xcc_test2_expect( 0 != vector_I.deinit(&vector_obj) );
		xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj, &vector_obj_empty) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}
