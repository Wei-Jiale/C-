//C++�еĺ�������
//�������أ�ͬһ��������������������������Ƶ�ͬ����������Щ�����Ĳ����б��������������ͻ�˳�򣩱��벻ͬ
//ע�������Ƿ���ֵ��ͬ�����ܹ������ء������ضԷ���ֵû��Ҫ��
#include<iostream>
using namespace std;

int Add(int left, int right){
		return left + right;
}

double Add(double left, double right){
	return left + right;
}

void Func(int num, char ch){

}

void Func(char ch, int num){

}

int main()
{
	Add(10, 20);
	Add(10.0, 20.0);

	//����ʵ�������Զ�ʱ�����͵��ö�Ӧ����
	Func('a', 10);
	Func(10, 'b');

	return 0;
}

