
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"

template<typename TPL_T>
std::string tmp_to_string(const TPL_T& arg)
{
	std::stringstream ss;
	ss<<arg;
	return ss.str();
}

int test_of__test(xcc_test2_param_list);

int test_of__test_sub01(xcc_test2_param_list);

int test_of__test_sub02_complicated_withFailure(xcc_test2_param_list);

int test_of__test_sub_customComplicatedVerification(xcc_test2_failureDetails_t& failInfo);

int test_of__test(xcc_test2_param_list)
{
	xcc_test2_scope("scope01");
	
	do
	{
		xcc_test2_case_descr("INIT-0.1.1", "description1");
		
		xcc_test2_expect( 0 == 0 );
		xcc_test2_expect_eq_t(int,  12, 12 );
		
		xcc_test2_case_end();
		
	} while(0);
	

	do
	{
		xcc_test2_case_descr("INIT-0.1.2", "description2");
		
		xcc_test2_expect( 0 == 0 );
		xcc_test2_expect_eq_t(int,  12, 12 );
		xcc_test2_case_step_annotate("some annotation for [INIT-0.1]");
		
		xcc_test2_case_end();
		
	} while(0);
	

	do
	{
		xcc_test2_case_descr("INIT-0.2.1", "");
		
		xcc_test2_expect( 0 == 0 );
		xcc_test2_expect_neq_t(int,  12, 13 );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case_descr("INIT-0.2.2", "description4");
		
		xcc_test2_case_step_annotate("some annotation for [INIT-0.2]");
		
		xcc_test2_expect( 0 == 0 );
		xcc_test2_expect_neq_t(int,  12, 13 );
		
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case_descr("NESTED-0.1.1", "description10");
		
		xcc_test2_case_step_annotate("some annotation for [NESTED-0.1.1]");
		
		test_of__test_sub02_complicated_withFailure( xcc_test2_param_internal_embedded() );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case_descr("NESTED-0.1.2", "description10");
		
		xcc_test2_case_step_annotate("some annotation for [NESTED-0.1.2]");
		
		test_of__test_sub01( xcc_test2_param_internal_embedded() );
		
		xcc_test2_case_end();
		
	} while(0);

	
	//test_of__test_sub02_complicated_withFailure( xcc_test2_param_internal_embedded() );
	
	test_of__test_sub01( xcc_test2_param_internal_embedded() );
	
	do
	{
		xcc_test2_case_descr("INIT-0.10.1", "description-x");
		
		xcc_test2_expect( 0 == 0 );
		xcc_test2_expect_eq_t(int,  12, 12 );
		xcc_test2_case_step_annotate("some annotation for [INIT-0.10.1]");
		
		xcc_test2_case_end();
		
	} while(0);

	
	xcc_test2_scope_end();
}


int test_of__test_sub01(xcc_test2_param_list)
{
	xcc_test2_scope("scope02");
	
	do
	{
		xcc_test2_case_descr("SUB-0.1", "");
		
		xcc_test2_expect( 0 == 0 );
		xcc_test2_expect_eq_t(int,  12, 12 );
		
		xcc_test2_case_end();
		
	} while(0);
	

	do
	{
		xcc_test2_case_descr("SUB-0.2", "descriptino for <SUB-0.2>");
		
		xcc_test2_expect( 0 == 0 );
		xcc_test2_expect_eq_t(int,  12, 12 );
		xcc_test2_case_step_annotate("some annotation for [SUB-0.2]");
		
		xcc_test2_case_end();
		
	} while(0);
	

	xcc_test2_scope_end();
}


int test_of__test_sub02_complicated_withFailure(xcc_test2_param_list)
{
	xcc_test2_scope("scope03-complicated");
	
	do
	{
		xcc_test2_case_descr("COMPLICATED-0.1", "");
		
		xcc_test2_case_step_annotate("some annotation for [COMPLICATED]");
		
		xcc_test2_expect_eq_t(int,  12, 12 );
		xcc_test2_expect( 0 == test_of__test_sub_customComplicatedVerification(xcc_test2_case_refer_customFailInfo() ) );
		
		xcc_test2_case_end();

	} while(0);
	
	xcc_test2_scope_end();
}


int test_of__test_sub_customComplicatedVerification(xcc_test2_failureDetails_t& failInfo)
{
	for(int n=0; n<4; n++)
	{
		failInfo.lastAnnotation=xcc_test2_annotation_t::itz_retv(
			  xcc_test2_scopeInfo_ITZ()
			, "iteration"
			, "idx=[%d]", n
		);
		
		if(3==n) {
			failInfo.scopeInfo=xcc_test2_scopeInfo_ITZ();
			failInfo.content="failure at idx:["+tmp_to_string<int>(n)+"] due to something procedural, details here";
			return 1;
		}
		
	}
	
	return 0;
}


int main()
{
	xcc_test2_procedure tmpProc;
	
	if(0!=test_of__test( xcc_test2_param_public_result(&tmpProc) ) ) {
		fprintf(stdout, "[xcc::tval] test: FAILURE!\n");
		//return 1;
	}
	else {
		fprintf(stdout, "[xcc::tval] test: OK!\n");
	}
	
	tmpProc.print_summary("xxx");
	
	
	return 0;
}
