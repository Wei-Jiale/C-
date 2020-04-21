#include<iostream>
using namespace std;
// 设计出一个类
// 计算这个类产生了多少个对象
// 对象的产生：构造/拷贝构造
class A{
public:
	A(){
		++n;
	}
	A(const A& a){
		++n;
	}
	// 修饰成员函数：没有this指针 函数中不能访问非静态成员
	static int Getn(){
		return n;
	}
private:
	// 修饰成员变量：解决安全问题
	static int n;// 声明 n属于类 并不是属于某个对象  属于静态区
}; 

int A::n = 0; // 定义

A func(A a){
	return a;
}

int main(){
	A a1;
	A a2;

	func(a1);
	func(a2);

	cout << a1.Getn() << endl;
	cout << a2.Getn() << endl;
	cout << A::Getn() << endl;


	return 0;
}