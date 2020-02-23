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

xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_copyFrom_errors(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("");
	
	do
	{
		xcc_test2_case("copyfrom-e.1.01:[NULL<-NULL]");
		
		TPL_VTYPE* vector_obj_ptr_self=NULL;
		TPL_VTYPE* vector_obj_ptr_src=NULL;
		
		if(1) 
		{
			xcc_test2_expect(0!= vector_I.assignFrom(vector_obj_ptr_self, vector_obj_ptr_src, NULL) );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("copyfrom-e.1.02:[NULL<-uninit]");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE* vector_obj_ptr_self=NULL;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE* vector_obj_ptr_src=&vector_src_obj;
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
		}
		
		if(1)
		{
			xcc_test2_expect(0!= vector_I.assignFrom(vector_obj_ptr_self, vector_obj_ptr_src, NULL) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("copyfrom-e.1.03:[NULL<-init]");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE* vector_obj_ptr_self=NULL;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE* vector_obj_ptr_src=&vector_src_obj;
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.init(vector_obj_ptr_src) );
		}
		
		if(1)
		{
			xcc_test2_expect(0 != vector_I.assignFrom(vector_obj_ptr_self, vector_obj_ptr_src, NULL) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("copyfrom-e.2.01:[uninit<-NULL]");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE* vector_obj_ptr_self=&vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE* vector_obj_ptr_src=NULL;
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
		}
		
		if(1)
		{
			xcc_test2_expect(0!= vector_I.assignFrom(vector_obj_ptr_self, vector_obj_ptr_src, NULL) );
		}
		
		xcc_test2_case_end();
		
	} while(0);


	do
	{
		xcc_test2_case("copyfrom-e.2.02:[uninit<-uninit]");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE* vector_obj_ptr_self=&vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE* vector_obj_ptr_src=&vector_src_obj;
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
		}
		
		if(1)
		{
			xcc_test2_expect(0!= vector_I.assignFrom(vector_obj_ptr_self, vector_obj_ptr_src, NULL) );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		/* --- */
		TPL_VTYPE vector_obj_empty={0};
		/* --- */
		
		xcc_test2_case("copyfrom-e.2.03:[uninit<-init]");
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect(0 == vector_I.init(&vector_src_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
			}
			
		}
		
		if(1)
		{
			xcc_test2_expect(0!= vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_obj_empty, &vector_self_obj) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_src_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		/* --- */
		TPL_VTYPE vector_self_obj_copy={0};
		
		xcc_test2_case("copyfrom-e.3.01:[init<-NULL]");
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy, &vector_self_obj);
		}
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.assignFrom(&vector_self_obj, NULL, NULL) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_self_obj_copy, &vector_self_obj) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		/* --- */
		TPL_VTYPE vector_self_obj_copy={0};

		xcc_test2_case("copyfrom-e.3.02:[init<-uninit]");
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy, &vector_self_obj);
		}
		
		if(1)
		{
			xcc_test2_expect( 0 != vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_self_obj_copy, &vector_self_obj) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		TPL_VTYPE vector_self_obj;
		/* --- */
		TPL_VTYPE vector_self_obj_copy={0};

		xcc_test2_case("copyfrom-e.4.01:[init<-init], SAME OBJECT to SAME OBJECT; expect OK (NOTHING TO DO) and NO CHANGES");
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy, &vector_self_obj);
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.assignFrom(&vector_self_obj, &vector_self_obj, NULL) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_self_obj_copy, &vector_self_obj) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}


xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_copyFrom_ok(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("test: copyFrom valid");
	
	do
	{
		xcc_test2_case("copyfrom-1.01-[init empty <- init empty]; expect OK empty");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE vector_self_obj_copy_before_op={0};
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.init(&vector_src_obj) );
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy_before_op, &vector_self_obj);
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == xc_mem_u_cmp_obj(TPL_VTYPE, &vector_self_obj_copy_before_op, &vector_self_obj) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.deinit(&vector_src_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("copyfrom-1.02-[init non-empty  <- init empty]; expect OK empty");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE vector_self_obj_copy_before_op={0};
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.init(&vector_src_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy_before_op, &vector_self_obj);
		}
		
		if(1) {
			const size_t expected_length=1;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
					  &vector_self_obj
					, expected_length
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  LLII_I.item_obj( 1, "v:001")
						}
					) 
				)
			);
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1) {
			const size_t expected_length=0;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
					  &vector_src_obj
					, expected_length
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  
						}
					) 
				)
			);
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.deinit(&vector_src_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("copyfrom-1.03-[empty<-non-empty]; expect OK non-empty");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE vector_self_obj_copy_before_op={0};
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.init(&vector_src_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy_before_op, &vector_self_obj);
		}
		
		if(1) {
			const size_t expected_length=1;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
					  &vector_src_obj
					, expected_length
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  LLII_I.item_obj( 1, "v:001")
						}
					) 
				)
			);
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1) {
			const size_t expected_length=1;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
					  &vector_self_obj
					, expected_length
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  LLII_I.item_obj( 1, "v:001")
						}
					) 
				)
			);
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.deinit(&vector_src_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("copyfrom-1.101-[non-empty#1<-non-empty#2(length bigger than #1)]; expect result: non-empty#2");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE vector_self_obj_copy_before_op={0};
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.init(&vector_src_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
			}
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(11, "v:011");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(12, "v:012");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(13, "v:013");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(14, "v:014");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy_before_op, &vector_self_obj);
		}
		
		if(1)
		{
			
			if(1) {
				const size_t expected_length=2;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_self_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
							}
						) 
					)
				);
			}
			
			if(1) {
				const size_t expected_length=4;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_src_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(11, "v:011")
								, LLII_I.item_obj(12, "v:012")
								, LLII_I.item_obj(13, "v:013")
								, LLII_I.item_obj(14, "v:014")
							}
						) 
					)
				);
			}
			
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1) {
			const size_t expected_length=4;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
					  &vector_self_obj
					, expected_length
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  LLII_I.item_obj(11, "v:011")
							, LLII_I.item_obj(12, "v:012")
							, LLII_I.item_obj(13, "v:013")
							, LLII_I.item_obj(14, "v:014")
						}
					) 
				)
			);
		}
		
		if(0) /* unusable here */
		{
			xcc_test2_expect( 0 != xc_mem_u_cmp_obj(TPL_VTYPE, &vector_self_obj, &vector_self_obj_copy_before_op) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.deinit(&vector_src_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	
	do
	{
		xcc_test2_case("copyfrom-1.101.2-[non-empty#1<-non-empty#2(length bigger (more than capacity of #1) than #1)]; expect result: non-empty#2");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE vector_self_obj_copy_before_op={0};
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.init(&vector_src_obj) );
			
			xcc_test2_expect( 0 == INTF_INTERNAL_I.hack_forceSmallerCapacity(&vector_self_obj, 4) );
			
			
			if(1)
			{
				xcc_test2_expect( 4 == vector_I.get_capacity(&vector_self_obj) );
				xcc_test2_expect( vector_I.get_capacity(&vector_self_obj) != vector_I.get_capacity(&vector_src_obj) );
			}
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
			}
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(11, "v:011");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(12, "v:012");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(13, "v:013");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(14, "v:014");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(15, "v:015");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(16, "v:016");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(17, "v:017");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(18, "v:018");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(19, "v:019");
				xcc_test2_expect( 0 != vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(20, "v:020");
				xcc_test2_expect( 0 != vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(21, "v:021");
				xcc_test2_expect( 0 != vector_I.push(&vector_src_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy_before_op, &vector_self_obj);
		}
		
		if(1)
		{
			
			if(1) {
				const size_t expected_length=2;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02_cap( xcc_test2_case_refer_customFailInfo(),  
						  &vector_self_obj
						, expected_length
						, 4
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
							}
						) 
					)
				);
			}
			
			if(1) {
				const size_t expected_length=8;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02_cap( xcc_test2_case_refer_customFailInfo(),  
						  &vector_src_obj
						, expected_length
						, 8
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(11, "v:011")
								, LLII_I.item_obj(12, "v:012")
								, LLII_I.item_obj(13, "v:013")
								, LLII_I.item_obj(14, "v:014")
								, LLII_I.item_obj(15, "v:015")
								, LLII_I.item_obj(16, "v:016")
								, LLII_I.item_obj(17, "v:017")
								, LLII_I.item_obj(18, "v:018")
							}
						) 
					)
				);
			}
			
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1) {
			const size_t expected_length=4;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02_cap( xcc_test2_case_refer_customFailInfo(),  
					  &vector_self_obj
					, expected_length
					, 4
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  LLII_I.item_obj(11, "v:011")
							, LLII_I.item_obj(12, "v:012")
							, LLII_I.item_obj(13, "v:013")
							, LLII_I.item_obj(14, "v:014")
						}
					) 
				)
			);
		}
		
		if(0) /* unusable here */
		{
			xcc_test2_expect( 0 != xc_mem_u_cmp_obj(TPL_VTYPE, &vector_self_obj, &vector_self_obj_copy_before_op) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.deinit(&vector_src_obj) );
		}
		
		xcc_test2_case_end();
	
	} while(0);
	
	do
	{
		xcc_test2_case("copyfrom-1.102-[non-empty#1<-non-empty#2(length smaller than #1)]; expect result: non-empty#2");
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE vector_self_obj_copy_before_op={0};
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.init(&vector_src_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(1, "v:001");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(2, "v:002");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(3, "v:003");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
			}
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(11, "v:011");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(12, "v:012");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(13, "v:013");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(14, "v:014");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(15, "v:015");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy_before_op, &vector_self_obj);
		}
		
		if(1)
		{
			if(1) {
				const size_t expected_length=3;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_src_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(1, "v:001")
								, LLII_I.item_obj(2, "v:002")
								, LLII_I.item_obj(3, "v:003")
							}
						) 
					)
				);
			}
			
			if(1) {
				const size_t expected_length=5;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_self_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(11, "v:011")
								, LLII_I.item_obj(12, "v:012")
								, LLII_I.item_obj(13, "v:013")
								, LLII_I.item_obj(14, "v:014")
								, LLII_I.item_obj(15, "v:015")
							}
						) 
					)
				);
			}

		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1) {
			const size_t expected_length=3;
			xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
					  &vector_src_obj
					, expected_length
					, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
							  LLII_I.item_obj(1, "v:001")
							, LLII_I.item_obj(2, "v:002")
							, LLII_I.item_obj(3, "v:003")
						}
					) 
				)
			);
		}
		
		if(0) /* unusable here */
		{
			xcc_test2_expect( 0 != xc_mem_u_cmp_obj(TPL_VTYPE, &vector_self_obj, &vector_self_obj_copy_before_op) );
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.deinit(&vector_src_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("copyfrom-1.103-[non-empty#1<-non-empty#2(length same as #1)]; expect result: non-empty#2");
		
		
		TPL_VTYPE vector_self_obj;
		TPL_VTYPE vector_src_obj;
		TPL_VTYPE vector_self_obj_copy_before_op={0};
		
		if(1)
		{
			xc_mem_bzero_obj(TPL_VTYPE, &vector_self_obj);
			xc_mem_bzero_obj(TPL_VTYPE, &vector_src_obj);
			xcc_test2_expect( 0 == vector_I.init(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.init(&vector_src_obj) );
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(91, "v:091");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(92, "v:092");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(93, "v:093");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(94, "v:094");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(95, "v:095");
				xcc_test2_expect( 0 == vector_I.push(&vector_src_obj, &tmp_item) );
			}
			
			if(1)
			{
				TPL_ITEM_TYPE tmp_item;
				
				tmp_item=LLII_I.item_obj(11, "v:011");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(12, "v:012");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(13, "v:013");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(14, "v:014");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
				tmp_item=LLII_I.item_obj(15, "v:015");
				xcc_test2_expect( 0 == vector_I.push(&vector_self_obj, &tmp_item) );
			}
			
			xc_mem_cp_obj(TPL_VTYPE, &vector_self_obj_copy_before_op, &vector_self_obj);
		}
		
		if(1)
		{
			
			if(1) {
				const size_t expected_length=5;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_src_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(91, "v:091")
								, LLII_I.item_obj(92, "v:092")
								, LLII_I.item_obj(93, "v:093")
								, LLII_I.item_obj(94, "v:094")
								, LLII_I.item_obj(95, "v:095")
							}
						) 
					)
				);
			}
			
			if(1) {
				const size_t expected_length=5;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_self_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(11, "v:011")
								, LLII_I.item_obj(12, "v:012")
								, LLII_I.item_obj(13, "v:013")
								, LLII_I.item_obj(14, "v:014")
								, LLII_I.item_obj(15, "v:015")
							}
						) 
					)
				);
			}
			
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.assignFrom(&vector_self_obj, &vector_src_obj, NULL) );
		}
		
		if(1)
		{

			if(1) {
				const size_t expected_length=5;
				xcc_test2_expect( 0 == TMP_TEST_INTERNAL_02( xcc_test2_case_refer_customFailInfo(),  
						  &vector_self_obj
						, expected_length
						, TEST_ARRAY2VEC<TPL_ITEM_TYPE>( std::array<TPL_ITEM_TYPE, expected_length>{
								  LLII_I.item_obj(91, "v:091")
								, LLII_I.item_obj(92, "v:092")
								, LLII_I.item_obj(93, "v:093")
								, LLII_I.item_obj(94, "v:094")
								, LLII_I.item_obj(95, "v:095")
							}
						) 
					)
				);
			}
			
			if(0) /* unusable here */
			{
				xcc_test2_expect( 0 != xc_mem_u_cmp_obj(TPL_VTYPE, &vector_self_obj, &vector_self_obj_copy_before_op) );
			}
		}
		
		if(1)
		{
			xcc_test2_expect( 0 == vector_I.deinit(&vector_self_obj) );
			xcc_test2_expect( 0 == vector_I.deinit(&vector_src_obj) );
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}


xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) test_copyFrom_all(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("test: copyFrom");

	do
	{
		
		xcc_test2_case("copyfrom-e:");
		
		xcc_test2_expect( 0 == this->test_copyFrom_errors( xcc_test2_param_internal_embedded() ) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		
		xcc_test2_case("copyfrom-1:");
		
		xcc_test2_expect( 0 == this->test_copyFrom_ok( xcc_test2_param_internal_embedded() ) );
		
		xcc_test2_case_end();
		
	} while(0);

	xcc_test2_scope_end();
}

