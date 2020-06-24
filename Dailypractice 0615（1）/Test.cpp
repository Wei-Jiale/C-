#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		// 计算参数个数
		int count = 0;
		for (int i = 0; i<str.size(); i++){
			// 空格
			if (str[i] == ' '){
				count++;
			}
			// 双引号
			if (str[i] == '"'){
				do{
					i++;
				} while (str[i] != '"');
			}
		}
		cout << count + 1 << endl;
		int flag = 1;
		for (int i = 0; i<str.size(); i++){
			// 遇到双引号
			if (str[i] == '"'){
				flag ^= 1;
			}
			// 双引号和普通空格不打印
			if (str[i] != ' '&&str[i] != '"'){
				cout << str[i];
			}
			// 双引号中的空格要打印
			if (str[i] == ' ' && (!flag)){
				cout << str[i];
			}
			//双引号外遇到空格则换行
			if (str[i] == ' '&&flag){
				cout << endl;
			}
		}
	}
	return 0;
}