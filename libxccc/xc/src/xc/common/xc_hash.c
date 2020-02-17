/* --- */
#include "xc/common/xc_hash.h"
/* --- */

/* --- --- --- --- */

xc_hash_inputBytes_t xc_hash_inputBytes(const size_t arg_bytesize, const unsigned char* arg_bytePtr)
{
	xc_hash_inputBytes_t retv={0};
	
	retv.bytes=arg_bytePtr;
	retv.bytesize=arg_bytesize;
	
	return retv;
}

xc_hash_inputBytes_t xc_hash_inputBytes_fromCstr(const char* arg_str)
{
	xc_hash_inputBytes_t retv={0};
	
	retv.bytes=(unsigned char*)arg_str;
	retv.bytesize=strlen(arg_str);
	
	return retv;
}

/* --- --- --- --- */

/* 
 * using implementation of hash function: "x65599";
 * multiplicative hash
 * see: "Compilers: Principles, Techniques, and Tools"
 * see: "sdbm", "berkeley db", [http://www.cse.yorku.ca/~oz/hash.html]
 * see: "x65599", [https://www.strchr.com/hash_functions]
 */
int xc_hash_x65599_32(const xc_hash_inputBytes_t arg_input, xc_hash_val32_t* refp_result)
{
	if(1)
	{
		if(NULL==refp_result) {
			return 1;
		}
		if(0 == arg_input.bytesize) {
			return 1;
		}
		if(NULL == arg_input.bytes) {
			return 1;
		}
	}
	/* --- */
	
	if(1)
	{
		unsigned int hash_val=0;
		unsigned int tmpv=0;
		size_t n=0;
		for(n=0; n<arg_input.bytesize; n++)
		{
			tmpv=arg_input.bytes[n];
			hash_val=tmpv + (hash_val << 6) + (hash_val << 16) - hash_val;
		}
		
		refp_result->v.val=hash_val;
	}
	
	return 0;
}

/* 
 * using implementation of hash function: "x65599";
 * multiplicative hash
 * see: "Compilers: Principles, Techniques, and Tools"
 * see: "sdbm", "berkeley db", [http://www.cse.yorku.ca/~oz/hash.html]
 * see: "x65599", [https://www.strchr.com/hash_functions]
 */
int xc_hash_x65599_64(const xc_hash_inputBytes_t arg_input, xc_hash_val64_t* refp_result)
{
	if(1)
	{
		if(NULL==refp_result) {
			return 1;
		}
		if(0 == arg_input.bytesize) {
			return 1;
		}
		if(NULL == arg_input.bytes) {
			return 1;
		}
	}
	/* --- */
	
	if(1)
	{
		uint64_t hash_val=0;
		uint64_t tmpv=0;
		size_t n=0;
		for(n=0; n<arg_input.bytesize; n++)
		{
			tmpv=arg_input.bytes[n];
			hash_val=tmpv + (hash_val << 6) + (hash_val << 16) - hash_val;
		}
		
		refp_result->v.val64=hash_val;
	}
	
	return 0;
}

/* --- --- --- --- */
