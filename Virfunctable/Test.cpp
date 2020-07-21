// ���̳��е��麯����
#include<iostream>
using namespace std;
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};

class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};

// ��������Ϊ����ָ��
typedef void(*VF_PTR)();
void PrintVFTable(VF_PTR* table){
	for (size_t i = 0; table[i] != 0; i++){
		printf("vfTable[%d]:%p->", i, table[i]);
		VF_PTR f = table[i];
		f();
	}
	cout << endl;
}

int main(){
	Base b;
	Derive d;
	// ȡ������ǰ�ĸ��ֽڴ���麯����ָ��
	PrintVFTable((VF_PTR*)*(int*)&b);
	PrintVFTable((VF_PTR*)*(int*)&d);
}