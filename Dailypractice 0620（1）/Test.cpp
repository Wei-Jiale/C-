//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӡ�
//С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�

#include<iostream>
using namespace std;

int main(){
	int month;
	while (cin >> month){
		// ǰ������ֻ��һֻ���ӣ��������²���С���ӣ�
		int first = 1;
		int second = 1;
		int result = 1;
		// �������¿�ʼ
		for (int i = 3; i <= month; i++){
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << endl;
	}
	return 0;
}