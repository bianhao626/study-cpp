#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

namespace kuto
{
	class MyString
	{
	public:
		//������
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		//���캯��
		MyString(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//��������
		~MyString()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//�������캯��s1(s2)
		MyString(const MyString& s)
		{
			//�����ڵĶ���
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		//s1 = s2��ֵ����
		MyString& operator=(const MyString& s)
		{
			//�Ѿ����ڵĶ���
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}

		//ģ��string����size��capacity
		size_t size() const
		{
			//���޸ĳ�Ա����
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}

		const char* c_str() const
		{
			return _str;
		}
		//����[]
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		//�滻����ʵ��
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}
		//����
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		//����push_back��append
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		//���������
		MyString& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		MyString& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//ģ��ʵ��insert
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			int end = _size + len;
			while (end > pos + len -1)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size = _size + len;
		}
		//ģ��ʵ��erase
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos ||  len > _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}
		//swap������ʵ��
		void swap(MyString& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		//find������ʵ��
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* ch, size_t pos = 0) const
		{
			assert(pos < _size);
			char* n = strstr(_str, ch);
			if (n != NULL)
			{
				return n - _str;
			}
			else
			{
				return npos;
			}
		}
		//substrʵ��
		MyString substr(size_t pos = 0, size_t len = npos)
		{
			MyString ret;
			if (len > _size - pos)
			{
				for (size_t i = pos; i < _size; i++)
				{
					ret += _str[i];
				}
			}
			else
			{
				for (size_t i = pos; i < pos + len; i++)
				{
					ret += _str[i];
				}
			}
			return ret;
		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		const static int npos;
	};
	const int MyString::npos = -1;
	void swap(MyString& x, MyString& y)
	{
		x.swap(y);
	}
	//����==\<\<=\>\>=\!=
	bool operator==(const MyString s1,const MyString& s2)
	{
		int ret = strcmp(s1.c_str(), s2.c_str());
		return ret == 0;
	}
	bool operator>(const MyString s1, const MyString& s2)
	{
		int ret = strcmp(s1.c_str(), s2.c_str());
		return ret > 0;
	}
	bool operator>=(const MyString s1, const MyString& s2)
	{
		return s1 > s2 || s1 == s2;
	}
	bool operator<(const MyString s1, const MyString& s2)
	{
		return !(s1 >= s2);
	}
	bool operator<=(const MyString s1, const MyString& s2)
	{
		return s1 < s2 || s1 == s2;
	}
	bool operator!=(const MyString s1, const MyString& s2)
	{
		return !(s1 == s2);
	}

	//<<\>>������
	ostream& operator<<(ostream& out, const MyString& s)
	{
		for (auto e : s)
		{
			out << e;
		}
		return out;
	}
	istream& operator>>(istream& in, MyString& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
	//getline����
	istream& getline(istream& in, MyString& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
}