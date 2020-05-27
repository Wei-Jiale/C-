// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		// 统计所有32个位中，每个位合计1出现的次数
		int bitsArray[32] = { 0 };
		for (auto val : nums){
			for (size_t i = 0; i < 32; ++i){
				if (val & (1 << i)){
					bitsArray[i]++;
				}
			}
		}
		int num = 0;
		for (size_t i = 0; i < 32; ++i){
			// 次数为3N+1的位就是只出现了一次的数的位
			if (bitsArray[i] % 3 == 1){
				num |= (1 << i);
			}
		}

		return num;
	}
};