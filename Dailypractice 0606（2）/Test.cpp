#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int StrToInt(string str){
		if (str.empty()){
			return 0;
		}
		// �������
		int symbol = 1;
		if (str[0] == '-') {
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+') {
			symbol = 1;
			str[0] = '0';
		}
		// �����
		int sum = 0;
		// �����ַ���ȡ���ַ�����ת��
		for (int i = 0; i<str.size(); ++i){
			// �Ƿ��ַ�
			if (str[i] < '0' || str[i] > '9'){
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
			// �ж����
			if (((symbol>0) && (sum > 0x7FFFFFFF)) || ((symbol<0) && (sum > 0x80000000))){
				sum = 0;
				break;
			}
		}
		return symbol * sum;
	}
};
