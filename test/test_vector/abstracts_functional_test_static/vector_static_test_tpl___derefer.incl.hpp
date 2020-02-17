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
xcc_tplTestVector_static_method(int) test_derefer_00(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	do
	{
		TPL_VTYPE vector_obj={0};
		TPL_VTYPE* vector_obj_ref=NULL;
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		
		/*
		 * test: 
		 *  - produce DEREFER from empty object 
		 * expected:
		 *  - pointers from DEREFER match targets in target object
		 * 
		*/
		xcc_test2_case("DEREFER-00-1.0");
		
		derefer_obj = vector_I.derefer_retv(vector_obj_ref);
		
		/* test : */
		xcc_test2_expect( 0 != vector_I.derefer_validate_integrity(&vector_obj, &derefer_obj) );
		/* test : done */
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}



xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_derefer_01(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");


	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_obj_ref=NULL;
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		
		/*
		 * test: 
		 *  - produce DEREFER from NULL ref to COLLECTION-OBJ
		 * expected:
		 *  - success retv (retv object by value)
		 *  - invalid deref obj
		 * 
		*/
		xcc_test2_case("DEREFER-1.0-null1");
		
		derefer_obj = vector_I.derefer_retv(vector_obj_ref);
		xcc_test2_expect( 0 != vector_I.derefer_validate_integrity(&vector_obj, &derefer_obj) );
		xcc_test2_expect( 0 != vector_I.derefer_validate_data(&derefer_obj) );
		
		xcc_test2_case_end();
		
	} while(0);


	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		TPL_VTYPE* vector_obj_ref=NULL;
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		
		/*
		 * test: 
		 *  - produce DEREFER from NULL ref to COLLECTION-OBJ
		 * expected:
		 *  - success retv (retv object by value)
		 *  - invalid deref obj
		 * 
		*/
		xcc_test2_case("DEREFER-1.0-null2");
		
		derefer_obj = vector_I.derefer_retv(NULL);
		xcc_test2_expect( 0 != vector_I.derefer_validate_integrity(&vector_obj, &derefer_obj) );
		xcc_test2_expect( 0 != vector_I.derefer_validate_data(&derefer_obj) );
		
		xcc_test2_case_end();
		
	} while(0);


	do
	{
		TPL_VTYPE vector_obj=TPL_VTYPE();
		_TPL_DEREFER_TYPE_ derefer_obj={0};
		
		/*
		 * test: 
		 *  - produce DEREFER from COLLECTION-OBJ in uninitialized state {0}
		 * expected:
		 *  - success retv (retv object by value)
		 *  - invalid deref obj
		 * 
		*/
		xcc_test2_case("DEREFER-1.0.a");
		
		xcc_test2_expect( 0 == vector_I.init(&vector_obj) );
		derefer_obj = vector_I.derefer_retv(&vector_obj);
		xcc_test2_expect( 0 == vector_I.derefer_validate_integrity(&vector_obj, &derefer_obj) );
		xcc_test2_expect( 0 == vector_I.derefer_validate_data(&derefer_obj) );
		
		/* cleanup: */
		xcc_test2_expect( 0 == vector_I.deinit(&vector_obj) );
		/* cleanup: done */
		
		xcc_test2_case_end();
		
	} while(0);


	xcc_test2_scope_end();
}


