// lambda���ʽ
// [��׽�б�](�����б�)multable->����ֵ����{������}
#include<iostream>
using namespace std;

// ��׽����ֵ��׽ �����ò�׽
// ��ֵ��׽�Ķ����ǲ��ܱ��ı�ģ���Ҫ����mutable���ԾͿ��Ըı��ˡ�

int main(){
	int a = 0, b = 1;
	// ʵ��a+b��lambda���ʽ
	auto add1 = [](int x, int y)->int{return x + y; };
	cout << add1(a, b) << endl;

	auto add2 = [a, b]()->int{return a + b; };
	cout << add2() << endl;

	// ʵ��a��b�Ľ���
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