#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1);
    bool CheckInvalid();
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator>(const Date& d);
    bool operator>=(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    
    Date& operator+=(int day);
    Date operator+(int day);
    Date& operator-=(int day);
    Date operator-(int day);

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);

    int operator-(const Date& d);

    int GetMonth(int year, int month)
    {
        assert(month > 0 && month < 13);
        int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400  == 0)))
        {
            return 29;
        }
        return MonthDay[month];
    }

    //void Print()
    //{
    //    cout << _year << "-" << _month << "-" << _day << endl;
    //}

    friend ostream& operator<<(ostream& _cout, const Date& d);
    friend istream& operator>>(istream& _cin, Date& d);
private:
    int _year;
    int _month;
    int _day;
};

ostream& operator<<(ostream& _cout, const Date& d);
istream& operator>>(istream& _cin, Date& d);