#include<iostream>
using namespace std;
// ��Ƴ�һ����
// �������������˶��ٸ�����
// ����Ĳ���������/��������
class A{
public:
	A(){
		++n;
	}
	A(const A& a){
		++n;
	}
	// ���γ�Ա������û��thisָ�� �����в��ܷ��ʷǾ�̬��Ա
	static int Getn(){
		return n;
	}
private:
	// ���γ�Ա�����������ȫ����
	static int n;// ���� n������ ����������ĳ������  ���ھ�̬��
}; 

int A::n = 0; // ����

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