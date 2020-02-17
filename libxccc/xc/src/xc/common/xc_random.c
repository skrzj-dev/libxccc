#include "stdlib.h"
/* --- */
#include "xc/common/xc_random.h"
/* --- */

int xc_rand_range_int(const int range_min, const int range_max)
{
	int retv=0;
	
	retv=( rand() % (range_max - range_min + 1 ) ) + range_min; /* even if it overflows, it's acceptable */
	
	return retv;
}


unsigned int xc_rand_range_uint(const unsigned int range_min, const unsigned int range_max)
{
	unsigned int retv=0;
	
	retv=( rand() % (range_max - range_min + 1 ) ) + range_min; /* even if it overflows, it's acceptable */
	
	return retv;
}
