//����һ������ n�����㷵�� ���� һ���� n �� ������ͬ ��������ɵ����飬������ n ������Ӻ�Ϊ 0 ��
//���룺n = 5
//�����[-7, -1, 1, 3, 4]

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