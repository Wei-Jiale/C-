#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N;
	// 定义斐波那契数列前两项f0,f1
	int f0 = 0;
	int f1 = 1;
	int f;
	// 距离N最近的左右斐波那契数
	int left = 0;
	int right = 0;
	cin >> N;
	while (1){
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		// 找到比N小且距离N最近的值并求出距离
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