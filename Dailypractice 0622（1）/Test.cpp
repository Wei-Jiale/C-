// 三个空汽水瓶可以换一瓶汽水
#include<iostream>
using namespace std;

int CalculateNum(int num){
	// 总兑换数
	int sum = 0;
	while (num>1){
		// 每三瓶换一瓶
		int result = num / 3;
		// 剩余不足三瓶的先保留
		int reminder = num % 3;
		sum = sum + result;
		// 下一次可以兑换的空瓶子
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