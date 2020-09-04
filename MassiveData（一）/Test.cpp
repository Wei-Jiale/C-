// 问题：给定100亿个整数，设计算法找到只出现一次的整数
// 设置两个位图，位图1和位图2的对应位都提供一个位来标记数据。

#include<iostream>
#include<bitset>
using namespace std;

template<size_t N>
class solution{
public:
	void set(size_t x){
		if (_bs1.test(x) == false && _bs2.test(x) == false){
			// 00 变 01
			_bs2.set(x);
		}
		else if (_bs1.test(x) == false && _bs2.test(x) == true){
			// 01变10
			_bs1.set(x);
			_bs2.reset(x);
		}
	}
private:
	bitset _bs1;
	bitset _bs2;
};