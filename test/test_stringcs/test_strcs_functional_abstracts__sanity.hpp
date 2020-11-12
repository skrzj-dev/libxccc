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

#ifndef _TEST_STRINGCS_FUNCTIONAL_ABSTRACTS__SANITY_HPP_
#define _TEST_STRINGCS_FUNCTIONAL_ABSTRACTS__SANITY_HPP_

/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2_paramrow.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */

template<typename TPL_STROBJ>
class subtest_sanityCheck: public test_xcStringS_testStaticStr_sub_I<TPL_STROBJ>
{
	private: test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* intfs;
	
	public: subtest_sanityCheck(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs)
	{
		this->intfs=ref_intfs;
	}
	
	
	public: int perform(xcc_test2_param_list)
	{
		return test_init_obj_deinit(xcc_test2_param_list_forward);
	}

	public: int test_init_obj_deinit(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[sanity check]");
		
		if(0)
		{
			xcc_test2_case("nullState");
			if(1)
			{
				xcc_test2_failureDetails_t* failInfo=xcc_test2_case_referp_customFailInfo();
				test_xcStringS_param_I_abstract<TPL_STROBJ>* TMP_INTF=intfs->INTF_SET->strcsNull;
				testParamValued01<TPL_STROBJ> TMPI=TMP_INTF->value();
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;
				
				xcc_test2_expect( 0 == TMPI.intf->prepareState2(*failInfo, ptr_self_state, TMPI.value) );
				xcc_test2_expect( 0 == TMPI.intf->verifyState(*failInfo, ptr_self_state, TMPI.value) );
				
				if(1)
				{
					xcc_test2_expect( NULL == ptr_self_state->refp_obj_operational );
					xcc_test2_expect( 0 == this->intfs->INTF_STATICSTR->get_length(&ptr_self_state->obj_operational) );
					xcc_test2_expect( 0 == this->intfs->INTF_STATICSTR->get_capacity(&ptr_self_state->obj_operational) );
					xcc_test2_expect( NULL == this->intfs->INTF_STATICSTR->cstr(&ptr_self_state->obj_operational) );
				}
				
				if(1)
				{
					xcc_test2_failureDetails_t dummy;
					xcc_test2_expect( 0 != intfs->INTF_SET->strcsInitNonEmpty->verifyState(dummy, ptr_self_state, TMPI.value) );
					xcc_test2_expect( 0 != intfs->INTF_SET->strcsInitEmpty->verifyState(dummy, ptr_self_state, TMPI.value) );
					xcc_test2_expect( 0 != intfs->INTF_SET->strcsUninitZero->verifyState(dummy, ptr_self_state, TMPI.value) );
					xcc_test2_expect( 0 != intfs->INTF_SET->strcsUninitNonZero->verifyState(dummy, ptr_self_state, TMPI.value) );
					xcc_test2_expect( 0 == intfs->INTF_SET->strcsNull->verifyState(dummy, ptr_self_state, TMPI.value) );
				}
				
				xcc_test2_expect( 0 == TMPI.intf->deinit(*failInfo, ptr_self_state) );
				
			}
			xcc_test2_case_end();
		}
		
		xcc_test2_scope_end();
	}
};

#endif
