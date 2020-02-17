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

#ifndef _XC_VECTOR_TEST_PERFORMANCE_ABSTRACT_HPP_
#define _XC_VECTOR_TEST_PERFORMANCE_ABSTRACT_HPP_

#include <string>
#include <vector>
/* --- */
#include "xc/test/xc_test_benchmark.h"
#include "xcc/common/xcc_err.hpp"
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test_benchmark.hpp"
/* --- */

namespace VectorPerformanceTest
{


struct bench_dummy_item_t
{
	int number;
	int array[32];
	char str[128];
};

class itemIntf_obj
{
	public: bench_dummy_item_t itz_retv(const int arg_n)
	{
		int n=0;
		bench_dummy_item_t retv={0};
		
		retv.number=arg_n;
		snprintf(retv.str, sizeof(retv.str), "%d", arg_n);
		
		for(n=0;n<32; n++) {
			retv.array[n]=arg_n+100+1;
		}
		
		return retv;
	}
};


class itemIntf_int
{
	public: int itz_retv(const int arg_n)
	{
		
		return 1000+arg_n;
	}
};


};

#endif
