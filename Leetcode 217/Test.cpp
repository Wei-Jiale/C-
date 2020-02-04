//存在重复元素
//利用集合排除重复元素 然后对比尺寸
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set s(nums.begin(), nums.end());
		return s.size() != nums.size();
	}
};