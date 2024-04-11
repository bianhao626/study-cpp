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

		//���캯��
		ListNode(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};


	//������
	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		//�ڵ����͵�ָ��
		Node* _node;

		//���캯��
		ListIterator(Node* node)
			:_node(node)
		{}

		//����ǰ�ú���++��ǰ�ú���--
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			//���ÿ������죨Ĭ�ϵ�ǳ�������캯����
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
			//���ÿ������죨Ĭ�ϵ�ǳ�������캯����
			_node = _node->_prev;
			return tmp;
		}

		//������
		Ref operator*()
		{
			return _node->_data;
		}
		//it->
		Ptr operator->()
		{
			return &_node->_data;
		}

		//�������Ƚ��Ƿ���ȣ�=
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
	//	//�ڵ����͵�ָ��
	//	Node* _node;

	//	//���캯��
	//	ListConstIterator(Node* node)
	//		:_node(node)
	//	{}

	//	//����ǰ�ú���++��ǰ�ú���--
	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	Self operator++(int)
	//	{
	//		Self tmp(*this);
	//		//���ÿ������죨Ĭ�ϵ�ǳ�������캯����
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
	//		//���ÿ������죨Ĭ�ϵ�ǳ�������캯����
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	//������
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	//it->
	//	const T* operator->()
	//	{
	//		return &_node->_data;
	//	}

	//	//�������Ƚ��Ƿ���ȣ�=
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
		//const�����������ݲ����޸�
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
			//�������죬Ȼ�󽻻���ԭ���ݲ����
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
			
			//�൱����β��
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
			//Ϊʲôend()--������ʹ��
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
		//list<T>::const_iterator��һ��������ģ�����T�����ͣ�
		//������Ҫtypename�ؼ��������߱���������һ���������ƣ�������һ����Ա�������ߺ�����
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