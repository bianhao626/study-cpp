#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
// 将以下代码适配到vector和list中做反向迭代器，理解反向迭代器的原理
namespace bit
{
	// 适配器 -- 复用
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> self;
		Iterator _it;

		Reverse_iterator(Iterator it)
			:_it(it)
		{}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		self& operator++()
		{
			--_it;
			return *this;
		}
		self operator++(int)
		{
			self tmp(_it);
			--_it;
			return tmp;
		}
		self& operator--()
		{
			++_it;
			return *this;
		}
		self operator--(int)
		{
			self tmp(_it);
			++_it;
			return tmp;
		}

		bool operator!=(const self& s)
		{
			return _it != s._it;
		}
	};
	// vector和list反向迭代器实现


	//链表
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		//构造函数
		ListNode(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};
	//迭代器
	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		//节点类型的指针
		Node* _node;

		//构造函数
		ListIterator(Node* node)
			:_node(node)
		{}

		//重载前置后置++和前置后置--
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			//调用拷贝构造（默认的浅拷贝构造函数）
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			//调用拷贝构造（默认的浅拷贝构造函数）
			_node = _node->_prev;
			return tmp;
		}

		//解引用
		Ref operator*()
		{
			return _node->_data;
		}
		//it->
		Ptr operator->()
		{
			return &_node->_data;
		}

		//迭代器比较是否相等！=
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		typedef Reverse_iterator<iterator, T&, T*> r_iterator;

		r_iterator rbegin()
		{
			return r_iterator(end());
		}
		r_iterator rend()
		{
			return r_iterator(begin());
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		//const迭代器，内容不能修改
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void Init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}
		list()
		{
			Init();
		}
		//it2(it1)
		list(const list<T>& it)
		{
			Init();
			for (auto& e : it)
			{
				push_back(e);
			}
		}
		void swap_list(list<T>& it)
		{
			std::swap(_head, it._head);
			std::swap(_size, it._size);
		}
		//it2 = it1
		list<T>& operator=(list<T> it)
		{
			//拷贝构造，然后交换，原数据不会变
			swap_list(it);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//push_back
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		//push_front
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		//pop_back
		void pop_back()
		{
			//为什么end()--不可以使用
			erase(--end());
		}
		//pop_front
		void pop_front()
		{
			erase(begin());
		}
		//insert
		void insert(iterator pos, const T& value)
		{
			Node* newnode = new Node(value);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_next = cur;
			newnode->_prev = prev;
			cur->_prev = newnode;
			_size++;
		}
		//erase
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* next = cur->_next;
			Node* prev = cur->_prev;
			prev->_next = next;
			next->_prev = prev;
			delete cur;

			_size--;
			return iterator(next);
		}
		//size
		size_t size()
		{
			return _size;
		}
		//empty
		bool empty()
		{
			return _size == 0;
		}
	private:
		Node* _head;
		size_t _size;
	};


	//vector
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef Reverse_iterator<iterator, T&, T*> r_iterator;

		r_iterator rbegin()
		{
			return r_iterator(end());
		}
		r_iterator rend()
		{
			return r_iterator(begin());
		}

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
			for (auto e : v)
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
}
