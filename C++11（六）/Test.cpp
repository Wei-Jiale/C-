// lambda表达式
// [捕捉列表](参数列表)multable->返回值类型{函数体}
#include<iostream>
using namespace std;

// 捕捉：传值捕捉 传引用捕捉
// 传值捕捉的对象是不能被改变的，需要加上mutable属性就可以改变了。

int main(){
	int a = 0, b = 1;
	// 实现a+b的lambda表达式
	auto add1 = [](int x, int y)->int{return x + y; };
	cout << add1(a, b) << endl;

	auto add2 = [a, b]()->int{return a + b; };
	cout << add2() << endl;

	// 实现a和b的交换
	auto swap1 = [](int& x, int& y){
		int z = x;
		x = y;
		y = z;
	};
	swap1(a, b);

	auto swap2 = [&a, &b]()mutable{
		int c = a;
		a = b;
		b = c;
	};
	swap2();

	return 0;
}