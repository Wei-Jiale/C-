//给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。
//输入：n = 5
//输出：[-7, -1, 1, 3, 4]

class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> ans;
		int sum = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans.push_back(i);
			sum += i;
		}
		ans.push_back(-sum);
		return ans;
	}
};