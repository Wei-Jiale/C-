// ��m�Ķ�����λ���뵽n�Ķ�����λ�ĵ�jλ
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n | m;
	}
};