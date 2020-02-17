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

#ifndef _XC_VECTOR_TEST_PERFORMANCE_ANY_TEST01_HPP_
#define _XC_VECTOR_TEST_PERFORMANCE_ANY_TEST01_HPP_

#include <string>
/*--- */
#include "xcc/common/xcc_cpp.hpp"
/*--- */
/*--- */


namespace VectorPerformanceTest
{


int xc_svector_test_performance_abstract_power2short_to64K(
	  const std::string operation_name
	, xcc::objPtr<xcc::test::testBenchmarkAction_I> refp_actionObj 
	, xcc::objPtr<xcc::test::testBenchmark01_result> refp_result
);


int xc_svector_test_performance_abstract_power2long_toMax(
	  const std::string operation_name
	, xcc::objPtr<xcc::test::testBenchmarkAction_I> refp_actionObj 
	, xcc::objPtr<xcc::test::testBenchmark01_result> refp_result
);


};

#endif
