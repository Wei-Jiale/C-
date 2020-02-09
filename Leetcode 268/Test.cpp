//缺失数字
//给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i<nums.size(); i++)
			sum = sum + i - nums[i];
		sum = sum + nums.size();
		return sum;
	}
};