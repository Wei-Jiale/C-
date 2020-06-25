// 输入某年某月某日，判断这一天是这一年的第几天
#include<iostream>
using namespace std;

int main(){
	// 用数组存放累加的天数
	int array[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day){
		sum = 0;
		sum = sum + array[month - 2];
		sum = sum + day;
		// 二月天数不确定
		if (month > 2){
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
				sum = sum + 1;
			}
		}
		cout << sum << endl;
	}
}