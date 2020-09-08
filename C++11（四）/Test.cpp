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
		cout << "String(const String& s)-深拷贝-效率低" << endl;

		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	// s3(右值-将亡值)
	String(String&& s)
		:_str(nullptr)
	{
		// 传过来的是一个将亡值，反正你都要亡了，我的目的是跟你有一样大的空间，一样的值
		// 不如把你的控制和只给我
		cout << "String(String&& s)-移动拷贝-效率高" << endl;
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
	return tmp; // 这里返回实际是拷贝tmp的临时对象
}

int main(){
	String s1("左值");
	String s2(s1);                      // 参数是左值
	String s3(f("右值-将亡值"));        // 参数是右值-将亡值(传递给你用，用完我就析构了)

	return 0;
}