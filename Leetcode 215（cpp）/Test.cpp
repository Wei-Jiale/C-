// 题目：在未排序的数组中找到第 k 个最大的元素
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
// 解法一：
// 时间复杂度：O(N*logN)
// 空间复杂度：O(N)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// 定义优先级队列
		priority_queue<int> pq;
		for (const auto&e : nums){
			pq.push(e);
		}

		while (--k){
			pq.pop();
		}

		return pq.top();
	}
};

// 解法二：
// 时间复杂度：O(N*logN)
// 空间复杂度：O(1)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// 排序
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};

// 解法三：
// 时间复杂度：O(N*logK)
// 空间复杂度：O(K)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// 建立K个数的小堆（大于堆顶进堆）
		priority_queue<int, vector<int>, greater<int>> pq;
		// 前K个数先进堆
		for (int i = 0; i<k; i++){
			pq.push(nums[i]);
		}
		// 比较剩余数和堆顶数的大小
		for (int j = k; j<nums.size(); j++){
			if (nums[j]>pq.top()){
				pq.pop();
				pq.push(nums[j]);
			}
		}
		return pq.top();
	}
};