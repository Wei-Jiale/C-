// �ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	while (cin >> str){
		// ����ַ����ֵĴ���
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