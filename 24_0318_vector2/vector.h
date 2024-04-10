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

		//���캯��
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
		//��������
		~vector()
		{
			delete[] _start;
			_start = _end = _endCapacity = nullptr;
		}
		//���캯��v1(v2)
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for ( auto e : v )
			{
				push_back(e);
			}
		}
		//��ֵ����v1 = v2
		vector<T>& operator=(vector<T> v)
		{
			//������ʱ�ռ�
			//iterator tmp = new T[v.capacity()];
			//memcpy(tmp, v._start, v.size() * sizeof(T));
			//delete[] _start;
			//_start = tmp;
			//_end = tmp + v.size();
			//_endCapacity = tmp + v.capacity();

			
			swap_vector(v);
			return *this;
		}

		//ȡֵ����[]
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

		//ģ��ʵ��size
		size_t size() const
		{
			return _end - _start;
		}
		//ģ��ʵ��capacity
		size_t capacity() const
		{
			return _endCapacity - _start;
		}
		//empty()ģ��ʵ��
		size_t empty() const
		{
			return _start == _end;
		}
		//��������ģ��ʵ��
		void swap_vector(vector<T> v)
		{
			std::swap(_start, v._start);
			std::swap(_end, v._end);
			std::swap(_endCapacity, v._endCapacity);
		}

		//resizeģ��ʵ��
		void resize(size_t n, const T& val = T())
		{
			//�������ռ�n����Ŀǰ���ٵĿռ䣬������¿ռ�Ŀ���
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
				//�������ֹλ��
				_end = _start + n;
			}
		}
		//reverse���ݺ���ģ��ʵ��
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//�����µĿռ䣬Ȼ��ѾɵĿռ��ֵ���ݸ��¿ռ��У�֮��ɾ���ÿռ�
				iterator tmp = new T[n];
				size_t old_size = size();
				//memcpy(tmp, _start, old_size * sizeof(T));
				//��������string���������͵�ʱ�򣬾ͻ����ǳ���������⣡������
				//�����ʽ����Ϊ��ֵ���ɣ������string�ĸ�ֵ
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
		//push_backģ��ʵ��
		void push_back(const T& x)
		{
			//���Ȳ鿴�ռ��Ƿ���
			if (_end == _endCapacity)
			{
				//��������
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_end = x;
			_end++;
		}
		//pop_backģ��ʵ��
		void pop_back()
		{
			//�ж��Ƿ�Ϊ��
			assert(!empty());
			--_end;
		}
		//����λ�ò���һ������ģ��ʵ��
		void insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _end);
			//�ڴ�ռ��Ƿ�������
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
		//����λ�����һ������ģ��ʵ��
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