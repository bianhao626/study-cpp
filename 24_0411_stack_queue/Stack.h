#pragma once
//#include<vector>
//#include<list>
#include<deque>

namespace kuto
{
	//适配器模式（设计模式）--转换
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		const T& top()
		{
			return _con.back();
		}
	private:
		Container _con;
	};
}