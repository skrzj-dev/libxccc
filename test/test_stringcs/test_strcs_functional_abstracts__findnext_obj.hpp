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

#ifndef TEST_XCSTRINGD_FUNCTIONAL_ABSTRACTS__FINDNEXT_OBJ_HPP
#define TEST_XCSTRINGD_FUNCTIONAL_ABSTRACTS__FINDNEXT_OBJ_HPP
/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2_paramrow.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */


template<typename TPL_STROBJ>
class subtest_findNextObj_anycase_tplt: public test_xcStringS_testStaticStr_sub_I<TPL_STROBJ>
{
	protected: int (*RETVAL)(int arg);
	protected: test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* intfs;
	protected: virtual int testedOp(TPL_STROBJ* ref_self, int off, TPL_STROBJ* param1, test_xcStringS_I_findResult* ref_expected_result)=0;
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: subtest_findNextObj_anycase_tplt(
		  test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs
	) 
	{
		this->RETVAL=NULL;
		this->intfs=ref_intfs;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: typedef xcc_test3_DATAROW5_DECLT(
		  xcc_test2_failureDetails_t*
		, int
		, testParamValued01<TPL_STROBJ>
		, int
		, testParamValued01<TPL_STROBJ>
	) test_findNextObj_ANYCASE_expectError_paramRow_t;
	protected: int test_findNextObj_ANYCASE_expectError_fn(
		  xcc_test2_failureDetails_t* failInfo
		, const int identifier
		, testParamValued01<TPL_STROBJ> self
		, const int off
		, testParamValued01<TPL_STROBJ> param1
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			test_xcStringS_I_findResult expected_result={-1, -1};
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_I_findResult got_result={-1, -1};
				int retv=0;
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				test_xcStringS_state<TPL_STROBJ> param_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_param_state=&param_state;
				
				xcc_test2_expect( 0 == self.intf->prepareState2(*failInfo, ptr_self_state, self.value) );
				xcc_test2_expect( 0 == param1.intf->prepareState2(*failInfo, ptr_param_state, param1.value) );
				
				xcc_test2_expect( (retv=testedOp(
							  ptr_self_state->refp_obj_operational
							, off
							, ptr_param_state->refp_obj_operational
							, &got_result
						) 
					) 
				);
				
				xcc_test2_expect( 0 != retv );
				xcc_test2_expect( expected_result.len  == got_result.len );
				xcc_test2_expect( expected_result.off == got_result.off );
				
				xcc_test2_expect( 0 == self.intf->verifyState(*failInfo, ptr_self_state, self.value.c_str()) );
				xcc_test2_expect( 0 == self.intf->deinit(*failInfo, ptr_self_state) );
				
				xcc_test2_expect( 0 == param1.intf->verifyState(*failInfo, ptr_param_state, param1.value.c_str()) );
				xcc_test2_expect( 0 == param1.intf->deinit(*failInfo, ptr_param_state) );

			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	public: typedef xcc_test3_DATAROW7_DECLT(
		  xcc_test2_failureDetails_t*
		, int
		, testParamValued01<TPL_STROBJ>
		, int
		, testParamValued01<TPL_STROBJ>
		, int
		, test_xcStringS_I_findResult
	) test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t;
	protected: int test_findNextObj_ANYCASE_paramsOk_expectResult_fn(
		  xcc_test2_failureDetails_t* failInfo
		, const int identifier
		, testParamValued01<TPL_STROBJ> self
		, int off
		, testParamValued01<TPL_STROBJ> param1
		, int resultval
		, test_xcStringS_I_findResult expected_result
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_I_findResult got_result={-1, -1};
				int retv=0;
				int param_len=0;
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				test_xcStringS_state<TPL_STROBJ> param_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_param_state=&param_state;
				
				param_len=param1.value.length();
				
				xcc_test2_expect( 0 == self.intf->prepareState2(*failInfo, ptr_self_state, self.value) );
				xcc_test2_expect( 0 == param1.intf->prepareState2(*failInfo, ptr_param_state, param1.value) );
				
				xcc_test2_expect( resultval == (retv=testedOp(
							  ptr_self_state->refp_obj_operational
							, off
							, ptr_param_state->refp_obj_operational
							, &got_result
						) 
					) 
				);
				
				if( 0 == expected_result.len  &&  param_len == got_result.len  ) {
					xcc_test2_expect( param_len == got_result.len );
				}
				else {
					xcc_test2_expect( expected_result.len == got_result.len );
				}
				xcc_test2_expect( expected_result.off == got_result.off );
				
				xcc_test2_expect( 0 == self.intf->verifyState(*failInfo, ptr_self_state, self.value.c_str()) );
				xcc_test2_expect( 0 == self.intf->deinit(*failInfo, ptr_self_state) );
				
				xcc_test2_expect( 0 == param1.intf->verifyState(*failInfo, ptr_param_state, param1.value.c_str()) );
				xcc_test2_expect( 0 == param1.intf->deinit(*failInfo, ptr_param_state) );

			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}


	public: typedef xcc_test3_DATAROW5_DECLT(
		  xcc_test2_failureDetails_t*
		, int
		, testParamValued01<TPL_STROBJ>
		, int
		, test_xcStringS_I_findResult
	) test_findNextObj_againstItself_expectRetv_paramRow_t;
	protected: int test_findNextObj_againstItself_expectRetv(
		  xcc_test2_failureDetails_t* failInfo
		, const int identifier
		, testParamValued01<TPL_STROBJ> self
		, int resultval
		, test_xcStringS_I_findResult expected_result
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_I_findResult got_result={0};
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;
				
				xcc_test2_expect( 0 == self.intf->prepareState2(*failInfo, ptr_self_state, self.value) );
				
				xcc_test2_expect( resultval == testedOp(
						  ptr_self_state->refp_obj_operational
						, 0
						, ptr_self_state->refp_obj_operational
						, &got_result
					)
				);
				
				int self_len=self.value.length();

				if( 0 == expected_result.len  &&  self_len == got_result.len  ) {
					xcc_test2_expect( self_len == got_result.len );
				}
				else {
					xcc_test2_expect( expected_result.len == got_result.len );
				}
				
				xcc_test2_expect( expected_result.off == got_result.off );
				
				xcc_test2_expect( 0 == self.intf->verifyState(*failInfo, ptr_self_state, self.value.c_str() ) );
				xcc_test2_expect( 0 == self.intf->deinit(*failInfo, ptr_self_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	protected: int test_findNextObj_obj_ANYCASE(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[findNextObj]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		
		/* error for invalid params: */
		if(1)
		{
			if(1)
			{
				test_findNextObj_ANYCASE_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var1"
						, refp_failReport, 11
							, intfs->INTF_SET->strcsNull->value(), 0, intfs->INTF_SET->strcsNull->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var2"
						, refp_failReport, 22
							, intfs->INTF_SET->strcsNull->value(), 0, intfs->INTF_SET->strcsUninitZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var3"
						, refp_failReport, 33
							, intfs->INTF_SET->strcsNull->value(), 0, intfs->INTF_SET->strcsUninitNonZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var4"
						, refp_failReport, 44
							, intfs->INTF_SET->strcsNull->value(), 0, intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var5"
						, refp_failReport, 55
							, intfs->INTF_SET->strcsNull->value(), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcd123")
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "findNextObj-[err-param.01,null self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_expectError_paramRow_t
					, test_findNextObj_ANYCASE_expectError_fn
					, rows
				);
			}
			
			if(1)
			{
				test_findNextObj_ANYCASE_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var1"
						, refp_failReport, 11
						, intfs->INTF_SET->strcsUninitZero->value(), 0, intfs->INTF_SET->strcsNull->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var2"
						, refp_failReport, 22
						, intfs->INTF_SET->strcsUninitZero->value(), 0, intfs->INTF_SET->strcsUninitZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var3"
						, refp_failReport, 33
						, intfs->INTF_SET->strcsUninitZero->value(), 0, intfs->INTF_SET->strcsUninitNonZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var4"
						, refp_failReport, 44
						, intfs->INTF_SET->strcsUninitZero->value(), 0, intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var5"
						, refp_failReport, 55
						, intfs->INTF_SET->strcsUninitZero->value(), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcd123")
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "findNextObj-[err-param.02,uninit-zero-self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_expectError_paramRow_t
					, test_findNextObj_ANYCASE_expectError_fn
					, rows
				);
			}
			
			if(1)
			{
				test_findNextObj_ANYCASE_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var1"
						, refp_failReport, 11
						, intfs->INTF_SET->strcsUninitNonZero->value(), 0, intfs->INTF_SET->strcsNull->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var2"
						, refp_failReport, 22
						, intfs->INTF_SET->strcsUninitNonZero->value(), 0, intfs->INTF_SET->strcsUninitZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var3"
						, refp_failReport, 33
						, intfs->INTF_SET->strcsUninitNonZero->value(), 0, intfs->INTF_SET->strcsUninitNonZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var4"
						, refp_failReport, 44
						, intfs->INTF_SET->strcsUninitNonZero->value(), 0, intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var5"
						, refp_failReport, 55
						, intfs->INTF_SET->strcsUninitNonZero->value(), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcd123")
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "findNextObj-[err-param.03,uninit-nonzero.self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_expectError_paramRow_t
					, test_findNextObj_ANYCASE_expectError_fn
					, rows
				);
			}
			
			if(1)
			{
				test_findNextObj_ANYCASE_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var1"
						, refp_failReport, 11
						, intfs->INTF_SET->strcsInitEmpty->value(), 0, intfs->INTF_SET->strcsNull->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var2"
						, refp_failReport, 22
						, intfs->INTF_SET->strcsInitEmpty->value(), 0, intfs->INTF_SET->strcsUninitZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var3"
						, refp_failReport, 33
						, intfs->INTF_SET->strcsInitEmpty->value(), 0, intfs->INTF_SET->strcsUninitNonZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var4"
						, refp_failReport, 44
						, intfs->INTF_SET->strcsInitEmpty->value(), 0, intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var5"
						, refp_failReport, 55
						, intfs->INTF_SET->strcsInitEmpty->value(), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcd123")
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "findNextObj-[err-param.04,init-empty.self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_expectError_paramRow_t
					, test_findNextObj_ANYCASE_expectError_fn
					, rows
				);
			}
			
			if(1)
			{
				test_findNextObj_ANYCASE_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var1"
						, refp_failReport, 140011
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsNull->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var2"
						, refp_failReport, 140022
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsUninitZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var3"
						, refp_failReport, 140033
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsUninitNonZero->value()
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var11"
						, refp_failReport, 140055
						, intfs->INTF_SET->strcsInitNonEmpty->value("q"), 1, intfs->INTF_SET->strcsInitNonEmpty->value("aaa")
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var11"
						, refp_failReport, 140055
						, intfs->INTF_SET->strcsInitNonEmpty->value("q"), 1, intfs->INTF_SET->strcsInitNonEmpty->value("a")
					)
					, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var12"
						, refp_failReport, 140066
						, intfs->INTF_SET->strcsInitNonEmpty->value("q"), -1, intfs->INTF_SET->strcsInitNonEmpty->value("a")
					)
					//, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var5"
					//	, refp_failReport, 55
					//	, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcd123")
					//)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "findNextObj-[err-param.05,init-non-empty.self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_expectError_paramRow_t
					, test_findNextObj_ANYCASE_expectError_fn
					, rows
				);
			}
		}
		/* error for invalid params: done */
		
		/* OK params, success result: */
		if(1)
		{
			if(1)
			{
				test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var12"
						, refp_failReport, 150033
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abc")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var12.0"
						, refp_failReport, 150032
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitEmpty->value()
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var12.1"
						, refp_failReport, 150034
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty387")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_expectError_paramRow_t, "var12.3"
						, refp_failReport, 150035
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty38121212121217")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var13"
						, refp_failReport, 150044
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386")
						, 0, test_xcStringS_I_findResult::GET_VALID(0)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var14"
						, refp_failReport, 150055
						, intfs->INTF_SET->strcsInitNonEmpty->value("0123.qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386")
						, 0, test_xcStringS_I_findResult::GET_VALID(5)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var15"
						, refp_failReport, 150066
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386.YYYY"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386")
						, 0, test_xcStringS_I_findResult::GET_VALID(0)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var16"
						, refp_failReport, 150077
						, intfs->INTF_SET->strcsInitNonEmpty->value("0123.qwerty386.YYYY"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386")
						, 0, test_xcStringS_I_findResult::GET_VALID(5)
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow7(
					  "findNextObj-[ok-param.01,exact-match]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
					, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
					, rows
				);
			}

			if(1)
			{
				test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
						, refp_failReport, 11
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitEmpty->value()
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var2"
						, refp_failReport, 22
						, intfs->INTF_SET->strcsInitNonEmpty->value("1"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("123abcd")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var3"
						, refp_failReport, 33
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcd123456"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var4"
						, refp_failReport, 44
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcd123456")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var5"
						, refp_failReport, 55
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386abcd123456789abcd")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var11"
						, refp_failReport, 1011
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty387")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var12"
						, refp_failReport, 1012
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("awerty387")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow7(
					  "findNextObj-[ok-param.01,absolute-no-match]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
					, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
					, rows
				);
			}

			if(1)
			{
				test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
						, refp_failReport, 11
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("123qwerty386")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var2"
						, refp_failReport, 22
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386123")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var3"
						, refp_failReport, 33
						, intfs->INTF_SET->strcsInitNonEmpty->value("0123.qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386")
						, 0, test_xcStringS_I_findResult::GET_VALID(5)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var4"
						, refp_failReport, 44
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386.123"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386")
						, 0, test_xcStringS_I_findResult::GET_VALID(0)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var5"
						, refp_failReport, 55
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty38x")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var6"
						, refp_failReport, 66
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty38x"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow7(
					  "findNextObj-[ok-param.01,partial-no-match]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
					, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
					, rows
				);
			}
			
			if(1)
			{
				test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
						, refp_failReport, 11
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zy1")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var2"
						, refp_failReport, 22
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx1")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var3"
						, refp_failReport, 33
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx1234")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var4"
						, refp_failReport, 44
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("cdz.123ABCZ.!@#$%^&*().zyx")
						, 0, test_xcStringS_I_findResult::GET_VALID(2)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var5"
						, refp_failReport, 55
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("x")
						, 0, test_xcStringS_I_findResult::GET_VALID(27)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var6"
						, refp_failReport, 66
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("[")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var7"
						, refp_failReport, 77
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value(".zyx")
						, 0, test_xcStringS_I_findResult::GET_VALID(24)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var8"
						, refp_failReport, 88
						, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value(".zy1")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow7(
					  "findNextObj-[ok-param.112.case-sensitive-match-of-substring-edge-cases]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
					, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
					, rows
				);
			}
			
			if(1)
			{
/*
abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd.
0...................x..............x....
0...................20.............x....
0...................20.............35..39
*/
				test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
						, refp_failReport, 11
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (0), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_VALID(0)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var2"
						, refp_failReport, 22
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (0+1), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_VALID(20)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var3"
						, refp_failReport, 33
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (20), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_VALID(20)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var4"
						, refp_failReport, 44
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (20+1), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_VALID(35)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var5"
						, refp_failReport, 55
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (35), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_VALID(35)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var6"
						, refp_failReport, 66
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (35+1), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var7"
						, refp_failReport, 77
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (38), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var8"
						, refp_failReport, 88
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (39), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var9"
						, refp_failReport, 99
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (39+1), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, -1, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var10"
						, refp_failReport, 100
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd."), (39+2), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, -1, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow7(
					  "findNextObj-[ok-param.211.anycase-continuous-find-next]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
					, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
					, rows
				);
			}
			
			
			if(1)
			{
/*
abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd.
0...................x..............x....
0...................20.............x....
0...................20.............35..39
*/
				test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
						, refp_failReport, 11
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd"), (0), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_VALID(0)
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var8"
						, refp_failReport, 88
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd"), (37), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var8"
						, refp_failReport, 88
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd"), (38), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, 0, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var9"
						, refp_failReport, 99
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd"), (39+1), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, -1, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var10"
						, refp_failReport, 100
						, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%.abcd.^&*().zyx.abcd"), (39+2), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, -1, test_xcStringS_I_findResult::GET_INVALID()
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow7(
					  "findNextObj-[ok-param.211.anycase-continuous-find-next]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
					, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
					, rows
				);
			}
			
		}
		/* OK params, success result: done */

		if(1)
		{
			test_findNextObj_againstItself_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_findNextObj_againstItself_expectRetv_paramRow_t, "var1"
					, refp_failReport, 11
						, intfs->INTF_SET->strcsUninitZero->value()
						, -1, test_xcStringS_I_findResult::GET_INVALID()
				)
				, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_againstItself_expectRetv_paramRow_t, "var2"
					, refp_failReport, 22
						, intfs->INTF_SET->strcsUninitNonZero->value()
						, -1, test_xcStringS_I_findResult::GET_INVALID()
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "findNextObj-[err-param.01,self-against-self]"
				, "TODO"
				, test_findNextObj_againstItself_expectRetv_paramRow_t
				, test_findNextObj_againstItself_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_findNextObj_againstItself_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_findNextObj_againstItself_expectRetv_paramRow_t, "var1"
					, refp_failReport, 11
					, intfs->INTF_SET->strcsInitEmpty->value()
					, -1, test_xcStringS_I_findResult::GET_INVALID()
				)
				, xcc_test3_DATAROW5_ITZ_T(test_findNextObj_againstItself_expectRetv_paramRow_t, "var2"
					, refp_failReport, 22
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "findNextObj-[ok-param.01,self-against-self]"
				, "TODO"
				, test_findNextObj_againstItself_expectRetv_paramRow_t
				, test_findNextObj_againstItself_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};



template<typename TPL_STROBJ>
class subtest_findNextObj_CaseSensitive_tplt: public subtest_findNextObj_anycase_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_findNextObj_anycase_tplt<TPL_STROBJ>::test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t;
	using subtest_findNextObj_anycase_tplt<TPL_STROBJ>::intfs;
	using subtest_findNextObj_anycase_tplt<TPL_STROBJ>::test_findNextObj_ANYCASE_paramsOk_expectResult_fn;
	
	public: subtest_findNextObj_CaseSensitive_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs): subtest_findNextObj_anycase_tplt <TPL_STROBJ>(ref_intfs)
	{
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	protected: int testedOp(TPL_STROBJ* ref_self, int off, TPL_STROBJ* param1, test_xcStringS_I_findResult* ref_expected_result)
	{
		return intfs->INTF_STATICSTR->findNext(ref_self, off, param1, ref_expected_result);
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */

	public: int perform(xcc_test2_param_list)
	{
		int x=0;
		
		x+=this->test_findNextObj_obj_ANYCASE(xcc_test2_param_list_forward);
		x+=this->test_findNextObj_obj_okParamsMatchCaseSensitive(xcc_test2_param_list_forward);
		
		return x;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int test_findNextObj_obj_okParamsMatchCaseSensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[findNextObj-matchCaseSensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
					, refp_failReport, 11
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var2"
					, refp_failReport, 222
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123abcz.!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_INVALID()
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var3"
					, refp_failReport, 33
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_INVALID()
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var4"
					, refp_failReport, 44
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_INVALID()
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow7(
				  "findNextObj-[ok-param.110.case-sensitive-match-of-entire-string]"
				, "FALSE_RETVV-ANY-PARAM-NULL"
				, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
				, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
				, rows
			);
		}
		
		if(1)
		{
			test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
					, refp_failReport, 11
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var2"
					, refp_failReport, 22
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ")
					, 0, test_xcStringS_I_findResult::GET_INVALID()
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var3"
					, refp_failReport, 33
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_VALID(14)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var4"
					, refp_failReport, 44
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("!@#$%^&*().ZYX")
					, 0, test_xcStringS_I_findResult::GET_INVALID()
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow7(
				  "findNextObj-[ok-param.111.case-sensitive-match-of-substring]"
				, "FALSE_RETVV-ANY-PARAM-NULL"
				, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
				, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};


template<typename TPL_STROBJ>
class subtest_findNextObj_CaseInSensitive_tplt: public subtest_findNextObj_anycase_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_findNextObj_anycase_tplt<TPL_STROBJ>::test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t;
	using subtest_findNextObj_anycase_tplt<TPL_STROBJ>::intfs;
	using subtest_findNextObj_anycase_tplt<TPL_STROBJ>::test_findNextObj_ANYCASE_paramsOk_expectResult_fn;

	public: subtest_findNextObj_CaseInSensitive_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs): subtest_findNextObj_anycase_tplt<TPL_STROBJ>(ref_intfs)
	{
	}

	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */

	protected: int testedOp(TPL_STROBJ* ref_self, int off, TPL_STROBJ* param1, test_xcStringS_I_findResult* ref_expected_result)
	{
		return intfs->INTF_STATICSTR->findNextNC(ref_self, off, param1, ref_expected_result);
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */

	public: int perform(xcc_test2_param_list)
	{
		int x=0;
		
		x+=this->test_findNextObj_obj_ANYCASE(xcc_test2_param_list_forward);
		x+=this->test_findNextObj_obj_okParamsMatchCaseInsensitive(xcc_test2_param_list_forward);
		
		return x;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int test_findNextObj_obj_okParamsMatchCaseInsensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[findNextObj-matchCaseInsensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
					, refp_failReport, 11
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var2"
					, refp_failReport, 222
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123abcz.!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var3"
					, refp_failReport, 33
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var4"
					, refp_failReport, 44
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow7(
				  "findNextObj-[ok-param.110.case-INsensitive-match-of-entire-string]"
				, "FALSE_RETVV-ANY-PARAM-NULL"
				, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
				, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
				, rows
			);
		}
		
		if(1)
		{
			test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var1"
					, refp_failReport, 11
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var2"
					, refp_failReport, 22
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ")
					, 0, test_xcStringS_I_findResult::GET_VALID(0)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var3"
					, refp_failReport, 33
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("!@#$%^&*().zyx")
					, 0, test_xcStringS_I_findResult::GET_VALID(14)
				)
				, xcc_test3_DATAROW7_ITZ_T(test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t, "var4"
					, refp_failReport, 44
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), 0, intfs->INTF_SET->strcsInitNonEmpty->value("!@#$%^&*().ZYX")
					, 0, test_xcStringS_I_findResult::GET_VALID(14)
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow7(
				  "findNextObj-[ok-param.111.case-INsensitive-match-of-substring]"
				, "FALSE_RETVV-ANY-PARAM-NULL"
				, test_findNextObj_ANYCASE_paramsOk_expectResult_paramRow_t
				, test_findNextObj_ANYCASE_paramsOk_expectResult_fn
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};

#endif
