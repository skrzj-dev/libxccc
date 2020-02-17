/*#ifndef _XC_CMEM_TEST_INTF__CMEM_H_
#define _XC_CMEM_TEST_INTF__CMEM_H_*/

#undef TEST_xc_mem_allocz_obj 
#undef TEST_xc_mem_allocz_bytes 
#undef TEST_xc_mem_allocz_obj_array 

#undef TEST_xc_mem_bzero_obj 
#undef TEST_xc_mem_bzero_obj_array 
#undef TEST_xc_mem_bzero_bytes 

#undef TEST_xc_mem_cp_obj 
#undef TEST_xc_mem_cp_obj_array 
#undef TEST_xc_mem_cp_bytes 

#undef TEST_xc_mem_cmp_obj_param 
#undef TEST_xc_mem_cmp_obj_array_param 
#undef TEST_xc_mem_cmp_bytes_param 

#undef TEST_xc_mem_free_obj
#undef TEST_xc_mem_free_bytes


/* --- --- --- */

#define TEST_xc_mem_allocz_obj xc_mem_u_allocz_obj
#define TEST_xc_mem_allocz_bytes xc_mem_u_allocz_bytes
#define TEST_xc_mem_allocz_obj_array xc_mem_u_allocz_obj_array

#define TEST_xc_mem_bzero_obj xc_mem_u_bzero_obj
#define TEST_xc_mem_bzero_obj_array xc_mem_u_bzero_obj_array
#define TEST_xc_mem_bzero_bytes xc_mem_u_bzero_bytes

#define TEST_xc_mem_cp_obj xc_mem_u_cp_obj
#define TEST_xc_mem_cp_obj_array xc_mem_u_cp_obj_array
#define TEST_xc_mem_cp_bytes xc_mem_u_cp_bytes

#define TEST_xc_mem_cmp_obj_param xc_mem_u_cmp_obj_param
#define TEST_xc_mem_cmp_obj_array_param xc_mem_u_cmp_obj_array_param
#define TEST_xc_mem_cmp_bytes_param xc_mem_u_cmp_bytes_param

#define TEST_xc_mem_free_obj xc_mem_u_free_obj
#define TEST_xc_mem_free_bytes xc_mem_u_free_bytes

/*#endif*/
