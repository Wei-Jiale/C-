#include<iostream> //IO��
using namespace std; // C++������ж������ŵ���std�����ռ��У����ں��Ϳ�������ͻչ��std��

int main(){
	int num1 = 1;
	double num2 = 2.2;
	cout << "num1=" << num1 << " " << "num2=" << num2 << endl;//cout�Զ�ʶ��������ͣ�����Ҫ�������ݸ�ʽ���ƣ�

	return 0;
}

//C++�е������ռ�ܺõĽ����������ͻ������
int main(){
	int cout = 10;
	std::cout << "cout=" << cout << endl;

	return 0;
}

//ȱʡ�������������庯��ʱΪ����ָ����һ��Ĭ��ֵ
void Func1(int a = 0){ // �βκ�ȱʡ����
	cout << "a=" << a << endl;
}

int main(){
	Func1(10);// ��ʵ�� ��ȱʡ��������������
	Func1();// ����ʵ�� ��ȱʡ������������

	return 0;
}

//ȫȱʡ��ȱʡȫ������
void Func2(int a = 10, int b = 20, int c = 30){ 
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

}

int main(){
	Func2();
	Func2(1);
	Func2(1, 2);
	Func2(1, 2, 3);

	return 0;
}

//��ȱʡ��ȱʡ���ֲ��������������������ȱʡ��
void Func3(int a, int b = 20, int c = 30){ //��һ������û��ȱʡ���� ����봫ʵ��
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

}

int main(){
	Func3(1);
	Func3(1, 2);
	Func3(1, 2, 3);

	return 0;
}
