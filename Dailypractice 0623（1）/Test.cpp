// �ַ����ķ�ת
// ������βָ�򣬽�����βԪ�أ�start++��end--����start��end����ʱ��ת��ɡ�
#include<iostream>
#include<string>
using namespace std;

string Reverse(string str){
	if (str.empty()){
		return str;
	}
	size_t start = 0;
	size_t end = str.size() - 1;
	while (start < end){
		swap(str[start], str[end]);
		start++;
		end--;
	}
	return str;
}

int main(){
	string str;
	getline(cin, str);
	cout << Reverse(str) << endl;
	return 0;
}