//ȱʧ����
//����һ������ 0, 1, 2, ..., n �� n ���������У��ҳ� 0 .. n ��û�г����������е��Ǹ�����
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