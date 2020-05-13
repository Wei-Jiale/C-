#pragma warning(disable : 4996)
#include<iostream>
using namespace std;

namespace copymodern{
	class string{
	public:
		// 1.���캯��
		string(char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			// _strָ��Ŀռ��ڶ��ϣ��ɽ���������:�޸ġ����ݣ�
			strcpy(_str, str);
		}

		// 2.��������
		~string(){
			delete[] _str;
			_str = nullptr;
		}

		//// 3.�������촫ͳд�������ǳ������ͬһ�ռ��ͷ����Σ� string s2(s1);
		//string(const string& s)
		//	// ����������ռ�
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}

		// 3.����������ִ�д��
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//// 4.��ֵ��ͳд�������ǳ������s1 = s3;
		//string& operator=(const string& s){
		//	// ��ֹ�Լ����Լ���ֵ
		//	if (this != &s){
		//		// ���ٺ�s3��ͬ��С����ʱ�ռ�
		//		char* temp = new char[strlen(s._str) + 1];
		//		strcpy(temp, s._str);
		//		// �ͷ�s1�Ŀռ�
		//		delete[] _str;
		//		// s1ָ���¿ռ�
		//		_str = temp;
		//	}
		//	return *this;
		//}

		//// 4.��ֵ�ִ�д��
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		swap(_str, tmp._str);
		//	}

		//	return *this;
		//}

		// 4.��ֵ�ִ�д��
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		// 5.size
		size_t size()const{
			return strlen(_str);
		}

		// 6.operator[]
		char& operator[](size_t i){
			return _str[i];
		}

	private:
		// string�ǹ����ַ������飬�ײ���һ��ָ�������ָ��
		char* _str;
	};
}

ostream& operator<<(ostream& out, const string& s){
	for (size_t i = 0; i < s.size(); ++i){
		out << s[i];
	}
	return out;
}

int main(){
	string s1("hello");
	string s2(s1);
	cout << s2 << endl;

	string s3("world");
	s1 = s3;
	cout << s1 << endl;
}