#include<iostream>
#include<string>
using namespace std;

int main(){
	// ����
	string str1;
	string str2;

	// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
	cin >> str1;
	while (cin >> str2){
		str1 = str2 + " " + str1;
	}

	cout << str1 << endl;
	return 0;
}