#include<iostream>
#include<string>
using namespace std;

int main(){
	string s("hello");
	// 3�ֱ�����ʽ��
	// �������ַ�ʽ���˱���string���󣬻����Ա����޸�string�е��ַ���
	// �����������ַ�ʽ����string���ԣ���һ��ʹ�����

	// 1. for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	// 2.������
	//string::iterator it = s.begin();
	auto it = s.begin();
	while (it != s.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//string::reverse_iterator rit = s.rbegin();
	auto rit = s.rbegin();
	while (rit != s.rend()){
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
		
	// 3.C++11��Χfor(�����ַ�����Χ�Զ�����)
	for (auto ch : s){
		cout << ch << " ";
	}
	cout << endl;

	return 0;
}