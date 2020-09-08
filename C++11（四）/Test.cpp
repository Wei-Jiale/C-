#include<iostream>
using namespace std;

class String{
public:
	String(const char* str = ""){
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// s2(s1)
	String(const String& s){
		cout << "String(const String& s)-���-Ч�ʵ�" << endl;

		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	// s3(��ֵ-����ֵ)
	String(String&& s)
		:_str(nullptr)
	{
		// ����������һ������ֵ�������㶼Ҫ���ˣ��ҵ�Ŀ���Ǹ�����һ����Ŀռ䣬һ����ֵ
		// �������Ŀ��ƺ�ֻ����
		cout << "String(String&& s)-�ƶ�����-Ч�ʸ�" << endl;
		swap(_str, s._str);
	}

	String& operator=(const String& s){
		if (this != &s){
			char* newstr = new char[strlen(s._str) + 1];
			strcpy(newstr, s._str);
			delete[] _str;
			_str = newstr;
		}
		return *this;
	}

	String& operator=(String&& s){
		swap(_str, s._str);
		return *this;
	}

	~String(){
		delete[] _str;
	}
private:
	char* _str;
};

String f(const char* str){
	String tmp(str);
	return tmp; // ���ﷵ��ʵ���ǿ���tmp����ʱ����
}

int main(){
	String s1("��ֵ");
	String s2(s1);                      // ��������ֵ
	String s3(f("��ֵ-����ֵ"));        // ��������ֵ-����ֵ(���ݸ����ã������Ҿ�������)

	return 0;
}