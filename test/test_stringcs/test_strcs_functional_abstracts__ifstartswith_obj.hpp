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

#ifndef _TEST_STRINGCS_ABSTRACTS_ifStartsWithObj_HPP_
#define _TEST_STRINGCS_ABSTRACTS_ifStartsWithObj_HPP_
/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2_paramrow.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */


template<typename TPL_STROBJ>
class subtest_ifStartsWithObj_tplt: public test_xcStringS_testStaticStr_sub_I<TPL_STROBJ>
{
	protected: test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* intfs;
	protected: virtual int testedOp(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, TPL_STROBJ* param1)=0;
	
	public: typedef xcc_test3_DATAROW5_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, testParamValued01<TPL_STROBJ>
		, int
	) test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t;
	protected: int test_ifStartsWithObj_ANYCASE_paramsError_expectRetv(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> self
		, testParamValued01<TPL_STROBJ> param1
		, int resultval
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				int retv=0;
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				test_xcStringS_state<TPL_STROBJ> param_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_param_state=&param_state;
				
				xcc_test2_expect( 0 == self.intf->prepareState2(*failInfo, ptr_self_state, self.value) );
				xcc_test2_expect( 0 == param1.intf->prepareState2(*failInfo, ptr_param_state, param1.value) );
				
				xcc_test2_expect( resultval == (retv=testedOp(strIntf, ptr_self_state->refp_obj_operational, ptr_param_state->refp_obj_operational) ) );
				
				xcc_test2_expect( 0 == self.intf->verifyState(*failInfo, ptr_self_state, self.value.c_str()) );
				xcc_test2_expect( 0 == self.intf->deinit(*failInfo, ptr_self_state) );
				
				xcc_test2_expect( 0 == param1.intf->verifyState(*failInfo, ptr_param_state, param1.value.c_str()) );
				xcc_test2_expect( 0 == param1.intf->deinit(*failInfo, ptr_param_state) );

			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}


	public: typedef xcc_test3_DATAROW4_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, int
	) test_ifStartsWithObj_againstItself_expectRetv_paramRow_t;
	protected: int test_ifStartsWithObj_againstItself_expectRetv(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> self
		, int resultval
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
				
				xcc_test2_expect( 0 == self.intf->prepareState2(*failInfo, ptr_self_state, self.value) );
				
				xcc_test2_expect( resultval == testedOp(strIntf, ptr_self_state->refp_obj_operational, ptr_self_state->refp_obj_operational) );
				
				xcc_test2_expect( 0 == self.intf->verifyState(*failInfo, ptr_self_state, self.value.c_str() ) );
				
				xcc_test2_expect( 0 == self.intf->deinit(*failInfo, ptr_self_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	
	public: subtest_ifStartsWithObj_tplt(
		  test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs
	) 
	{
		this->intfs=ref_intfs;
	}
	

	protected: int test_ifStartsWithObj_ANYCASE(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[ifStartsWithObj]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsNull->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsUninitZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsUninitNonZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsInitEmpty->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd123"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[err-param.01,null self]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsNull->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsUninitZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsUninitNonZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsInitEmpty->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd123"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[err-param.02,uninit-zero-self]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsNull->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsUninitZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsUninitNonZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsInitEmpty->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd123"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[err-param.03,uninit-nonzero.self]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsNull->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitNonZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitEmpty->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd123"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[err-param.04,init-empty.self]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsNull->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsUninitZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsUninitNonZero->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitEmpty->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("abcd123"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[err-param.05,init-non-empty.self]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitEmpty->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("XXXX.qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("XXXX.qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("XXXX."), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386.YYYY"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var6"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("XXXX.qwerty386.YYYY"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[ok-param.01,exact-match]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}

		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitEmpty->value(), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("123abcd"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcd123456"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("abcd123456"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386abcd123456789abcd"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[ok-param.01,absolute-no-match]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}

		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("123qwerty386"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386123"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("123.qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386.123"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty38x"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var6"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty38x"), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[ok-param.01,partial-no-match]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zy1"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx1"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx1234"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("cdz.123ABCZ.!@#$%^&*().zyx"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var5"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("x"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var6"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("["), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var7"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value(".zyx"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var8"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value(".zy1"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var9"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ."), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var10"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("A"), 1
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[ok-param.112.case-sensitive-match-of-substring-edge-cases]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_againstItself_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(test_ifStartsWithObj_againstItself_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), 0
				)
				, xcc_test3_DATAROW4_ITZ_T(test_ifStartsWithObj_againstItself_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "ifStartsWithObj-[err-param.01,self-against-self]"
				, "TODO"
				, test_ifStartsWithObj_againstItself_expectRetv_paramRow_t
				, test_ifStartsWithObj_againstItself_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_againstItself_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW4_ITZ_T(test_ifStartsWithObj_againstItself_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), 0
				)
				, xcc_test3_DATAROW4_ITZ_T(test_ifStartsWithObj_againstItself_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123"), 1
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow4(
				  "ifStartsWithObj-[ok-param.01,self-against-self]"
				, "TODO"
				, test_ifStartsWithObj_againstItself_expectRetv_paramRow_t
				, test_ifStartsWithObj_againstItself_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};



template<typename TPL_STROBJ>
class subtest_startsWithObj_CaseSensitive_tplt: public subtest_ifStartsWithObj_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_ifStartsWithObj_tplt<TPL_STROBJ>::test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t;
	using subtest_ifStartsWithObj_tplt<TPL_STROBJ>::intfs;
	using subtest_ifStartsWithObj_tplt<TPL_STROBJ>::test_ifStartsWithObj_ANYCASE_paramsError_expectRetv;
	
	public: subtest_startsWithObj_CaseSensitive_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs): subtest_ifStartsWithObj_tplt <TPL_STROBJ>(ref_intfs)
	{
	}
	
	protected: int testedOp(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, TPL_STROBJ* param1)
	{
		return intf->startsWith(ref_self, param1);
	}
	
	public: int perform(xcc_test2_param_list)
	{
		int x=0;
		
		x+=this->test_ifStartsWithObj_ANYCASE(xcc_test2_param_list_forward);
		x+=this->test_ifStartsWithObj_okParamsMatchCaseSensitive(xcc_test2_param_list_forward);
		
		return x;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int test_ifStartsWithObj_okParamsMatchCaseSensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[ifStartsWithObj-matchCaseSensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123abcz.!@#$%^&*().zyx"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[ok-param.110.case-sensitive-match-of-entire-string]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz."), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ."), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz."), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz."), 0
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[ok-param.111.case-sensitive-match-of-substring]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};


template<typename TPL_STROBJ>
class subtest_startsWithObj_CaseInSensitive_tplt: public subtest_ifStartsWithObj_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_ifStartsWithObj_tplt<TPL_STROBJ>::test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t;
	using subtest_ifStartsWithObj_tplt<TPL_STROBJ>::intfs;
	using subtest_ifStartsWithObj_tplt<TPL_STROBJ>::test_ifStartsWithObj_ANYCASE_paramsError_expectRetv;

	public: subtest_startsWithObj_CaseInSensitive_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs): subtest_ifStartsWithObj_tplt<TPL_STROBJ>(ref_intfs)
	{
	}

	protected: int testedOp(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, TPL_STROBJ* param1)
	{
		return intf->startsWithNC(ref_self, param1);
	}
	
	public: int perform(xcc_test2_param_list)
	{
		int x=0;
		
		x+=this->test_ifStartsWithObj_ANYCASE(xcc_test2_param_list_forward);
		x+=this->test_ifStartsWithObj_okParamsMatchCaseInsensitive(xcc_test2_param_list_forward);
		
		return x;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int test_ifStartsWithObj_okParamsMatchCaseInsensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[ifStartsWithObj-matchCaseInsensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123abcz.!@#$%^&*().zyx"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), 1
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[ok-param.10110.case-insensitive-match-of-entire-string]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ."), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz."), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("abcdz."), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ.123ABCZ.!@#$%^&*().zyx"), intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ."), 1
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifStartsWithObj-[ok-param.10111.case-insensitive-match-of-substring]"
				, "TODO-01"
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifStartsWithObj_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};

#endif
