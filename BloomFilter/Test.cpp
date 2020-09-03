#include<iostream>
#include<vector>
#include<string>

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

// 布隆过滤器
struct HashStr1{
	// BKDR哈希算法
	size_t operator()(const std::string& str){
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); ++i){
			hash *= 131;
			hash += str[i];
		}
		return hash;
	}
};

struct HashStr2{
	// RS哈希算法
	size_t operator()(const std::string& str){
		size_t hash = 0;
		size_t magic = 63689;
		for (size_t i = 0; i < str.size(); ++i){
			hash *= magic;
			hash += str[i];
			magic *= 378551;
		}
		return hash;
	}
};

struct HashStr3{
	// SDBM哈希算法
	size_t operator()(const std::string& str){
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); ++i){
			hash *= 65599;
			hash += str[i];
		}
		return hash;
	}
};

template<class K = std::string, class Hash1 = HashStr1, class Hash2 = HashStr2, class Hash3 = HashStr3>
class bloomfilter{
public:
	bloomfilter(size_t num){
		_bs(-1);
	}
	void set(const K& key){
		// 通过多个哈希函数将数据映射到位图中
		size_t index1 = Hash1()(key);
		size_t index2 = Hash2()(key);
		size_t index3 = Hash3()(key);

		_bs.set(index1);
		_bs.set(index2);
		_bs.set(index3);
	}

	// 存在误删的问题
	void reset(const K& key){
		// 不支持删除
	}

	bool test(const K& key){
		// 判断在是不准确的，可能存在误判，判断不在是准确的。
		size_t index1 = Hash1()(key);
		if (_bs.test(index1) == false)
			return false;
		size_t index2 = Hash2()(key);
		if (_bs.test(index2) == false)
			return false;
		size_t index3 = Hash3()(key);
		if (_bs.test(index3) == false)
			return false;

		return true;
	}
private:
	// 底层其实是一个位图
	bitmap _bs;
	size_t len;
};