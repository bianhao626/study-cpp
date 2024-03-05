#pragma once
#include<iostream>
using namespace std;

class MyClass
{
public:
	void Init(int year, int month, int day);
	void Print();

private:
	//此处是声明
	//声明和定义的区别，就要看开不开空间
	int _year;
	int _month;
	int _day;
};