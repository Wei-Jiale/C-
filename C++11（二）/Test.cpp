#include<iostream>
#include<vector>
using namespace std;

// Ĭ�ϳ�Ա�����Ŀ���
class A{
public:
	A(int a) : _a(a)
	{}
	// ��ʽȱʡ���캯�����ɱ���������
	A() = default;
	// �����������������ⶨ��ʱ�ñ���������Ĭ�ϸ�ֵ���������
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
	// ��ֹ����������Ĭ�ϵĿ������캯���Լ���ֵ���������
	A(const A&) = delete;
	A& operator(const A&) = delete;
private:
	int _a;
};