#include "xcc/test/xcc_test2.hpp"

#include "xc/common/xc_mem.h"
#include "test_xc_mem_intf__cmem_u.h"

#include "test_xc_mem__cmem_code_inc.hpp"

#include "test_xc_mem__cmem_u.hpp"

static int test_xc_mem_u_do_all(xcc_test2_param_list) noexcept;

static int test_xc_mem_u_do_all(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("[test xc_mem_u]");
	
	xcc_test2_expect( 0 == test_cmem__alloc( xcc_test2_param_internal_embedded() ) );

	xcc_test2_expect( 0 == test_cmem__free( xcc_test2_param_internal_embedded() ) );
	
	xcc_test2_expect( 0 == test_cmem__cmp( xcc_test2_param_internal_embedded() ) );

	xcc_test2_expect( 0 == test_cmem__copy( xcc_test2_param_internal_embedded() ) );
	
	xcc_test2_scope_end();
}


int test_xc_mem_u(xcc_test2_param_list) noexcept
{
	
	return test_xc_mem_u_do_all(xcc_test2_param_list_forward);
}
