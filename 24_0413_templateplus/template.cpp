#include"template.h"

namespace kuto
{
	//定义的地方，不知道实例化T成什么类型，所以有定义无法实例化，也就是无法生成函数的地址到符号表
	//template<class T, size_t N>
	//size_t array<T, N>::size() const
	//{
	//	T x = 0;
	//	x += N;
	//	return _size;
	//}
	void func()
	{
		cout << "void func()" << endl;
	}

	//// 显示实例化(如何解决上面的问题）
	//template
	//class array<int>;
	////但是每一个类型都需要显示实例化一个
	//template
	//class array<double>;
}