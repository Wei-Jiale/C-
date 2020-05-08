#include<iostream>
#include<string>
using namespace std;

void Teststring(){
	string str;
	str.push_back(' '); // 在str后插入空格
	str.append("hello"); // 在str后追加一个字符"hello"
	str += 'b'; // 在str后追加一个字符'b'
	str += "it"; // 在str后追加一个字符串"it"
	cout << str << endl;
	cout << str.c_str() << endl; // 以C语言的方式打印字符串

	// 获取file的后缀
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	// npos是string里面的一个静态成员变量
	// static const size_t npos = -1;
	// 取出url中的域名
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos){
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	// 删除url的协议前缀
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}