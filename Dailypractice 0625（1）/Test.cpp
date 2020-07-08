// 找出字符串中第一个只出现一次的字符
#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	while (cin >> str){
		// 存放字符出现的次数
		int hashtable[256] = { 0 };
		for (auto& e : str){
			hashtable[e]++;
		}
		int i;
		for (i = 0; i<str.size(); i++){
			if (hashtable[str[i]] == 1){
				cout << str[i] << endl;
				break;
			}
		}
		if (i >= str.size()){
			cout << -1 << endl;
		}
	}
	return 0;
}