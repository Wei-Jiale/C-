#include<iostream>
#include<vector>

class bitmap{
public:
	bitmap(size_t N){
		_bits.resize(N / 32 + 1, 0); // �࿪һ������32bit
		_num = 0;
	}

	// ���
	void set(size_t x){
		// Ѱ��x�ı�Ǵ���ڵڼ�������
		size_t index = x / 32;
		// Ѱ��x�ı����������͵ĵڼ���λ
		size_t pos = x % 32;

		//���������λ�ƶ�
		_bits[index] |= (1 << pos);
	}

	void reset(size_t x){
		// Ѱ��x�ı�Ǵ���ڵڼ�������
		size_t index = x / 32;
		// Ѱ��x�ı����������͵ĵڼ���λ
		size_t pos = x % 32;

		// ��pos��λ����Ϊ0
		_bits[index] &= ~(1 << pos);
	}

	// �ж�x��ӳ��λ�Ƿ�Ϊ1
	bool test(size_t x){
		// Ѱ��x�ı�Ǵ���ڵڼ�������
		size_t index = x / 32;
		// Ѱ��x�ı����������͵ĵڼ���λ
		size_t pos = x % 32;

		return _bits[index] & (1 << pos);
	}

private:
	std::vector<int> _bits;
	size_t _num; // �洢�����ݸ���
};