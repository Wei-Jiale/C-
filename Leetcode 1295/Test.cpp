//统计位数为偶数的数字
//使用整数转换为字符函数再判断长度
class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int ans = 0;
		for (int num : nums) {
			if (to_string(num).size() % 2 == 0) {
				++ans;
			}
		}
		return ans;
	}
};