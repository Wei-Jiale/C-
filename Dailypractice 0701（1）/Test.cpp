// 不使用四则运算算加法
// 两数异或得两数相加后不包含进位得结果
// 两数相与左移一位为两数相加后的进位
class Solution {
public:
	int Add(int num1, int num2){
		while (num2 != 0){
			// 相加后不包含进位的数据
			int sum = num1 ^ num2;
			// 相加后的进位
			int carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		}
		return num1;
	}
};