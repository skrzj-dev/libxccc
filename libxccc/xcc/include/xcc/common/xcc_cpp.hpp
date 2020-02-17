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

#ifndef _XCC_CPP_HPP_
#define _XCC_CPP_HPP_

#include <exception>
#include <cstring>

namespace xcc
{
	
	template<typename TPL_OBJT>
	class tval
	{
		private: TPL_OBJT val_obj;
		
		public: tval() noexcept {
			this->val_obj=0;
		}
		
		public: tval(const TPL_OBJT val) noexcept {
			this->val_obj=val;
		}
		
		public: ~tval() noexcept {
			
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT get_val() const noexcept {
			return this->val_obj;
		}
		public: TPL_OBJT get_val() noexcept {
			return this->val_obj;
		}
		public: TPL_OBJT val() noexcept {
			return this->val_obj;
		}
		public: TPL_OBJT val() const noexcept {
			return this->val_obj;
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT& get_ref() noexcept {
			return this->val_obj;
		}
		public: const TPL_OBJT& get_ref() const noexcept {
			return this->val_obj;
		}
		public: TPL_OBJT& ref() noexcept {
			return this->val_obj;
		}
		public: const TPL_OBJT& ref() const noexcept {
			return this->val_obj;
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT* get_refp() noexcept {
			return &this->val_obj;
		}
		public: const TPL_OBJT* get_refp() const noexcept {
			return &this->val_obj;
		}
		public: TPL_OBJT* refp() noexcept {
			return &this->val_obj;
		}
		public: const TPL_OBJT* refp() const noexcept {
			return &this->val_obj;
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT assign(const TPL_OBJT& val) noexcept {
			return this->val_obj=val;
		}
		public: TPL_OBJT assign(const tval<TPL_OBJT>& ref_other) noexcept {
			this->val_obj=ref_other.get_ref();
			return this->val_obj;
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT operator = (const tval<TPL_OBJT>& ref_other) noexcept {
			return this->assign(ref_other);
		}
		public: TPL_OBJT operator = (const TPL_OBJT val_other) noexcept {
			return this->assign(val_other);
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT operator + (const tval<TPL_OBJT>& ref_other) noexcept {
			return this->val_obj + ref_other.ref();
		}
		public: TPL_OBJT operator + (const TPL_OBJT val_other) noexcept {
			return this->val_obj + val_other;
		}
		public: TPL_OBJT operator ++ () noexcept {
			++ this->val_obj;
			return this->val_obj; 
		}
		public: TPL_OBJT operator ++ (int) noexcept {
			return this->val_obj++;
		}
		public: TPL_OBJT operator += (const tval<TPL_OBJT>& ref_other) noexcept {
			this->val_obj += ref_other.ref();
			return this->val_obj;
		}
		public: TPL_OBJT operator += (const TPL_OBJT val_other) noexcept {
			this->val_obj += val_other;
			return this->val_obj;
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT operator - (const tval<TPL_OBJT>& ref_other) noexcept {
			return this->val_obj - ref_other.ref();
		}
		public: TPL_OBJT operator - (const TPL_OBJT val_other) noexcept {
			return this->val_other - val_other;
		}
		public: TPL_OBJT operator -- () noexcept {
			-- this->val_obj; 
			return *this; 
		}
		public: TPL_OBJT operator -- (int) noexcept {
			return this->val_obj--;
		}
		public: TPL_OBJT operator -= (const tval<TPL_OBJT>& ref_other) noexcept {
			this->val_obj -= ref_other.ref();
			return this->val_obj;
		}
		public: TPL_OBJT operator -= (const TPL_OBJT val_other) noexcept {
			this->val_obj -= val_other;
			return this->val_obj;
		}
		
		
		/* --- */
		
		
		public: bool operator == (const tval<TPL_OBJT>& ref_other) noexcept {
			return (this->val_obj == ref_other.ref() );
		}
		public: bool operator == (const TPL_OBJT val_other) noexcept {
			return (this->val_obj == val_other);
		}
		
		
		/* --- */
		
		
		public: bool operator != (const tval<TPL_OBJT>& ref_other) noexcept {
			return (this->val_obj != ref_other.ref() );
		}
		public: bool operator != (const TPL_OBJT val_other) noexcept {
			return (this->val_obj != val_other);
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT operator * (const tval<TPL_OBJT>& ref_other) noexcept {
			return this->val_obj * ref_other.ref();
		}
		public: TPL_OBJT operator * (const TPL_OBJT val_other) noexcept {
			return this->val_obj * val_other;
		}
		public: TPL_OBJT operator *= (const tval<TPL_OBJT>& ref_other) noexcept {
			this->val_obj *= ref_other.ref();
			return this->val_obj;
		}
		public: TPL_OBJT operator *= (const TPL_OBJT val_other) noexcept {
			this->val_obj *= val_other;
			return this->val_obj;
		}
		
		
		/* --- */
		
		
		public: TPL_OBJT operator / (const tval<TPL_OBJT>& ref_other) noexcept {
			return this->val_obj / ref_other.ref();
		}
		public: TPL_OBJT operator / (const TPL_OBJT val_other) noexcept {
			return this->val_obj/val_other;
		}
		public: TPL_OBJT operator /= (const tval<TPL_OBJT>& ref_other) noexcept {
			this->val_obj/=ref_other.ref();
			return this->val_obj;
		}
		public: TPL_OBJT operator /= (const TPL_OBJT val_other) noexcept {
			this->val_obj /= val_other;
			return this->val_obj;
		}
		
		
	};
	
	
	template<typename TPL_OBJT>
	class objPtr
	{
		private: TPL_OBJT* ptr;
		
		public: objPtr() {
			this->ptr=nullptr;
		}
		
		public: objPtr(TPL_OBJT* ptr) {
			this->ptr=ptr;
		}
		
		public: ~objPtr() {
			
		}
		
		public: TPL_OBJT* val()  {
			return this->ptr;
		}
		public: void val(TPL_OBJT* arg)  {
			this->ptr=arg;;
		}

		public: TPL_OBJT& ref()  {
			if(nullptr == this->ptr) {
				throw std::exception();
			}
			return *this->ptr;
		}
		
		public: int isNull() const {
			return (nullptr == this->ptr);
		}
		
	};
	
	template<typename TPL_OBJT>
	class objPtrConst
	{
		private: const TPL_OBJT* ptr;
		
		public: objPtrConst() {
			this->ptr=nullptr;
		}
		
		public: objPtrConst(const TPL_OBJT* ptr) {
			this->ptr=ptr;
		}
		
		public: ~objPtrConst() {
			
		}
		
		public: const TPL_OBJT* val()  {
			return this->ptr;
		}
		public: void val(TPL_OBJT* arg)  {
			this->ptr=arg;
		}

		public: const TPL_OBJT& ref()  {
			if(nullptr == this->ptr) {
				throw std::exception();
			}
			return *this->ptr;
		}
		
		public: int isNull() const {
			return (nullptr == this->ptr);
		}

	};
	
	template<typename TPL_OBJT>
	class refp2objPtr
	{
		private: TPL_OBJT** refp2ptr;
		
		public: refp2objPtr() {
			this->refp2ptr=nullptr;
		}
		
		public: refp2objPtr(TPL_OBJT** refp2ptr) {
			this->refp2ptr=refp2ptr;
		}
		
		public: ~refp2objPtr() {
			
		}
		
		public: TPL_OBJT* val()  {
			return this->refp2ptr;
		}

		public: TPL_OBJT& ref()  {
			if(nullptr == this->refp2ptr) {
				throw std::exception();
			}
			return *this->refp2ptr;
		}
		
	};
	
	
	template<typename TPL_OBJT>
	class objArrayPtr
	{
		private: TPL_OBJT* ptr;
		
		public: objArrayPtr() {
			this->ptr=nullptr;
		}
		
		public: objArrayPtr(TPL_OBJT* ptr) {
			this->ptr=ptr;
		}
		
		public: ~objArrayPtr() {
			
		}
		
		public: TPL_OBJT* val()  {
			return this->ptr;
		}

		public: TPL_OBJT& ref()  {
			if(nullptr == this->ptr) {
				throw std::exception();
			}
			return *this->ptr;
		}
		
	};
	
	template<typename TPL_OBJT>
	class objArrayPtrConst
	{
		private: const TPL_OBJT* ptr;
		
		public: objArrayPtrConst() {
			this->ptr=nullptr;
		}
		
		public: objArrayPtrConst(const TPL_OBJT* ptr) {
			this->ptr=ptr;
		}
		
		public: ~objArrayPtrConst() {
			
		}
		
		public: const TPL_OBJT* val()  {
			return this->ptr;
		}

		public: const TPL_OBJT& ref()  {
			if(nullptr== this->ptr) {
				throw std::exception();
			}
			return *this->ptr;
		}
		
	};
};

template <typename TPL_T>
using TVal= xcc::tval<TPL_T>;

template <typename TPL_T>
using TObjRef= xcc::objPtr<TPL_T>;

template <typename TPL_T>
using TConstObjRef= xcc::objPtr<TPL_T>;


#endif
