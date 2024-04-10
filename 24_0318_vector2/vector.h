#pragma once
#include<iostream>
using namespace std;

#include<assert.h>
namespace kuto
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _end;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _end;
		}

		//构造函数
		vector()
		{}
		vector(size_t n, const T& value = T())
		{
			//_start = new T[n];
			//_end = _endCapacity = _start + n;
			//iterator pos = _start;
			//while (pos < _end)
			//{
			//	*pos = value;
			//	pos++;
			//}
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(value);
			}
		}
		vector(int n, const T& value = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(value);
			}
		}
		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _end = _endCapacity = nullptr;
		}
		//构造函数v1(v2)
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for ( auto e : v )
			{
				push_back(e);
			}
		}
		//赋值重载v1 = v2
		vector<T>& operator=(vector<T> v)
		{
			//开辟临时空间
			//iterator tmp = new T[v.capacity()];
			//memcpy(tmp, v._start, v.size() * sizeof(T));
			//delete[] _start;
			//_start = tmp;
			//_end = tmp + v.size();
			//_endCapacity = tmp + v.capacity();

			
			swap_vector(v);
			return *this;
		}

		//取值重载[]
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return *(_start + pos);
		}

		//模拟实现size
		size_t size() const
		{
			return _end - _start;
		}
		//模拟实现capacity
		size_t capacity() const
		{
			return _endCapacity - _start;
		}
		//empty()模拟实现
		size_t empty() const
		{
			return _start == _end;
		}
		//交换函数模拟实现
		void swap_vector(vector<T> v)
		{
			std::swap(_start, v._start);
			std::swap(_end, v._end);
			std::swap(_endCapacity, v._endCapacity);
		}

		//resize模拟实现
		void resize(size_t n, const T& val = T())
		{
			//如果所需空间n大于目前开辟的空间，则进行新空间的开辟
			if (n > size())
			{
				reserve(n);
				while (_end < _start + n)
				{
					*_end = val;
					_end++;
				}
			}
			else
			{
				//输出的终止位置
				_end = _start + n;
			}
		}
		//reverse扩容函数模拟实现
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//开辟新的空间，然后把旧的空间的值传递给新空间中，之后删除久空间
				iterator tmp = new T[n];
				size_t old_size = size();
				//memcpy(tmp, _start, old_size * sizeof(T));
				//当对象是string这样的类型的时候，就会出现浅拷贝的问题！！！！
				//解决方式，改为赋值即可，会调用string的赋值
				for (size_t i = 0; i < old_size; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;

				_start = tmp;
				_end = tmp + old_size;
				_endCapacity = tmp + n;
			}
		}
		//push_back模拟实现
		void push_back(const T& x)
		{
			//首先查看空间是否满
			if (_end == _endCapacity)
			{
				//进行扩容
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_end = x;
			_end++;
		}
		//pop_back模拟实现
		void pop_back()
		{
			//判断是否为空
			assert(!empty());
			--_end;
		}
		//任意位置插入一个数据模拟实现
		void insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _end);
			//内存空间是否是满的
			if (_end == _endCapacity)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator state = _end - 1;
			while (state >= pos)
			{
				*(state + 1) = *state;
				state--;
			}
			*pos = val;
			_end++;
		}
		//任意位置清除一个数据模拟实现
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _end);
			
			iterator it = pos + 1;
			while (it < _end)
			{
				*(it - 1) = *it;
				it++;
			}
			_end--;
			return pos;
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

	private:
		iterator _start = nullptr;
		iterator _end = nullptr;
		iterator _endCapacity = nullptr;
	};

	template<class T>
	void print_vector(const vector<T>& n)
	{
		for (size_t i = 0; i < n.size(); i++)
		{
			cout << n[i] << " ";
		}
		cout << endl;

		//typename vector<T>::iterator it = n.begin();
		//while (it != n.end())
		//{
		//	cout << *it++ << " ";
		//}
		//cout << endl;
		//for (auto e : n)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;
	}
}