// ��ȫ������
// ��ȫ���������ӣ��������������Լ�����ĺ�ǡ�õ���������
#include<iostream>
#include<algorithm>
using namespace std;

int count(int n){
	int ret = 0;
	if ((n <= 0) || (n>500000)){
		return -1;
	}
	else{
		for (int i = 2; i <= n; i++){
			int sum = 0;
			// ������Χ
			int sq = sqrt(i);
			for (int j = 2; j <= sq; j++){
				if (i%j == 0){
					if (i / j == j){
						sum = sum + j;
					}
					else{
						sum = sum + j + i / j;
					}
				}
			}
			if (sum + 1 == i){
				ret++;
			}
		}
		return ret;
	}
}

int main(){
	int input;
	while (cin >> input){
		cout << count(input) << endl;
	}
	return 0;
}