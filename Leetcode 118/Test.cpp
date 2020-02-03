//杨辉三角
#include<iostream>
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans(numRows);
		if (numRows == 0)    return ans; //若numRows为空，返回空数组
		for (int i = 0; i < numRows; ++i) //给数组一个个赋值
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0 || j == i) //若是左右两边的边界，赋值为1
					ans[i].push_back(1);
				else
					ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]); //否则赋值为该位置左上与右上的和
			}
		}
		return ans;
	}
};