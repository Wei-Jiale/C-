// ��������ˮƿ���Ի�һƿ��ˮ
#include<iostream>
using namespace std;

int CalculateNum(int num){
	// �ܶһ���
	int sum = 0;
	while (num>1){
		// ÿ��ƿ��һƿ
		int result = num / 3;
		// ʣ�಻����ƿ���ȱ���
		int reminder = num % 3;
		sum = sum + result;
		// ��һ�ο��Զһ��Ŀ�ƿ��
		num = result + reminder;
		if (num == 2){
			++sum;
			break;
		}
	}
	return sum;
}

int main(){
	int num;
	while (cin >> num){
		cout << CalculateNum(num) << endl;
	}
	return 0;
}