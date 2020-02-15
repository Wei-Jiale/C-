//找出数组中重复的数字
//输入：[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3 
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		if (nums.empty())
			return -1;

		for (int i = 0; i < nums.size(); ++i)
		{
			while (nums[i] != i)
			{
				if (nums[i] == nums[nums[i]])
					return nums[i];
				else
					swap(nums[i], nums[nums[i]]);
			}
		}

		return -1;
	}
};