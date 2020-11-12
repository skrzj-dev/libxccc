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

#ifndef _TEST_STRINGCS_ABSTRACTS_INIT_CSTR_HPP_
#define _TEST_STRINGCS_ABSTRACTS_INIT_CSTR_HPP_
/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2_paramrow.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */


template<typename TPL_STROBJ>
class subtest_fnInitCstr_Mutable: public test_xcStringS_testStaticStr_sub_I<TPL_STROBJ>
{
	protected: test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* intfs;
	
	protected: virtual int testedOp(TPL_STROBJ* target, const char* param)
	{
		return intfs->INTF_STATICSTR->init_cstr(target, param);
	}
	
	public: subtest_fnInitCstr_Mutable(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs)
	{
		this->intfs=ref_intfs;
	}
	
	typedef xcc_test3_DATAROW4_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, const char*
	) init_paramsError_expectError_paramRow_t;

	typedef xcc_test3_DATAROW5_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, const char*
		, testParamValued01<TPL_STROBJ>
	) init_paramsError_expectResultOk_paramRow_t;
	
	public: int init_paramsError_expectError(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> selfI
		, const char* param_cstr
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				xcc_test2_expect( 0 == selfI.intf->prepareState2(*failInfo, ptr_self_state, selfI.value) );
				
				xcc_test2_expect( 0 != testedOp(ptr_self_state->refp_obj_operational, param_cstr) );
				
				xcc_test2_expect( 0 == selfI.intf->verifyState(*failInfo, ptr_self_state, selfI.value) );
				
				xcc_test2_expect( 0 == selfI.intf->deinit(*failInfo, ptr_self_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}

	
	public: int init_paramsError_expectResultOk(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> target1
		, const char* param_cstr
		, testParamValued01<TPL_STROBJ> result
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				test_xcStringS_state<TPL_STROBJ> result_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_result_state=&result_state;
				
				xcc_test2_expect( 0 == target1.intf->prepareState2(*failInfo, ptr_self_state, target1.value) );
				xcc_test2_expect( 0 == target1.intf->verifyState(*failInfo, ptr_self_state, target1.value) );
				
				xcc_test2_expect( 0 == result.intf->prepareState2(*failInfo, &result_state, result.value) );
				xcc_test2_expect( 0 == result.intf->verifyState(*failInfo, ptr_result_state, result.value) );
				
				xcc_test2_expect( 0 == testedOp(ptr_self_state->refp_obj_operational, param_cstr) );
				
				xcc_test2_expect( 0 == result.intf->verifyState(*failInfo, ptr_result_state, result.value) );

				xcc_test2_expect( 0 == target1.intf->deinit(*failInfo, ptr_self_state) );
				xcc_test2_expect( 0 == result.intf->deinit(*failInfo, ptr_result_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	
	public: int perform(xcc_test2_param_list)
	{
		return test_fnInitCstr(xcc_test2_param_list_forward);
	}

	public: int test_fnInitCstr(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[init/deinit/raii]");
		
		if(1)
		{
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", xcc_test2_case_referp_customFailInfo(), intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsNull->value(), NULL
				)
				, xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", xcc_test2_case_referp_customFailInfo(), intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsNull->value(), "" 
				)
				, xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", xcc_test2_case_referp_customFailInfo(), intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsNull->value(), "abcd123" 
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.01,null self]"
				, "ERROR-ANY-PARAM-NULL"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitZero->value(), NULL
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.02, uninit self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitNonZero->value(), NULL
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.03, uninit self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitEmpty->value(), NULL
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.03, init empty self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), NULL
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.04, init nonempty self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectResultOk_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitZero->value(), "", intfs->INTF_SET->strcsInitEmpty->value() 
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var2", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitZero->value(), "1", intfs->INTF_SET->strcsInitNonEmpty->value("1") 
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var3", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitZero->value(), "abcdegh12345", intfs->INTF_SET->strcsInitNonEmpty->value("abcdegh12345") 
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "init-cstr-deinit[ok-param.01, uninit zero self]"
				, "INIT-OK-OTHER-PARAM-ANY-INIT-FROM-ANY-UNINIT"
				, init_paramsError_expectResultOk_paramRow_t
				, init_paramsError_expectResultOk
				, rows
			);
		}

		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectResultOk_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitNonZero->value(), "", intfs->INTF_SET->strcsInitEmpty->value() 
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var2", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitNonZero->value(), "1", intfs->INTF_SET->strcsInitNonEmpty->value("1") 
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var3", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitNonZero->value(), "abcdegh12345", intfs->INTF_SET->strcsInitNonEmpty->value("abcdegh12345") 
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "init-cstr-deinit[ok-param.02, uninit nonzero self]"
				, "INIT-OK-OTHER-PARAM-ANY-INIT-FROM-ANY-UNINIT"
				, init_paramsError_expectResultOk_paramRow_t
				, init_paramsError_expectResultOk
				, rows
			);
		}
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectResultOk_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitEmpty->value(), "", intfs->INTF_SET->strcsInitEmpty->value()
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var2", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitEmpty->value(), "1", intfs->INTF_SET->strcsInitNonEmpty->value("1")
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var3", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitEmpty->value(), "abcdegh12345", intfs->INTF_SET->strcsInitNonEmpty->value("abcdegh12345")
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "init-cstr-deinit[ok-param.03, init empty self]"
				, "INIT-ERROR-IF-ALREADY-INITIALIZED"
				, init_paramsError_expectResultOk_paramRow_t
				, init_paramsError_expectResultOk
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectResultOk_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwertyuiop12345"), "", intfs->INTF_SET->strcsInitEmpty->value()
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var2", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwertyuiop12345"), "1", intfs->INTF_SET->strcsInitNonEmpty->value("1")
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var3", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwertyuiop12345"), "abcdegh12345", intfs->INTF_SET->strcsInitNonEmpty->value("abcdegh12345")
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "init-cstr-deinit[ok-param.04, init nonempty self]"
				, "INIT-ERROR-IF-ALREADY-INITIALIZED"
				, init_paramsError_expectResultOk_paramRow_t
				, init_paramsError_expectResultOk
				, rows
			);
		}
			

		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */

		xcc_test2_scope_end();
		
	}
};


template<typename TPL_STROBJ>
class subtest_fnInitCstr_Immutable: public test_xcStringS_testStaticStr_sub_I<TPL_STROBJ>
{
	protected: test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* intfs;
	
	public: subtest_fnInitCstr_Immutable(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs)
	{
		this->intfs=ref_intfs;
	}
	
	protected: virtual int testedOp(TPL_STROBJ* target, const char* param)
	{
		return intfs->INTF_STATICSTR->init_cstr(target, param);
	}
	
	typedef xcc_test3_DATAROW4_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, const char*
	) init_paramsError_expectError_paramRow_t;

	typedef xcc_test3_DATAROW5_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, const char*
		, testParamValued01<TPL_STROBJ>
	) init_paramsError_expectResultOk_paramRow_t;
	
	public: int init_paramsError_expectError(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> selfI
		, const char* param_cstr
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				xcc_test2_expect( 0 == selfI.intf->prepareState2(*failInfo, ptr_self_state, selfI.value) );
				
				xcc_test2_expect( 0 != testedOp(ptr_self_state->refp_obj_operational, param_cstr) );
				
				xcc_test2_expect( 0 == selfI.intf->verifyState(*failInfo, ptr_self_state, selfI.value) );
				
				xcc_test2_expect( 0 == selfI.intf->deinit(*failInfo, ptr_self_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}

	
	public: int init_paramsError_expectResultOk(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> target1
		, const char* param_cstr
		, testParamValued01<TPL_STROBJ> result
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				test_xcStringS_state<TPL_STROBJ> result_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_result_state=&result_state;
				
				xcc_test2_expect( 0 == target1.intf->prepareState2(*failInfo, ptr_self_state, target1.value) );
				xcc_test2_expect( 0 == target1.intf->verifyState(*failInfo, ptr_self_state, target1.value) );
				
				xcc_test2_expect( 0 == result.intf->prepareState2(*failInfo, &result_state, result.value) );
				xcc_test2_expect( 0 == result.intf->verifyState(*failInfo, ptr_result_state, result.value) );
				
				xcc_test2_expect( 0 == testedOp(ptr_self_state->refp_obj_operational, param_cstr) );
				
				xcc_test2_expect( 0 == result.intf->verifyState(*failInfo, ptr_result_state, result.value) );

				xcc_test2_expect( 0 == target1.intf->deinit(*failInfo, ptr_self_state) );
				xcc_test2_expect( 0 == result.intf->deinit(*failInfo, ptr_result_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	
	public: virtual int perform(xcc_test2_param_list)
	{
		return test_fnInitCstr(xcc_test2_param_list_forward);
	}

	public: int test_fnInitCstr(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[init/deinit/raii]");
		
		if(1)
		{
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", xcc_test2_case_referp_customFailInfo(), intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsNull->value(), NULL
				)
				, xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", xcc_test2_case_referp_customFailInfo(), intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsNull->value(), "" 
				)
				, xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", xcc_test2_case_referp_customFailInfo(), intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsNull->value(), "abcd123" 
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.01,null self]"
				, "ERROR-ANY-PARAM-NULL"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitZero->value(), NULL
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.02, uninit self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitNonZero->value(), NULL
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.03, uninit self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitEmpty->value(), NULL
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.03, init empty self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), NULL
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[err-param.04, init nonempty self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectResultOk_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitZero->value(), "", intfs->INTF_SET->strcsInitEmpty->value() 
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var2", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitZero->value(), "1", intfs->INTF_SET->strcsInitNonEmpty->value("1") 
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var3", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitZero->value(), "abcdegh12345", intfs->INTF_SET->strcsInitNonEmpty->value("abcdegh12345") 
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "init-cstr-deinit[ok-param.01, uninit zero self]"
				, "INIT-OK-OTHER-PARAM-ANY-INIT-FROM-ANY-UNINIT"
				, init_paramsError_expectResultOk_paramRow_t
				, init_paramsError_expectResultOk
				, rows
			);
		}

		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectResultOk_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitNonZero->value(), "", intfs->INTF_SET->strcsInitEmpty->value() 
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var2", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitNonZero->value(), "1", intfs->INTF_SET->strcsInitNonEmpty->value("1") 
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var3", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsUninitNonZero->value(), "abcdegh12345", intfs->INTF_SET->strcsInitNonEmpty->value("abcdegh12345") 
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "init-cstr-deinit[ok-param.02, uninit nonzero self]"
				, "INIT-OK-OTHER-PARAM-ANY-INIT-FROM-ANY-UNINIT"
				, init_paramsError_expectResultOk_paramRow_t
				, init_paramsError_expectResultOk
				, rows
			);
		}
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitEmpty->value(), "" 
				)
				, xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var2", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitEmpty->value(), "1" 
				)
				, xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var3", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitEmpty->value(), "abcdegh12345"
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[ok-param.03, init empty self]"
				, "INIT-ERROR-IF-ALREADY-INITIALIZED"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		if(1)
		{
			xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
			
			init_paramsError_expectError_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var1", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwertyuiop12345"), ""
				)
				, xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var2", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwertyuiop12345"), "1"
				)
				, xcc_test3_DATAROW4_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var3", refp_failReport, intfs->INTF_STATICSTR, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwertyuiop12345"), "abcdegh12345"
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "init-cstr-deinit[ok-param.04, init nonempty self]"
				, "INIT-ERROR-IF-ALREADY-INITIALIZED"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
			

		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */

		xcc_test2_scope_end();
		
	}
};


#endif
