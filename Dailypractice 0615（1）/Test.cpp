#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		// �����������
		int count = 0;
		for (int i = 0; i<str.size(); i++){
			// �ո�
			if (str[i] == ' '){
				count++;
			}
			// ˫����
			if (str[i] == '"'){
				do{
					i++;
				} while (str[i] != '"');
			}
		}
		cout << count + 1 << endl;
		int flag = 1;
		for (int i = 0; i<str.size(); i++){
			// ����˫����
			if (str[i] == '"'){
				flag ^= 1;
			}
			// ˫���ź���ͨ�ո񲻴�ӡ
			if (str[i] != ' '&&str[i] != '"'){
				cout << str[i];
			}
			// ˫�����еĿո�Ҫ��ӡ
			if (str[i] == ' ' && (!flag)){
				cout << str[i];
			}
			//˫�����������ո�����
			if (str[i] == ' '&&flag){
				cout << endl;
			}
		}
	}
	return 0;
}