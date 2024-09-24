#pragma once
#include <iostream>

template<class T>
class SharedPtr
{
private:
	T* ptr;
	int* ref_cnt;

public:
	SharedPtr() :ptr(nullptr), ref_cnt(new int(0)) {}
	SharedPtr(T* p) :ptr(p), ref_cnt(new int(1)) {}
	SharedPtr(const SharedPtr& other) :ptr(other.ptr), ref_cnt(other.ref_cnt) {
		(*ref_cnt)++;
	}
	SharedPtr(SharedPtr&& other) noexcept :ptr(other.ptr), ref_cnt(other.ref_cnt) {
		other.ptr = nullptr;
		other.ref_cnt = nullptr;
	}
	SharedPtr& operator=(const SharedPtr& other) {
		if (this != &other) {
			release();
			ptr = other.ptr;
			ref_cnt = other.ref_cnt;
			(*ref_cnt)++;
		}
		return *this;
	}
	SharedPtr& operator=(SharedPtr&& other) noexcept {
		if (this != &other) {
			release();
			ptr = other.ptr;
			ref_cnt = other.ref_cnt;
			other.ptr = nullptr;
			other.ref_cnt = nullptr;
		}
		return *this;
	}

	T& operator*()const {
		return *ptr;
	}
	T* operator->()const {
		return ptr;
	}

	int use_count()const{
		return *ref_cnt;
	}

	void reset(T* p=nullptr) {
		release();
		if (p) {
			ptr = p;
			ref_cnt = new int(1);
		}
		else {
			ptr = nullptr;
			ref_cnt = new int(0);
		}
	}

	~SharedPtr() {
		release();
	}

private:
	void release() {
		if (ref_cnt && --(*ref_cnt) == 0) {
			delete ptr;
			delete ref_cnt;
		}
	}
};

