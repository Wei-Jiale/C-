#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	string cur;
	string retstr;
	cin >> str;

	// 遍历字符串
	// 注意：循环终止条件为 i<=str.size() 字符串末尾有‘\0’
	for (int i = 0; i <= str.size(); i++){
		if (str[i] >= '0'&&str[i] <= '9'){
			// 记录数字串
			cur = cur + str[i];
		}
		else{
			if (retstr.size() < cur.size()){
				// cur长度>restr长度则更新retstr
				retstr = cur;
			}
			else{
				cur.clear();
			}
		}
	}

	cout << retstr << endl;
	return 0;
}