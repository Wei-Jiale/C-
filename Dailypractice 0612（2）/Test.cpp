// 计算二进制位中连续1的个数
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int count = 0;
		int maxcount = 0;
		while (n){
			if (n & 1){
				count++;
				maxcount = max(count, maxcount);
			}
			else{
				count = 0;
			}
			n = n >> 1;
		}
		cout << maxcount << endl;
	}
	return 0;
}