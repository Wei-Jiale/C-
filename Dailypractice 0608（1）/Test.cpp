#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N;
	// ����쳲���������ǰ����f0,f1
	int f0 = 0;
	int f1 = 1;
	int f;
	// ����N���������쳲�������
	int left = 0;
	int right = 0;
	cin >> N;
	while (1){
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		// �ҵ���NС�Ҿ���N�����ֵ���������
		if (f < N){
			left = N - f;
		}
		else{
			right = f - N;
			break;
		}
	}
	cout << min(left, right) << endl;
	return 0;
}