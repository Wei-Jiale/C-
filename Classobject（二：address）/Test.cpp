#include<iostream>
using namespace std;
class Student{
	// 默认生成的取地址及const取地址操作符如下
	Student* operator&()
	{
		return this;
	}

	const Student* operator&() const
	{
		return this;
	}
};
// 这两个默认成员函数是最后的两个会默认生成的成员函数，一般情况下不需要我们显式定义
// 除非我们想让别人通过取地址符获得指定的数据。
