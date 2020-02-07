//买卖股票的最佳时期
//利润最大
//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//注意你不能在买入股票前卖出股票。
//输入: [7,1,5,3,6,4]
//输出: 5
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0){
			return 0;
		}

		int pmax = 0;
		int pmin = prices[0];

		for (int i = 1; i<prices.size(); i++){
			pmin = min(pmin, prices[i]);
			pmax = max(pmax, prices[i] - pmin);
		}

		return pmax;
	}
};