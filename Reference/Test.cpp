//����
//���ã����Ѿ����ڵı���ȡ��һ���������������������ͬһ���ڴ�ռ�
#include<iostream>
using namespace std;

// 1.����
int mian(){
	int a = 10;
	int& b = a;//b��a�ı���

	//Ȩ�޿�����С�����ܷŴ�
	int c = 20;
	const int& d = c;

	//const int e = 30;
	//int& f = e; Ȩ�޷Ŵ����

	return 0;
}

// 2.����������
// �ٴ�����һ����ʱ���� ���Ч��
void Swap_c(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Swap_cpp(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int a = 10;
	int b = 20;
	Swap_c(&a, &b);//����ַ�����ռ䣩
	Swap_cpp(a, b);//�����ã������ռ䣩

	return 0;
}

// 3.����������ֵ
// ע�����ر�������������Ӧ���湤�� ���򲻰�ȫ(�ռ���ܱ��޸ģ�
// �ٴ�����һ����ʱ���� ���Ч��
int Count1(){
	static int n = 0;
	n++;

	return n;//������ʱ����n�����ռ䣩�൱�ڿ���
}

int& Count2(){
	static int n = 0;
	n++;

	return n;//�������ã������ռ䣩�൱������
}

int main(){

	return 0;
}

//���õ����ԣ������ʼ��/һ�����������ж������/һ������һ��ʵ�岻������������ʵ��