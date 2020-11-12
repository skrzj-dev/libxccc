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

#ifndef _TEST_STRINGCS_FUNCTIONAL_ABSTRACTS_MAIN_HPP_
#define _TEST_STRINGCS_FUNCTIONAL_ABSTRACTS_MAIN_HPP_

/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
#include "test_strcs_functional_abstracts__init_obj.hpp"
#include "test_strcs_functional_abstracts__init_cstr.hpp"
#include "test_strcs_functional_abstracts__init_fmt.hpp"
#include "test_strcs_functional_abstracts__eq.hpp"
#include "test_strcs_functional_abstracts__sanity.hpp"
#include "test_strcs_functional_abstracts__contains_cstr.hpp"
#include "test_strcs_functional_abstracts__contains_obj.hpp"
#include "test_strcs_functional_abstracts__ifstartswith_obj.hpp"
#include "test_strcs_functional_abstracts__ifstartswith_cstr.hpp"
#include "test_strcs_functional_abstracts__ifendswith_obj.hpp"
#include "test_strcs_functional_abstracts__ifendswith_cstr.hpp"
#include "test_strcs_functional_abstracts__findnext_obj.hpp"
#include "test_strcs_functional_abstracts__findnext_cstr.hpp"
#include "test_strcs_functional_abstracts__substr.hpp"
/* --- */

template<typename TPL_STR_T>
class test_xcStringS_testStaticStr
{
	public: test_xcStringS_testStaticStr(
		  test_xcStringS_I_abstract<TPL_STR_T>* refp_INTF_STATICSTR
		, test_xcStringS_param_I_Set_tplt<TPL_STR_T>* INTF_SET
	);
	
	
	private: test_xcStringS_I_abstract<TPL_STR_T>* INTF_STATICSTR;
	private: test_xcStringS_verify_handleState_I_abstract<TPL_STR_T>* INTF_VERIFY;
	private: test_xcStringS_param_I_Set_tplt<TPL_STR_T>* INTF_SET;
	
	public: test_xcStringS_testStaticStr_intfs_tpl<TPL_STR_T> intfs;
	
	public: int test_sanity(xcc_test2_param_list);
	
	/* --- */ 

	public: int test_init_obj_immutable(xcc_test2_param_list);
	public: int test_initCstr_immutable(xcc_test2_param_list);
	public: int test_initFmt_immutable(xcc_test2_param_list);
	
	public: int test_substrInit_Mutable(xcc_test2_param_list);
	public: int test_substrInit_Immutable(xcc_test2_param_list);
	
	/* --- */ 
	
	public: int test_cmpEq_CaseSensitive(xcc_test2_param_list);
	public: int test_cmpEq_CaseInSensitive(xcc_test2_param_list);
	
	public: int test_containsCstr_caseSensitive(xcc_test2_param_list);
	public: int test_containsCstr_caseInSensitive(xcc_test2_param_list);
	public: int test_containsObj_caseSensitive(xcc_test2_param_list);
	public: int test_containsObj_caseInSensitive(xcc_test2_param_list);

	public: int test_startsWithObj_caseSensitive(xcc_test2_param_list);
	public: int test_startsWithObj_caseInSensitive(xcc_test2_param_list);
	public: int test_startsWithCstr_caseSensitive(xcc_test2_param_list);
	public: int test_startsWithCstr_caseInSensitive(xcc_test2_param_list);
	
	public: int test_EndsWithObj_caseSensitive(xcc_test2_param_list);
	public: int test_EndsWithObj_caseInSensitive(xcc_test2_param_list);
	public: int test_EndsWithCstr_caseSensitive(xcc_test2_param_list);
	public: int test_EndsWithCstr_caseInSensitive(xcc_test2_param_list);
	
	public: int test_findNextObj_caseSensitive(xcc_test2_param_list);
	public: int test_findNextObj_caseInSensitive(xcc_test2_param_list);
	public: int test_findNextCstr_caseSensitive(xcc_test2_param_list);
	public: int test_findNextCstr_caseInSensitive(xcc_test2_param_list);
	
	/* --- */ 
};



template<typename TPL_STR_T>
test_xcStringS_testStaticStr<TPL_STR_T>::test_xcStringS_testStaticStr(
		  test_xcStringS_I_abstract<TPL_STR_T>* refp_INTF_STATICSTR
		, test_xcStringS_param_I_Set_tplt<TPL_STR_T>* INTF_SET
)
{
	
	this->INTF_STATICSTR=refp_INTF_STATICSTR;
	this->INTF_SET=INTF_SET;
	
	intfs=test_xcStringS_testStaticStr_intfs_tpl<TPL_STR_T>(refp_INTF_STATICSTR, INTF_SET);
}


template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_cmpEq_CaseSensitive(xcc_test2_param_list)
{
	subtest_eqCaseSensitive<TPL_STR_T> TESTOBJ=subtest_eqCaseSensitive<TPL_STR_T>(&this->intfs);
	
	return TESTOBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_cmpEq_CaseInSensitive(xcc_test2_param_list)
{
	subtest_eqCaseInSensitive<TPL_STR_T> TESTOBJ=subtest_eqCaseInSensitive<TPL_STR_T>(&this->intfs);
	
	return TESTOBJ.perform(xcc_test2_param_list_forward);
}


template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_sanity(xcc_test2_param_list)
{
	subtest_sanityCheck<TPL_STR_T> TESTCLASS_TMP=subtest_sanityCheck<TPL_STR_T>(&this->intfs);

	return TESTCLASS_TMP.perform(xcc_test2_param_list_forward);
}


template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_init_obj_immutable(xcc_test2_param_list)
{
	subtest_fnInitObj_Immutable_tplt<TPL_STR_T> TESTCLASS_INIT_DEINIT=subtest_fnInitObj_Immutable_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_INIT_DEINIT.perform(xcc_test2_param_list_forward);
}


template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_initCstr_immutable(xcc_test2_param_list)
{
	subtest_fnInitCstr_Immutable<TPL_STR_T> TESTCLASS_INIT_CSTR_DEINIT=subtest_fnInitCstr_Immutable<TPL_STR_T>(&this->intfs);

	return TESTCLASS_INIT_CSTR_DEINIT.perform(xcc_test2_param_list_forward);
}


template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_initFmt_immutable(xcc_test2_param_list)
{
	subtest_fnInitFmt_Immutable<TPL_STR_T> TESTCLASS_INIT_CSTR_DEINIT=subtest_fnInitFmt_Immutable<TPL_STR_T>(&this->intfs);

	return TESTCLASS_INIT_CSTR_DEINIT.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_containsObj_caseSensitive(xcc_test2_param_list)
{
	subtest_containsObj_eqCaseSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_containsObj_eqCaseSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_containsObj_caseInSensitive(xcc_test2_param_list)
{
	subtest_containsObj_eqCaseInSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_containsObj_eqCaseInSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_containsCstr_caseSensitive(xcc_test2_param_list)
{
	subtest_containsCstr_eqCaseSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_containsCstr_eqCaseSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_containsCstr_caseInSensitive(xcc_test2_param_list)
{
	subtest_containsCstr_eqCaseInSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_containsCstr_eqCaseInSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_startsWithObj_caseSensitive(xcc_test2_param_list)
{
	subtest_startsWithObj_CaseSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_startsWithObj_CaseSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_startsWithObj_caseInSensitive(xcc_test2_param_list)
{
	subtest_startsWithObj_CaseInSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_startsWithObj_CaseInSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_startsWithCstr_caseSensitive(xcc_test2_param_list)
{
	subtest_StartsWithCstr_CaseSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_StartsWithCstr_CaseSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_startsWithCstr_caseInSensitive(xcc_test2_param_list)
{
	subtest_StartsWithCstr_CaseInSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_StartsWithCstr_CaseInSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */


template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_EndsWithObj_caseSensitive(xcc_test2_param_list)
{
	subtest_ifEndsWithObj_CaseSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_ifEndsWithObj_CaseSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_EndsWithObj_caseInSensitive(xcc_test2_param_list)
{
	subtest_ifEndsWithObj_CaseInSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_ifEndsWithObj_CaseInSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_EndsWithCstr_caseSensitive(xcc_test2_param_list)
{
	subtest_ifEndsWithCstr_CaseSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_ifEndsWithCstr_CaseSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_EndsWithCstr_caseInSensitive(xcc_test2_param_list)
{
	subtest_ifEndsWithCstr_CaseInSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_ifEndsWithCstr_CaseInSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}


/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_findNextObj_caseSensitive(xcc_test2_param_list)
{
	subtest_findNextObj_CaseSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_findNextObj_CaseSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_findNextObj_caseInSensitive(xcc_test2_param_list)
{
	subtest_findNextObj_CaseInSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_findNextObj_CaseInSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_findNextCstr_caseSensitive(xcc_test2_param_list)
{
	subtest_findNextCstr_CaseSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_findNextCstr_CaseSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_findNextCstr_caseInSensitive(xcc_test2_param_list)
{
	subtest_findNextCstr_CaseInSensitive_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_findNextCstr_CaseInSensitive_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}


/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_substrInit_Mutable(xcc_test2_param_list)
{
	subtest_fnSubstrInit_Mutable_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_fnSubstrInit_Mutable_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

template<typename TPL_STR_T>
int test_xcStringS_testStaticStr<TPL_STR_T>::test_substrInit_Immutable(xcc_test2_param_list)
{
	subtest_fnSubstrInit_Immutable_tplt<TPL_STR_T> TESTCLASS_OBJ=subtest_fnSubstrInit_Immutable_tplt<TPL_STR_T>(&this->intfs);

	return TESTCLASS_OBJ.perform(xcc_test2_param_list_forward);
}

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#endif
