#include<iostream>
#include<string>
using namespace std;

int main(){
	string s("hello");
	// 3种遍历方式：
	// 以下三种方式除了遍历string对象，还可以遍历修改string中的字符，
	// 另外以下三种方式对于string而言，第一种使用最多

	// 1. for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	// 2.迭代器
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
		
	// 3.C++11范围for(基于字符串范围自动遍历)
	for (auto ch : s){
		cout << ch << " ";
	}
	cout << endl;

	return 0;
}