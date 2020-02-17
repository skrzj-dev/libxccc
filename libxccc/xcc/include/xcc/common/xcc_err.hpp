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

#ifndef _XCC_ERR_HPP_
#define _XCC_ERR_HPP_

#include <exception>
#include <cstdio>

/* --- */


namespace xcc
{
	class xcc_err_exception
	{
		public: const char* filename;
		public: const char* fnname;
		public: const char* excname;
		public: int err_line;
		private: char buffer[320];
		protected: int is_managed;
		
		public: int is_managed_get(){
			return this->is_managed;
		}
		
		public: xcc_err_exception()
		{
		}
		
		public: xcc_err_exception(const char* type_str, const char* str_filename, const char* str_fnname, const int line)
		{
			char tmp_buf_filename[64]={0};
			char tmp_buf_fnname[128]={0};

			this->err_line=line;
			this->filename=str_filename ? str_filename  : "<NULL>";
			this->fnname=str_fnname ? str_fnname : "<NULL>" ;
			this->excname=type_str ? type_str : "<NULL>";
			
			snprintf(tmp_buf_filename, sizeof(tmp_buf_filename), "%s", this->filename);
			snprintf(tmp_buf_fnname, sizeof(tmp_buf_fnname), "%s", this->fnname);
			
			snprintf(this->buffer, sizeof(this->buffer), "<%s> from [%s]:[%s]:%d", this->excname, tmp_buf_filename, tmp_buf_fnname, this->err_line);
		}
		
		public: const char* what() const noexcept
		{
			return this->buffer;
		}
	};


	class xcc_err_exception_mg: public xcc::xcc_err_exception
	{
		public: xcc_err_exception_mg(const char* str_filename, const char* str_fnname, const int line)
		:xcc_err_exception("MG TERM", str_filename, str_fnname, line)
		{
			this->is_managed=1;
		}
	};


	class xcc_err_exception_unmg: public xcc::xcc_err_exception
	{
		public: xcc_err_exception_unmg(const char* str_filename, const char* str_fnname, const int line)
		:xcc_err_exception("UNMG TERM", str_filename, str_fnname, line)
		{
			this->is_managed=0;
		}

	};


	class xcc_err_exception_unkn: public xcc::xcc_err_exception
	{
		public: xcc_err_exception_unkn(const char* str_filename, const char* str_fnname, const int line)
		:xcc_err_exception("UNKN EXC", str_filename, str_fnname, 1)
		{
			this->is_managed=0;
		}

	};


	class xcc_err_scopeInfo
	{
		public: xcc_err_exception stored_exception;
		public: const char* filename;
		public: const char* fnname;
		public: int err_line;
		
		public: xcc_err_scopeInfo(const char* str_filename, const char* str_fnname)
		{
			this->err_line=1;
			this->filename=str_filename;
			this->fnname=str_fnname;
			this->stored_exception=xcc_err_exception_unkn(str_filename, str_fnname, 1);
		}
		
		public: ~xcc_err_scopeInfo()
		{
		}
		
		public: int signalize()
		{
			const char* what_str=NULL;
			
			if( 0 == this->stored_exception.is_managed_get() )
			{
				if(NULL==(what_str=stored_exception.what() ) ) {
					what_str="<NULL error information>";
				}
				
				fprintf(stdout, "[%s]\n", what_str);
				
			}
			
			return 0;
		}
		
	};
	
};
/* --- */


#define xcc_err_decl()\
	xcc::xcc_err_scopeInfo err_scope_data(__FILE__, __FUNCTION__);\
	;


#define xcc_err_term_mg() do {\
		err_scope_data.stored_exception=xcc::xcc_err_exception_mg(__FILE__, __FUNCTION__, __LINE__);\
		throw err_scope_data.stored_exception;\
	} while(0);


#define xcc_err_term_unmg() do {\
		err_scope_data.stored_exception=xcc::xcc_err_exception_unmg(__FILE__, __FUNCTION__, __LINE__);\
		throw err_scope_data.stored_exception;\
	} while(0);

#define xcc_err_handle() do { \
		err_scope_data.signalize();\
	} while(0);


/* --- --- --- --- */


#define xcc_err_term_mg() do {\
		err_scope_data.stored_exception=xcc::xcc_err_exception_mg(__FILE__, __FUNCTION__, __LINE__);\
		throw err_scope_data.stored_exception;\
	} while(0);


#define xcc_err_term_unmg() do {\
		err_scope_data.stored_exception=xcc::xcc_err_exception_unmg(__FILE__, __FUNCTION__, __LINE__);\
		throw err_scope_data.stored_exception;\
	} while(0);

#define xcc_err_handle() do { \
		err_scope_data.signalize();\
	} while(0);


#define xcc_err_try_unmg(_STMT_) do {\
		if( _STMT_ ) {\
			xcc_err_term_unmg();\
		}\
	} while(0);


#endif
