#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

namespace kuto
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		//构造函数
		ListNode(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
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

	//template<class T>
	//struct ListConstIterator
	//{
	//	typedef ListNode<T> Node;
	//	typedef ListConstIterator<T> Self;
	//	//节点类型的指针
	//	Node* _node;

	//	//构造函数
	//	ListConstIterator(Node* node)
	//		:_node(node)
	//	{}

	//	//重载前置后置++和前置后置--
	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	Self operator++(int)
	//	{
	//		Self tmp(*this);
	//		//调用拷贝构造（默认的浅拷贝构造函数）
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	Self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}
	//	Self operator--(int)
	//	{
	//		Self tmp(*this);
	//		//调用拷贝构造（默认的浅拷贝构造函数）
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	//解引用
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	//it->
	//	const T* operator->()
	//	{
	//		return &_node->_data;
	//	}

	//	//迭代器比较是否相等！=
	//	bool operator!=(const Self& it)
	//	{
	//		return _node != it._node;
	//	}
	//};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

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
			//Node* newnode = new Node(x);
			//Node* tail = _head->_prev;

			//newnode->_next = _head;
			//newnode->_prev = tail;
			//tail->_next = newnode;
			//_head->_prev = newnode;
			
			//相当于是尾插
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

	template<class T>
	void Print(const list<T>& ctl)
	{
		//list<T>::const_iterator是一个依赖于模板参数T的类型，
		//所以需要typename关键字来告诉编译器这是一个类型名称，而不是一个成员变量或者函数。
		typename list<T>::const_iterator it = ctl.begin();
		while (it != ctl.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void Print(const list<int>& ctl)
	{
		list<int>::const_iterator it = ctl.begin();
		while (it != ctl.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}