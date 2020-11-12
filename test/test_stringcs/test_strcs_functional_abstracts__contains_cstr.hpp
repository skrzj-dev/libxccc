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

#ifndef _TEST_STRINGCS_ABSTRACTS_CONTAINS_HPP_
#define _TEST_STRINGCS_ABSTRACTS_CONTAINS_HPP_
/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2_paramrow.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */


template<typename TPL_STROBJ>
class subtest_containsCstr_tplt: public test_xcStringS_testStaticStr_sub_I<TPL_STROBJ>
{
	protected: test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* intfs;
	protected: virtual int testedOp_cstr(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, const char* param1)=0;
	

	typedef xcc_test3_DATAROW5_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, const char*
		, int
	) test_contains_cstr_paramsError_expectRetv_paramRow_t;
	protected: int test_contains_cstr_paramsError_expectRetv(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> target1
		, const char* cstr_param1
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
				
				xcc_test2_expect( 0 == target1.intf->prepareState2(*failInfo, ptr_self_state, target1.value) );
				
				xcc_test2_expect( resultval == testedOp_cstr(strIntf, ptr_self_state->refp_obj_operational, cstr_param1) );
				
				xcc_test2_expect( 0 == target1.intf->verifyState(*failInfo, ptr_self_state, target1.value.c_str()) );
				
				xcc_test2_expect( 0 == target1.intf->deinit(*failInfo, ptr_self_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	typedef xcc_test3_DATAROW4_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, int
	) test_contains_cstr_againstItself_expectRetv_paramRow_t;
	private: int test_contains_cstr_againstItself_expectRetv(
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
				
				xcc_test2_expect( resultval == testedOp_cstr( 
						  strIntf
						, ptr_self_state->refp_obj_operational
						, strIntf->cstr( ptr_self_state->refp_obj_operational)  
					) 
				);
				
				xcc_test2_expect( 0 == self.intf->verifyState(*failInfo, ptr_self_state, self.value.c_str() ) );
				
				xcc_test2_expect( 0 == self.intf->deinit(*failInfo, ptr_self_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	
	public: subtest_containsCstr_tplt(
		  test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs
	) 
	{
		this->intfs=ref_intfs;
	}
	

	public: int test_contains_strc_ANYCASE(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[contains-cstr-anycase]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		/* errors: */
		if(1)
		{
			if(1)
			{
				test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsNull->value(), NULL, 0
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsNull->value(), "", 0
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var3"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsNull->value(), "abcd123", 0
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "contains-cstr-[err-param.01,null self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_contains_cstr_paramsError_expectRetv_paramRow_t
					, test_contains_cstr_paramsError_expectRetv
					, rows
				);
			}
			
			if(1)
			{
				test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsUninitZero->value(), NULL, 0
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsUninitZero->value(), "", 0
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var3"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsUninitZero->value(), "abcd123", 0
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "contains-cstr-[err-param.02,uninit-zero-self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_contains_cstr_paramsError_expectRetv_paramRow_t
					, test_contains_cstr_paramsError_expectRetv
					, rows
				);
			}
			
			if(1)
			{
				test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsUninitNonZero->value(), NULL, 0
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsUninitNonZero->value(), "", 0
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var3"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsUninitNonZero->value(), "abcd123", 0
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "contains-cstr-[err-param.03,uninit-non-zero-self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_contains_cstr_paramsError_expectRetv_paramRow_t
					, test_contains_cstr_paramsError_expectRetv
					, rows
				);
			}
			
			if(1)
			{
				test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsInitEmpty->value(), NULL, 0
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "contains-cstr-[err-param.04,init-empty.self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_contains_cstr_paramsError_expectRetv_paramRow_t
					, test_contains_cstr_paramsError_expectRetv
					, rows
				);
			}
			
			if(1)
			{
				test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), NULL, 0
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "contains-cstr-[err-param.05,init-non-empty.self]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_contains_cstr_paramsError_expectRetv_paramRow_t
					, test_contains_cstr_paramsError_expectRetv
					, rows
				);
			}
			
			
		}
		/* errors: done */
		
		
		/* itself x itself: */
		if(1)
		{
			if(1)
			{
				test_contains_cstr_againstItself_expectRetv_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW4_ITZ_T(test_contains_cstr_againstItself_expectRetv_paramRow_t, "var1"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsUninitZero->value(), 0
					)
					, xcc_test3_DATAROW4_ITZ_T(test_contains_cstr_againstItself_expectRetv_paramRow_t, "var2"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsUninitNonZero->value(), 0
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow4(
					  "contains-cstr-[err-param.01,self-against-self]"
					, "TODO"
					, test_contains_cstr_againstItself_expectRetv_paramRow_t
					, test_contains_cstr_againstItself_expectRetv
					, rows
				);
			}
			
			if(1)
			{
				test_contains_cstr_againstItself_expectRetv_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW4_ITZ_T(test_contains_cstr_againstItself_expectRetv_paramRow_t, "var1"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsInitEmpty->value(), 0
					)
					, xcc_test3_DATAROW4_ITZ_T(test_contains_cstr_againstItself_expectRetv_paramRow_t, "var2"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123"), 1
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow4(
					  "contains-cstr-[ok-param.01,self-against-self]"
					, "TODO"
					, test_contains_cstr_againstItself_expectRetv_paramRow_t
					, test_contains_cstr_againstItself_expectRetv
					, rows
				);
			}
		}
		/* itself x itself: done */
		
		/* ok params: */
		if(1)
		{
			if(1)
			{
				test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsInitEmpty->value(), "", 0
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), "qwerty386", 1
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsInitNonEmpty->value("xxx.qwerty386"), "qwerty386", 1
					)
					, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
						, refp_failReport, intfs->INTF_STATICSTR
						, intfs->INTF_SET->strcsInitNonEmpty->value("zxcvby386"), "qwerty386", 0
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "contains-cstr-[ok-param.01,exact-match]"
					, "FALSE_RETVV-ANY-PARAM-NULL"
					, test_contains_cstr_paramsError_expectRetv_paramRow_t
					, test_contains_cstr_paramsError_expectRetv
					, rows
				);
			}
		}
		/* ok params: done */
		
		xcc_test2_scope_end();
	}
	
	public: int test_contains_cstr_okParamsMatchCaseInsensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[contains-cstr-matchCaseInsensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz123ABCDZ!@#$%^&*()"), "abcdz123ABCDZ!@#$%^&*()", 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz123ABCDZ!@#$%^&*()"), "ABCDZ123abcdz!@#$%^&*()", 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz123abcdz!@#$%^&*()"), "ABCDZ123ABCDZ!@#$%^&*()", 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("ABCDZ123ABCDZ!@#$%^&*()"), "abcdz123abcdz!@#$%^&*()", 1
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "contains-cstr-[err-param.210.case-insensitive-match]"
				, "FALSE_RETVV-ANY-PARAM-NULL"
				, test_contains_cstr_paramsError_expectRetv_paramRow_t
				, test_contains_cstr_paramsError_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};



template<typename TPL_STROBJ>
class subtest_containsCstr_eqCaseSensitive_tplt: public subtest_containsCstr_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_containsCstr_tplt<TPL_STROBJ>::test_contains_cstr_paramsError_expectRetv_paramRow_t;
	using subtest_containsCstr_tplt<TPL_STROBJ>::intfs;
	using subtest_containsCstr_tplt<TPL_STROBJ>::test_contains_cstr_paramsError_expectRetv;

	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: subtest_containsCstr_eqCaseSensitive_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs): subtest_containsCstr_tplt<TPL_STROBJ>(ref_intfs)
	{
	}
	
	protected: int testedOp_cstr(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, const char* param1)
	{
		return intf->contains_cstr(ref_self, param1);
	}
	
	public: int perform(xcc_test2_param_list)
	{
		int x=0;
		
		x+=this->test_contains_strc_ANYCASE(xcc_test2_param_list_forward);
		x+=this->test_contains_cstr_okParamsMatchCaseSensitive(xcc_test2_param_list_forward);
		
		return x;
	}
	
	public: int test_contains_cstr_okParamsMatchCaseSensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[contains-cstr-matchCaseInsensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), "abcdz.123ABCZ.!@#$%^&*().zyx", 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), "ABCDZ.123abcz.!@#$%^&*().zyx", 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), "ABCZ", 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), "abcz", 1
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "contains-cstr-[ok-param.10110.case-insensitive-match-of-entire-string]"
				, "FALSE_RETVV-ANY-PARAM-NULL"
				, test_contains_cstr_paramsError_expectRetv_paramRow_t
				, test_contains_cstr_paramsError_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
};



template<typename TPL_STROBJ>
class subtest_containsCstr_eqCaseInSensitive_tplt: public subtest_containsCstr_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_containsCstr_tplt<TPL_STROBJ>::test_contains_cstr_paramsError_expectRetv_paramRow_t;
	using subtest_containsCstr_tplt<TPL_STROBJ>::intfs;
	using subtest_containsCstr_tplt<TPL_STROBJ>::test_contains_cstr_paramsError_expectRetv;

	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: subtest_containsCstr_eqCaseInSensitive_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs): subtest_containsCstr_tplt<TPL_STROBJ>(ref_intfs)
	{
	}

	protected: int testedOp_cstr(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, const char* param1)
	{
		return intf->containsNC_cstr(ref_self, param1);
	}
	
	public: int perform(xcc_test2_param_list)
	{
		int x=0;
		
		x+=this->test_contains_strc_ANYCASE(xcc_test2_param_list_forward);
		x+=this->test_containsObj_cstr_okParamsMatchCaseInsensitive(xcc_test2_param_list_forward);
		
		return x;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int test_containsObj_cstr_okParamsMatchCaseInsensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[contains-obj-matchCaseInsensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_contains_cstr_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), "abcdz.123ABCZ.!@#$%^&*().zyx", 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), "ABCDZ.123abcz.!@#$%^&*().zyx", 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), "ABCZ", 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_contains_cstr_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), "abcz", 1
				)
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "contains-cstr-[ok-param.10110.case-insensitive-match-of-entire-string]"
				, "FALSE_RETVV-ANY-PARAM-NULL"
				, test_contains_cstr_paramsError_expectRetv_paramRow_t
				, test_contains_cstr_paramsError_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};

#endif
