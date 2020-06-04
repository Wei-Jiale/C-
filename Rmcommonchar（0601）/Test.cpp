#include<iostream>
#include<string>
using namespace std;

int main(){
	// 输入：cin遇到空格会结束，OJ中最好使用getline接收字符串 
	string strsrc, strrm;
	getline(cin, strsrc);
	getline(cin, strrm);

	// 使用哈希映射统计strrm字符串中出现的字符
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < strrm.size(); i++){
		hashtable[strrm[i]]++;
	}

	// 遍历strsrc
	string newstr;
	for (size_t i = 0; i < strsrc.size(); i++){
		// strsrc字符对应的位为0则表示不在strrm的范围中
		if (hashtable[strsrc[i]] == 0){
			newstr = newstr + strsrc[i];
		}
	}

	cout << newstr << endl;
	return 0;
}