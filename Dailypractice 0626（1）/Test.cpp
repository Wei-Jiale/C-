// 检查数组中出现超过一半的数
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// 排序
		sort(gifts.begin(), gifts.end());
		// 超过一半的数必然在中间
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++){
			// 统计排在中间数的个数
			if (gifts[i] == middle){
				count++;
			}
		}
		// 检测排在中间的数出现次数是否超过数组的一半
		if (count>n / 2){
			return middle;
		}
		else{
			return 0;
		}
	}
};