#include<iostream>
#include<vector>
using namespace std;

// 默认成员函数的控制
class A{
public:
	A(int a) : _a(a)
	{}
	// 显式缺省构造函数，由编译器生成
	A() = default;
	// 在类中声明，在类外定义时让编译器生成默认赋值运算符重载
	A& operator=(const A& a);
private:
	int _a;
};

A& A::operator=(const A& a) = default;

int main(){
	A a1(10);
	A a2;
	a2 = a1;
	return 0;
}

class A{
public:
	A(int a) : _a(a)
	{}
	// 禁止编译器生成默认的拷贝构造函数以及赋值运算符重载
	A(const A&) = delete;
	A& operator(const A&) = delete;
private:
	int _a;
};