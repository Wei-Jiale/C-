#include<iostream>
#include<string>
using namespace std;

int main(){
	// ע�⣺string�����֧��ֱ����cin��cout������������
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
	// ��aaaaaaaaaa��
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	// "aaaaaaaaaa\0\0\0\0\0"
	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// ��s����Ч�ַ�������С��5��
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	return 0;
}