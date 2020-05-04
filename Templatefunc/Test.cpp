#include <iostream>
using namespace std;
//定义函数模板,T为任意类型
//class 也可替换为 typename
template<class T>
void Swap(T& a, T& b){
	T t = a;
	a = b;
	b = t;
}

int main(){
	int a = 4, b = 5;
	double c = 6, d = 7;
	Swap(a, b);
	Swap(c, d);
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
}