class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0;
		int carry = 0;
		while (B){
			// 对应位的和
			sum = A^B;
			// 对应位和的进位，既然是进位就要整体左移
			carry = (A&B) << 1;
			// 对应位的和+对应位的进位
			A = sum;
			B = carry;
		}
		return sum;
	}
};