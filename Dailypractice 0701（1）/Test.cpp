// ��ʹ������������ӷ�
// ��������������Ӻ󲻰�����λ�ý��
// ������������һλΪ������Ӻ�Ľ�λ
class Solution {
public:
	int Add(int num1, int num2){
		while (num2 != 0){
			// ��Ӻ󲻰�����λ������
			int sum = num1 ^ num2;
			// ��Ӻ�Ľ�λ
			int carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		}
		return num1;
	}
};