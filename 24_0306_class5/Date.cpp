#include"Date.h"

Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
    if (!CheckInvalid())
    {
        cout << "����ʱ�����ǷǷ���" << endl;
    }
}

bool Date::CheckInvalid()
{
    if (_year <=0 || _month <= 0 || _month > 12 || _day <= 0 || _day > GetMonth(_year,_month))
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool Date::operator<(const Date& d)
{
    if (_year < d._year)
    {
        return true;
    }
    else if (_year == d._year)
    {
        if (_month < d._month)
        {
            return true;
        }
        else if (_month == d._month)
        {
            return _day < d._day;
        }
    }
    return false;
}

bool Date::operator==(const Date& d)
{
    return _year == d._year
        && _month == d._month
        && _day == d._day;
}

bool Date::operator<=(const Date& d)
{
    return *this < d || *this == d;
}
bool Date::operator>(const Date& d)
{
    return !(*this <= d);
}
bool Date::operator>=(const Date& d)
{
    return !(*this < d);
}
bool Date::operator!=(const Date& d)
{
    return !(*this == d);
}

Date& Date::operator+=(int day)
{
    _day += day;
    while (_day > GetMonth(_year, _month))
    {
        _day -= GetMonth(_year, _month);
        _month++;
        if (_month == 13)
        {
            _year++;
            _month = 1;
        }
    }
    return *this;
}
Date Date::operator+(int day)
{
    Date tmp(*this);
    //Date tmp = *this;
    // ����д�����ǿ�������--ע�⿽������͸�ֵ֮�������

    //tmp._day += day;
    //while (tmp._day > GetMonth(_year, _month))
    //{
    //    tmp._day -= GetMonth(_year, _month);
    //    tmp._month++;
    //    if (tmp._month == 13)
    //    {
    //        tmp._year++;
    //        tmp._month = 1;
    //    }
    //}
    //return tmp;

    return tmp += day;
}
Date& Date::operator-=(int day)
{
    _day -= day;
    while (_day <= 0)
    {
        _month--;
        if (_month == 0)
        {
            _year--;
            _month = 12;
        }
        _day += GetMonth(_year, _month);
    }
    return *this;
}
Date Date::operator-(int day)
{
    Date tmp = *this;
    tmp += day;
    return tmp;
}
Date& Date::operator++()
{
    return *this += 1;
}
Date Date::operator++(int)
{
    Date tmp = *this;
    *this += 1;
    return tmp;
}
Date& Date::operator--()
{
    return *this -= 1;
}
Date Date::operator--(int)
{
    Date tmp = *this;
    *this -= 1;
    return tmp;
}
//d1 - d2
int Date::operator-(const Date& d)
{
    int flag = 1;
    Date max = *this;
    Date min = d;

    if (*this < d)
    {
        flag = -1;
        max = d;
        min = *this;
    }
    int n = 0;
    while (min <= max)
    {
        ++min;
        n++;
    }
    return n * flag;
}
ostream& operator<<(ostream& _cout, const Date& d)
{
    _cout << d._year << "��" << d._month << "��" << d._day << "��" << endl;
    return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
    while (1)
    {
        _cin >> d._year >> d._month >> d._day;
        if (!d.CheckInvalid())
        {
            cout << "�������ڷǷ�" << endl;
        }
        else
        {
            break;
        }
    }
    return _cin;
}