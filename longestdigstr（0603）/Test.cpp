#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	string cur;
	string retstr;
	cin >> str;

	// �����ַ���
	// ע�⣺ѭ����ֹ����Ϊ i<=str.size() �ַ���ĩβ�С�\0��
	for (int i = 0; i <= str.size(); i++){
		if (str[i] >= '0'&&str[i] <= '9'){
			// ��¼���ִ�
			cur = cur + str[i];
		}
		else{
			if (retstr.size() < cur.size()){
				// cur����>restr���������retstr
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