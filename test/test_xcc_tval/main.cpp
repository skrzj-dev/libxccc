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

/* --- */
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/common/xcc_err.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "test_tval_main.hpp"
/* ---  */

#define TEST_EXPECT_EQ_STMT(_STMT_) do { if(  0 == (_STMT_) ) { xcc_err_term_unmg(); } } while(0);


/*
 * TODO refactor etc
 * now it's just most elementary test to verify basic arithmetics
 *
 *    +
 *    +=
 *    ++
 *
 *    -
 *    -=
 *    --
 *
 *    *
 *    *=
 *
 *    /
 *    /=
 *
 *    =
 *
 *    ==
 * 
 */

int test_tval_all(void) noexcept
{
	xcc_err_decl();
	
	try
	{
		do
		{
			xcc::tval<int> tmp_1=0;
			
			TEST_EXPECT_EQ_STMT( 0 == tmp_1.val() );
			TEST_EXPECT_EQ_STMT( 0 == tmp_1.ref() );
			TEST_EXPECT_EQ_STMT( 0 == *tmp_1.refp() );

			TEST_EXPECT_EQ_STMT( 11 != tmp_1.val() );
			TEST_EXPECT_EQ_STMT( 11 != tmp_1.ref() );
			TEST_EXPECT_EQ_STMT( 11 != *tmp_1.refp() );
			
		} while(0);

		do
		{
			xcc::tval<int> tmp_1=99;
			
			TEST_EXPECT_EQ_STMT( 99 == tmp_1.val() );
			TEST_EXPECT_EQ_STMT( 99 == tmp_1.ref() );
			TEST_EXPECT_EQ_STMT( 99 == *tmp_1.refp() );
			
			TEST_EXPECT_EQ_STMT( 11 != tmp_1.val() );
			TEST_EXPECT_EQ_STMT( 11 != tmp_1.ref() );
			TEST_EXPECT_EQ_STMT( 11 != *tmp_1.refp() );

			TEST_EXPECT_EQ_STMT( tmp_1.val() == 99 );
			TEST_EXPECT_EQ_STMT( tmp_1.ref() == 99 );
			TEST_EXPECT_EQ_STMT( *tmp_1.refp() == 99 );
			
			TEST_EXPECT_EQ_STMT( tmp_1.val() != 11 );
			TEST_EXPECT_EQ_STMT( tmp_1.ref() != 11 );
			TEST_EXPECT_EQ_STMT( *tmp_1.refp() != 11 );
			
		} while(0);


		do
		{
			xcc::tval<int> tmp_1=2;
			const xcc::tval<int> tmp_2=99;
			
			tmp_1=tmp_2;
			
			TEST_EXPECT_EQ_STMT( 99 == tmp_1.val() );
			TEST_EXPECT_EQ_STMT( 99 == tmp_1.ref() );
			TEST_EXPECT_EQ_STMT( 99 == *tmp_1.refp() );

			TEST_EXPECT_EQ_STMT( 99 == tmp_2.val() );
			TEST_EXPECT_EQ_STMT( 99 == tmp_2.ref() );
			TEST_EXPECT_EQ_STMT( 99 == *tmp_2.refp() );
			
			
		} while(0);

		if(1)
		{

			do
			{
				xcc::tval<int> tmp_1=2;
				
				tmp_1++;
				
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 3 == *tmp_1.refp() );

				tmp_1++;
				
				TEST_EXPECT_EQ_STMT( 4 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 4 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 4 == *tmp_1.refp() );

				
			} while(0);
			
			do
			{
				xcc::tval<int> tmp_1=2;
				
				++tmp_1;
				
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 3 == *tmp_1.refp() );

				++tmp_1;
				
				TEST_EXPECT_EQ_STMT( 4 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 4 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 4 == *tmp_1.refp() );
				
			} while(0);


			do
			{
				xcc::tval<int> tmp_1=2;
				
				tmp_1+=4;
				
				TEST_EXPECT_EQ_STMT( 6 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 6 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 6 == *tmp_1.refp() );

				tmp_1+=3;
				
				TEST_EXPECT_EQ_STMT( 9 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 9 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 9 == *tmp_1.refp() );
				
			} while(0);
			
			do
			{
				xcc::tval<int> tmp_1=2;
				
				int x=4;
				x+=tmp_1.ref();
				
				TEST_EXPECT_EQ_STMT( 2 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 2 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 2 == *tmp_1.refp() );

				int y=3;
				y+=tmp_1.ref();
				
				TEST_EXPECT_EQ_STMT( 2 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 2 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 2 == *tmp_1.refp() );
				
			} while(0);
			
			
			do
			{
				xcc::tval<int> tmp_1=2;
				
				int x=(tmp_1++);
				
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 3 == *tmp_1.refp() );

				TEST_EXPECT_EQ_STMT( 2 == x );
				TEST_EXPECT_EQ_STMT( 2 == x );
				TEST_EXPECT_EQ_STMT( 2 == x );
				
			} while(0);

			do
			{
				xcc::tval<int> tmp_1=2;
				
				int x=(++tmp_1);
				
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 3 == *tmp_1.refp() );

				TEST_EXPECT_EQ_STMT( 3 == x );
				TEST_EXPECT_EQ_STMT( 3 == x );
				TEST_EXPECT_EQ_STMT( 3 == x );
				
			} while(0);
			
		}
	
		if(1)
		{
			do
			{
				xcc::tval<int> tmp_1=6;
				xcc::tval<int> tmp_result=1;
				int result_val=2;
				
				tmp_result=tmp_1/2;
				
				result_val=tmp_1/2;
				
				TEST_EXPECT_EQ_STMT( 6 == tmp_1.val() );
				TEST_EXPECT_EQ_STMT( 6 == tmp_1.ref() );
				TEST_EXPECT_EQ_STMT( 6 == *tmp_1.refp() );

				TEST_EXPECT_EQ_STMT( 3 == tmp_result.val() );
				TEST_EXPECT_EQ_STMT( 3 == result_val );
				
			} while(0);
			
			do
			{
				xcc::tval<int> tmp_1=6;
				
				tmp_1/=2;
				
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.val() );
			
			} while(0);

			do
			{
				xcc::tval<int> tmp_1=6;
				
				tmp_1=tmp_1/2;
				
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.val() );
				
			} while(0);

			do
			{
				xcc::tval<int> tmp_1=1;
				xcc::tval<int> tmp_2=6;
				
				tmp_1=tmp_2/2;
				
				TEST_EXPECT_EQ_STMT( 3 == tmp_1.val() );

				TEST_EXPECT_EQ_STMT( 6 == tmp_2.val() );
				
			} while(0);
		}
		
	
		if(1)
		{
			do
			{
				xcc::tval<int> tmp_1=6;
				xcc::tval<int> tmp_result=1;
				int result_val=2;
				
				tmp_result=tmp_1*2;
				
				result_val=tmp_1*2;
				
				TEST_EXPECT_EQ_STMT( 6 == tmp_1.val() );

				TEST_EXPECT_EQ_STMT( 12 == tmp_result.val() );
				TEST_EXPECT_EQ_STMT( 12 == result_val );
				
			} while(0);
			
			do
			{
				xcc::tval<int> tmp_1=6;
				
				tmp_1*=2;
				
				TEST_EXPECT_EQ_STMT( 12 == tmp_1.val() );
			
			} while(0);

			do
			{
				xcc::tval<int> tmp_1=6;
				
				tmp_1=tmp_1*2;
				
				TEST_EXPECT_EQ_STMT( 12 == tmp_1.val() );
				
			} while(0);

			do
			{
				xcc::tval<int> tmp_1=1;
				xcc::tval<int> tmp_2=6;
				
				tmp_1=tmp_2*2;
				
				TEST_EXPECT_EQ_STMT( 12 == tmp_1.val() );

				TEST_EXPECT_EQ_STMT( 6 == tmp_2.val() );
				
			} while(0);
		}

		return 0;
	}
	catch(...)
	{
		xcc_err_handle();
		return 1;
	}
	
	return 0;
}

int main()
{
	if(0!=test_tval_all() ) {
		fprintf(stdout, "[xcc::tval] test: FAILURE!\n");
		return 1;
	}
	fprintf(stdout, "[xcc::tval] test: OK!\n");
	return 0;
}
