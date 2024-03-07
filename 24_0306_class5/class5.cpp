//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    Date(const Date& d)//¿½±´¹¹Ôìº¯Êý
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//
//    Date& operator=(const Date& d)
//    {
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//
//        return *this;
//    }
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    Date d1(2022, 2, 2);
//    Date d2(2012, 1, 1);
//    d1 = d2;
//    d1.Print();
//    
//	return 0;
//}

#include"Date.h"
int main()
{
	//Date d1(2024, 1, 29);
	//Date d2 = d1 + 1000;
	//d1.Print();
	//d2.Print();
	//d2 -= 1000;
	//d2.Print();

	//Date d3(2000, 1, 1);
	//++d3;
	//d3.Print();
	//d3++;
	//d3.Print();

	//Date d4(2024, 3, 7);
	//Date d5(2024, 8, 1);
	//cout << d5 - d4 << endl;

	//cout << d4 << d5;

	//Date d6;
	//cin >> d6;
	//cout << d6;

	Date d7(2024, 3, 81);
	cout << d7;
	Date d8;
	cin >> d8;
	cout << d8;
	return 0;
}