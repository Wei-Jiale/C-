//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int val = 0;
		for (auto e : nums){
			val ^= e;
		}

		return val;
	}
};

// 任何数和 0 做异或运算，结果仍然是原来的数
// 任何数和其自身做异或运算，结果是 0