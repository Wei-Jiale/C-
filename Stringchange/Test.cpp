#include<iostream>
#include<string>
using namespace std;

void Teststring(){
	string str;
	str.push_back(' '); // ��str�����ո�
	str.append("hello"); // ��str��׷��һ���ַ�"hello"
	str += 'b'; // ��str��׷��һ���ַ�'b'
	str += "it"; // ��str��׷��һ���ַ���"it"
	cout << str << endl;
	cout << str.c_str() << endl; // ��C���Եķ�ʽ��ӡ�ַ���

	// ��ȡfile�ĺ�׺
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	// npos��string�����һ����̬��Ա����
	// static const size_t npos = -1;
	// ȡ��url�е�����
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

	// ɾ��url��Э��ǰ׺
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}