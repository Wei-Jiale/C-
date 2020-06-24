#include<iostream>
#include<algorithm>
using namespace std;

bool isPrime(int num){
	//ֻ�����������������ܱ�������ߵ�����������һ�����ܱ������ұߵ�������
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++){
		if (num%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int num;
	int half;
	int i;
	while (cin >> num){
		// ���м���������
		half = num / 2;
		for (i = half; i>0; i--){
			if (isPrime(i) && isPrime(num - i)){
				break;
			}
		}
		cout << i << endl << num - i << endl;
	}
}