#include<iostream>
#include<vector>

class bitmap{
public:
	bitmap(size_t N){
		_bits.resize(N / 32 + 1, 0); // 多开一个整型32bit
		_num = 0;
	}

	// 标记
	void set(size_t x){
		// 寻找x的标记存放在第几个整型
		size_t index = x / 32;
		// 寻找x的标记在这个整型的第几个位
		size_t pos = x % 32;

		//左移是向高位移动
		_bits[index] |= (1 << pos);
	}

	void reset(size_t x){
		// 寻找x的标记存放在第几个整型
		size_t index = x / 32;
		// 寻找x的标记在这个整型的第几个位
		size_t pos = x % 32;

		// 第pos个位置置为0
		_bits[index] &= ~(1 << pos);
	}

	// 判断x的映射位是否为1
	bool test(size_t x){
		// 寻找x的标记存放在第几个整型
		size_t index = x / 32;
		// 寻找x的标记在这个整型的第几个位
		size_t pos = x % 32;

		return _bits[index] & (1 << pos);
	}

private:
	std::vector<int> _bits;
	size_t _num; // 存储的数据个数
};