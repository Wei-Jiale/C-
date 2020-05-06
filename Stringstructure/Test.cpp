#include<iostream>
#include<string>
using namespace std;

int main(){
	string s1; // 构造空的string类对象s1
	string s2("hello"); // 用C格式字符串构造string类对象s2
	string s3(s2); // 拷贝构造s3
	string s4(10, 'a'); // 10个字符a

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	return 0;
}