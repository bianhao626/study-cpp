#include<iostream>
using namespace std;

#include<list>
int main()
{
	list<int> It;
	It.push_back(1);
	It.push_back(2);
	It.push_back(3);

	list<int>::iterator it = It.begin();
	while (it != It.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;

	It.reverse();
	for (auto e : It)
	{
		cout << e << " ";
	}
	cout << endl;

	It.splice(It.end(), It, It.begin());
	for (auto e : It)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}