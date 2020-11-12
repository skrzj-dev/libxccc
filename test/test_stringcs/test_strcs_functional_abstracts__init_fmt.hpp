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

#ifndef _TEST_STRINGCS_ABSTRACTS_INIT_FMT_HPP_
#define _TEST_STRINGCS_ABSTRACTS_INIT_FMT_HPP_
/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2_paramrow.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */

template<typename TPL_STROBJ>
class subtest_fnInitFmt_Immutable: public subtest_fnInitCstr_Immutable<TPL_STROBJ>
{
	using subtest_fnInitCstr_Immutable<TPL_STROBJ>::intfs;
	using subtest_fnInitCstr_Immutable<TPL_STROBJ>::test_fnInitCstr;
	
	protected: virtual int testedOp(TPL_STROBJ* target, const char* param)
	{
		return intfs->INTF_STATICSTR->init_fmt(target, param);
	}

	public: subtest_fnInitFmt_Immutable(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs)
		: subtest_fnInitCstr_Immutable<TPL_STROBJ>(ref_intfs)
	{
		this->intfs=ref_intfs;
	}
	
	public: int perform(xcc_test2_param_list)
	{
		return test_fnInitCstr(xcc_test2_param_list_forward);
	}

};

#endif