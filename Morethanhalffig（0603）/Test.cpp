#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()){
			return 0;
		}

		// 排序数组
		sort(numbers.begin(), numbers.end());
		// 取出数组中间数
		int middle = numbers[numbers.size() / 2];

		// 判断中间数出现次数是否超过数组长度的一半
		int count = 0;
		for (int i = 0; i<numbers.size(); i++){
			if (middle == numbers[i]){
				count++;
			}
		}
		return (count>numbers.size() / 2) ? middle : 0;
	}
};