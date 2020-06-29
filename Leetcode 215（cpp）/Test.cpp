// ��Ŀ����δ������������ҵ��� k ������Ԫ��
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
// �ⷨһ��
// ʱ�临�Ӷȣ�O(N*logN)
// �ռ临�Ӷȣ�O(N)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// �������ȼ�����
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

// �ⷨ����
// ʱ�临�Ӷȣ�O(N*logN)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// ����
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};

// �ⷨ����
// ʱ�临�Ӷȣ�O(N*logK)
// �ռ临�Ӷȣ�O(K)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// ����K������С�ѣ����ڶѶ����ѣ�
		priority_queue<int, vector<int>, greater<int>> pq;
		// ǰK�����Ƚ���
		for (int i = 0; i<k; i++){
			pq.push(nums[i]);
		}
		// �Ƚ�ʣ�����ͶѶ����Ĵ�С
		for (int j = k; j<nums.size(); j++){
			if (nums[j]>pq.top()){
				pq.pop();
				pq.push(nums[j]);
			}
		}
		return pq.top();
	}
};