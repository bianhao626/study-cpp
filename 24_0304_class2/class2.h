#pragma once
#include<iostream>
using namespace std;

class MyClass
{
public:
	void Init(int year, int month, int day);
	void Print();

private:
	//�˴�������
	//�����Ͷ�������𣬾�Ҫ���������ռ�
	int _year;
	int _month;
	int _day;
};