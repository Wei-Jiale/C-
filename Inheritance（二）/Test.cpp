// ���������������ͬ����Ա���������Ա�����λ����ͬ����Ա��ֱ�ӷ���,������������أ�Ҳ���ض���
// ���������Ա�����У�����ʹ�� <���� :: �����Ա> ָ����������ʾ���ʻ����е�ͬ����Ա��
#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
	string _name = "С��"; // ����
	int _num = 11; // ���֤��
};
class Student : public Person{
public:
	void Print(){
		cout << " ����:" << _name << endl;
		cout << " ���֤��:" << Person::_num << endl;
		cout << " ѧ��:" << _num << endl;
	}
protected:
	int _num = 99; // ѧ��
};
void Test(){
	Student s1;
	s1.Print();
};

int main(){
	Test();
	return 0;
}