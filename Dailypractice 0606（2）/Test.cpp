#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int StrToInt(string str){
		if (str.empty()){
			return 0;
		}
		// 处理符号
		int symbol = 1;
		if (str[0] == '-') {
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+') {
			symbol = 1;
			str[0] = '0';
		}
		// 定义和
		int sum = 0;
		// 遍历字符串取出字符进行转换
		for (int i = 0; i<str.size(); ++i){
			// 非法字符
			if (str[i] < '0' || str[i] > '9'){
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
			// 判断溢出
			if (((symbol>0) && (sum > 0x7FFFFFFF)) || ((symbol<0) && (sum > 0x80000000))){
				sum = 0;
				break;
			}
		}
		return symbol * sum;
	}
};
