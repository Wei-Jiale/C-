//��Ʊ���������ʱ��
//������� ��Ƶ������
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;

		for (int i = 0; i + 1 < prices.size(); ++i){
			profit += max(prices[i + 1] - prices[i], 0);
		}

		return profit;
	}
};
//ÿ�������Ʊ �ڶ���ͳ��۵�
//ֻҪ����ɼ۱Ƚ���� ���������
//����ͳ��ۿ��Է�����ͬһ��