#pragma once
#include<iostream>
using namespace std;

namespace kuto
{
	template<class T, size_t N = 10>
	class array
	{
	public:
		size_t size() const;
	private:
		T _array[N];
		size_t _size = 0;
	};

	// ģ�嶨�岻������뵽.cpp
	// ���������Ͷ��嶼�ŵ�.h
	template<class T, size_t N>
	size_t array<T, N>::size() const
	{
		T x = 0;
		x += N;
		return _size;
	}

	void func();
}