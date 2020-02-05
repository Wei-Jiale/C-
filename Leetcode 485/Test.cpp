//�������1�ĸ���
class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int maxn = 0, num = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] == 1){
				num++;
				maxn = max(maxn, num);
			}
			else
				num = 0;
		}
		return maxn;
	}
};