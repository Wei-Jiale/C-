#pragma warning(disable : 4996)
#include<iostream>
using namespace std;

namespace copymodern{
	class string{
	public:
		// 1.构造函数
		string(char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			// _str指向的空间在堆上（可进行灵活操作:修改、扩容）
			strcpy(_str, str);
		}

		// 2.析构函数
		~string(){
			delete[] _str;
			_str = nullptr;
		}

		//// 3.拷贝构造传统写法（解决浅拷贝：同一空间释放两次） string s2(s1);
		//string(const string& s)
		//	// 深拷贝：拷贝空间
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}

		// 3.拷贝构造的现代写法
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//// 4.赋值传统写法（解决浅拷贝）s1 = s3;
		//string& operator=(const string& s){
		//	// 防止自己给自己赋值
		//	if (this != &s){
		//		// 开辟和s3相同大小的临时空间
		//		char* temp = new char[strlen(s._str) + 1];
		//		strcpy(temp, s._str);
		//		// 释放s1的空间
		//		delete[] _str;
		//		// s1指向新空间
		//		_str = temp;
		//	}
		//	return *this;
		//}

		//// 4.赋值现代写法
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		swap(_str, tmp._str);
		//	}

		//	return *this;
		//}

		// 4.赋值现代写法
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
		// string是管理字符的数组，底层是一个指向数组的指针
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