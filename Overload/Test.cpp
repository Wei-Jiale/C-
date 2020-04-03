//C++中的函数重载
//函数重载：同一作用域中允许声明多个功能类似的同名函数，这些函数的参数列表（参数个数或类型或顺序）必须不同
//注：仅仅是返回值不同，则不能构成重载。（重载对返回值没有要求）
#include<iostream>
using namespace std;

int Add(int left, int right){
		return left + right;
}

double Add(double left, double right){
	return left + right;
}

void Func(int num, char ch){

}

void Func(char ch, int num){

}

int main()
{
	Add(10, 20);
	Add(10.0, 20.0);

	//根据实参类型自动时别类型调用对应函数
	Func('a', 10);
	Func(10, 'b');

	return 0;
}

