class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0;
		int carry = 0;
		while (B){
			// ��Ӧλ�ĺ�
			sum = A^B;
			// ��Ӧλ�͵Ľ�λ����Ȼ�ǽ�λ��Ҫ��������
			carry = (A&B) << 1;
			// ��Ӧλ�ĺ�+��Ӧλ�Ľ�λ
			A = sum;
			B = carry;
		}
		return sum;
	}
};