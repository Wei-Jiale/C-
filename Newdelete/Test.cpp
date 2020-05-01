#include <iostream>                                 
#include <stdlib.h>  
using namespace std;
class Stu{
public:
	Stu(){
		cout << "default building" << endl;
	}

	Stu(int num, string name) :_num(num), _name(name){
		cout << "custom building" << endl;
	}

	~Stu(){
		cout << "destroying" << endl;
	}
private:
	int _num;
	string _name;
};

int main(){
	cout << "malloc:" << endl;
	Stu* a = (Stu*)malloc(sizeof(Stu));
	cout << "new:" << endl;
	Stu* b = new Stu(1, "����");
	cout << "malloc:" << endl;
	Stu* c = (Stu*)malloc(sizeof(Stu)* 5);
	cout << "new:" << endl;
	Stu* d = new Stu[5];
	cout << "free:" << endl;
	free(a);
	cout << "delete:" << endl;
	delete b;
	cout << "free:" << endl;
	free(c);
	cout << "delete:" << endl;
	delete[] d;
}
// ����Զ������͵��ڴ������ͷţ�new���������ڷ����ڴ��ʱ���ֶ�����ָ���Ĺ��캯�������ڷ���������Ŀռ�ʱ�Զ�����Ĭ�Ϲ��캯��
// deleteҲ���Զ�������������