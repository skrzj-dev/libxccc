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

#ifndef _TEST_STRINGCS_FUNCTIONAL_ABSTRACTS_PARAM_INTFS_HPP_
#define _TEST_STRINGCS_FUNCTIONAL_ABSTRACTS_PARAM_INTFS_HPP_

/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */
#include "xc/common/xc_mem.h"
#include "xc/common/xc_strcs.h"
#include "xc/common/xc_strc_ll.h"
/* --- */

class test_xcStringS_verify_CalcAlloc_I_01: public test_xcStringS_verify_CalcAlloc_I_abstract
{
	public: int calcCapacityAllocForLength(const int length, int& result)
	{
		result=length+2;
		return 0;
	}
};




template <class TPL_STROBJ>
class test_xcStringS_param_I_null_tplt: public test_xcStringS_param_I_abstract<TPL_STROBJ>
{
	public: test_xcStringS_param_I_null_tplt(test_xcStringS_verify_CalcAlloc_I_abstract* arg_calcCapaciity)
		:test_xcStringS_param_I_abstract<TPL_STROBJ>(arg_calcCapaciity)
	{
	}
	
	public: int prepareState2(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* ref_targetState, std::string content) 
	{
		xc_strcs_t* refp_target=&ref_targetState->obj_operational;
		
		xc_mem_bzero_obj(xc_strcs_t, &ref_targetState->obj_initial);
		xc_mem_bzero_obj(xc_strcs_t, &ref_targetState->obj_operational);
		ref_targetState->refp_obj_operational=NULL;
		return 0;
	}
	
	public: int verifyState(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content) 
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state NULL");
			
			failInfo.content="@@@ a10"+std::string("");
			xcc_test2_expect_eq_t(TPL_STROBJ*, NULL, refp_targetState->refp_obj_operational);
			
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}

	public: int deinit(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState) 
	{
		xc_strcs_deinit(&refp_targetState->obj_initial);
		xc_strcs_deinit(&refp_targetState->obj_operational);
		refp_targetState->refp_obj_operational=NULL;

		return 0;
	}
};

template <class TPL_STROBJ>
class test_xcStringS_param_I_uninitNonZero_tplt: public test_xcStringS_param_I_abstract<TPL_STROBJ>
{
	public: test_xcStringS_param_I_uninitNonZero_tplt(test_xcStringS_verify_CalcAlloc_I_abstract* arg_calcCapaciity)
		:test_xcStringS_param_I_abstract<TPL_STROBJ>(arg_calcCapaciity)
	{
	}

	public: int prepareState2(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content)
	{
		xc_strcs_t* refp_target=&refp_targetState->obj_operational;
		
		this->deinit(failInfo, refp_targetState);
		refp_targetState->refp_obj_operational=&refp_targetState->obj_operational;
		memset(refp_target, 0x99, sizeof(xc_strcs_t) );
		return 0;
	}
	
	public: int verifyState(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content) 
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			
			char tmp[255]={0};
			xc_strcs_t* refp_target_casted=refp_targetState->refp_obj_operational;
			const int capacity=refp_target_casted->private_data.strcs_capacity;
			const int length=refp_target_casted->private_data.strcs_len;
			
			failInfo.content="@@@ x10"+std::string(tmp);
			xcc_test2_expect_neq_t(int, 1, xc_strcs_isInit(refp_target_casted) );
			
			unsigned char* bytes=(unsigned char*)refp_target_casted;
			size_t n=0;
			
			for(n=0; n< sizeof(xc_strcs_t); n++)
			{
				xcc_test2_expect( (unsigned char)0x99 == bytes[n] );
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}

	public: int deinit(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState)
	{
		xc_strcs_deinit(&refp_targetState->obj_initial);
		xc_strcs_deinit(&refp_targetState->obj_operational);
		refp_targetState->refp_obj_operational=NULL;

		return 0;
	}
};


template <class TPL_STROBJ>
class test_xcStringS_param_I_uninitZero_tplt: public test_xcStringS_param_I_abstract<TPL_STROBJ>
{
	public: test_xcStringS_param_I_uninitZero_tplt(test_xcStringS_verify_CalcAlloc_I_abstract* arg_calcCapaciity)
		:test_xcStringS_param_I_abstract<TPL_STROBJ>(arg_calcCapaciity)
	{
	}

	public: int prepareState2(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* ref_targetState, std::string content) 
	{
		xc_strcs_t* refp_target=&ref_targetState->obj_operational;
		
		this->deinit(failInfo, ref_targetState);
		ref_targetState->refp_obj_operational=&ref_targetState->obj_operational;
		return 0;
	}
	
	public: int verifyState(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content) 
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			
			char tmp[255]={0};
			xc_strcs_t* refp_target_casted=refp_targetState->refp_obj_operational;
			const int capacity=refp_target_casted->private_data.strcs_capacity;
			const int length=refp_target_casted->private_data.strcs_len;
			
			failInfo.content="@@@ b10:"+std::string(tmp);
			xcc_test2_expect_neq_t(int, 1, xc_strcs_isInit(refp_target_casted) ); // here error

			sprintf(tmp, "%d == %d ?", 0, capacity);
			failInfo.content="@@@ b11:"+std::string(tmp);
			xcc_test2_expect_eq_t(int, 0, capacity );
			
			sprintf(tmp, "%d <= %d ?", length, 0);
			failInfo.content="@@@ b12:"+std::string(tmp);
			xcc_test2_expect(length <= 0);
			
			sprintf(tmp, "%d is true?", (NULL == refp_target_casted->private_data.strcs_buf));
			failInfo.content="@@@ b13:"+std::string(tmp);
			xcc_test2_expect(NULL == refp_target_casted->private_data.strcs_buf);
			
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}

	public: int deinit(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState) 
	{
		xc_strcs_deinit(&refp_targetState->obj_initial);
		xc_strcs_deinit(&refp_targetState->obj_operational);
		refp_targetState->refp_obj_operational=NULL;

		return 0;
	}
};
;


template <class TPL_STROBJ>
class test_xcStringS_param_I_initEmpty_tplt: public test_xcStringS_param_I_abstract<TPL_STROBJ>
{
	public: test_xcStringS_param_I_initEmpty_tplt(test_xcStringS_verify_CalcAlloc_I_abstract* arg_calcCapaciity)
		:test_xcStringS_param_I_abstract<TPL_STROBJ>(arg_calcCapaciity)
	{
	}

	public: int prepareState2(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content) 
	{
		xc_strcs_t* refp_target=&refp_targetState->obj_operational;
		
		xc_mem_bzero_obj(xc_strcs_t, refp_target);
		refp_targetState->refp_obj_operational=&refp_targetState->obj_operational;
		
		if(0 != xc_strcs_fromCstr_init(refp_target, "") ) {
			return 1;
		}
		
		return 0;
	}
	
	public: int verifyState(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content) 
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			
			xc_strcs_t* refp_target_casted=refp_targetState->refp_obj_operational;
		
			failInfo.content="@@@ y1";
			xcc_test2_expect_neq_t(int, 0, refp_target_casted->private_data.strcs_capacity );
			failInfo.content="@@@ y2";
			xcc_test2_expect( refp_target_casted->private_data.strcs_len >= 0);
			failInfo.content="@@@ y3";
			xcc_test2_expect(NULL != refp_target_casted->private_data.strcs_buf);
			
			if(1)
			{
				int diag_retv=0;
				
				diag_retv = xc_strcs_LL_DIAG_verifyIntegrity(refp_target_casted);
				failInfo.content=xcc::test2::helper::cstrfmt_to_string("@@@ y4 114 [%d]...", diag_retv);
				xcc_test2_expect_eq_t(int, 0, diag_retv);
				failInfo.content=xcc::test2::helper::cstrfmt_to_string("@@@ y4 114 [%d] done", diag_retv);
				
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}

	public: int deinit(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState) 
	{
		xc_strcs_deinit(&refp_targetState->obj_initial);
		xc_strcs_deinit(&refp_targetState->obj_operational);
		refp_targetState->refp_obj_operational=NULL;

		return 0;
	}
};
;

template <class TPL_STROBJ>
class test_xcStringS_param_I_initNonEmpty_tplt: public test_xcStringS_param_I_abstract<TPL_STROBJ>
{
	public: test_xcStringS_param_I_initNonEmpty_tplt(test_xcStringS_verify_CalcAlloc_I_abstract* arg_calcCapaciity)
		:test_xcStringS_param_I_abstract<TPL_STROBJ>(arg_calcCapaciity)
	{
	}
	
	public: int prepareState2(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content) 
	{
		xc_strcs_t* refp_target=&refp_targetState->obj_operational;
		
		xc_mem_bzero_obj(xc_strcs_t, refp_target);
		refp_targetState->refp_obj_operational=&refp_targetState->obj_operational;
		
		if(0 != xc_strcs_fromCstr_init(refp_target, content.c_str() ) ) {
			return 1;
		}
		
		return 0;
	}
	
	public: int verifyState(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content_str) 
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			
			xc_strcs_t* refp_target_casted=refp_targetState->refp_obj_operational;
			
			const size_t length=content_str.length();
			int capacity=0;
			
			failInfo.content="@@@ z1";
			xcc_test2_expect( 0 == this->calcCapacity_I->calcCapacityAllocForLength(length, capacity) );
			failInfo.content="@@@ z1 done";
			
			failInfo.content="@@@ z2";
			xcc_test2_expect( NULL != refp_target_casted->private_data.strcs_buf );
			failInfo.content="@@@ z2 done";
			
			failInfo.content="@@@ z4";
			xcc_test2_expect_eq_t(int, capacity, refp_target_casted->private_data.strcs_capacity);
			failInfo.content="@@@ z4 done";
			
			failInfo.content="@@@ z5";
			xcc_test2_expect_eq_t(int, length, refp_target_casted->private_data.strcs_len);
			failInfo.content="@@@ z5 done";

			failInfo.content="@@@ z6";
			xcc_test2_expect( 0 == strcmp(content_str.c_str(), refp_target_casted->private_data.strcs_buf) );
			failInfo.content="@@@ z6 done";
			
			
			if(1)
			{
				
				failInfo.content="@@@ 101";
				xcc_test2_expect( NULL != refp_target_casted->private_data.strcs_buf );
				xcc_test2_expect( refp_target_casted->private_data.strcs_capacity > 0 );
				failInfo.content="@@@ 101 done";

				failInfo.content="@@@ 102";
				size_t calc_length=0;
				calc_length=strlen(refp_target_casted->private_data.strcs_buf);
				xcc_test2_expect_eq_t(size_t, calc_length, ((size_t)refp_target_casted->private_data.strcs_len) );
				failInfo.content="@@@ 102 done";
				
				failInfo.content="@@@ 103";
				unsigned char x=0;
				x=(unsigned char)refp_target_casted->private_data.strcs_buf[refp_target_casted->private_data.strcs_capacity-1];
				xcc_test2_expect_eq_t(unsigned char, x, xc_strc_LL_termC);
				failInfo.content="@@@ 103 done";
				
			}
			
			if(1)
			{
				int diag_retv=0;
				
				diag_retv = xc_strcs_LL_DIAG_verifyIntegrity(refp_target_casted);
				failInfo.content=xcc::test2::helper::cstrfmt_to_string("@@@ 114 [%d]...", diag_retv);
				xcc_test2_expect_eq_t(int, 0, diag_retv);
				failInfo.content=xcc::test2::helper::cstrfmt_to_string("@@@ 114 [%d] done", diag_retv);
				
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}

	public: int deinit(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState) 
	{
		xc_strcs_deinit(&refp_targetState->obj_initial);
		xc_strcs_deinit(&refp_targetState->obj_operational);
		refp_targetState->refp_obj_operational=NULL;
		
		return 0;
	}
};


#endif