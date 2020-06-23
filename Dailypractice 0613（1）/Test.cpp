// 将m的二进制位插入到n的二进制位的第j位
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n | m;
	}
};