#include<iostream>
#include<string>
using namespace std;

int main(){
	// ���룺cin�����ո�������OJ�����ʹ��getline�����ַ��� 
	string strsrc, strrm;
	getline(cin, strsrc);
	getline(cin, strrm);

	// ʹ�ù�ϣӳ��ͳ��strrm�ַ����г��ֵ��ַ�
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < strrm.size(); i++){
		hashtable[strrm[i]]++;
	}

	// ����strsrc
	string newstr;
	for (size_t i = 0; i < strsrc.size(); i++){
		// strsrc�ַ���Ӧ��λΪ0���ʾ����strrm�ķ�Χ��
		if (hashtable[strsrc[i]] == 0){
			newstr = newstr + strsrc[i];
		}
	}

	cout << newstr << endl;
	return 0;
}