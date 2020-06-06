#include<iostream>
#include<string>
using namespace std;

int main(){
	// 输入
	string str1;
	string str2;

	// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
	cin >> str1;
	while (cin >> str2){
		str1 = str2 + " " + str1;
	}

	cout << str1 << endl;
	return 0;
}