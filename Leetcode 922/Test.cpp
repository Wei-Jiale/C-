//给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
//当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
//[4,2,5,7]
//输出：[4, 5, 2, 7]

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int n = A.size();

		for (int i = 0, j = 1; i < n && j < n; i += 2, j += 2) {
			while (i < n && A[i] % 2 == 0) {
				i += 2;
			}
			while (j < n && A[j] % 2 != 0){
				j += 2;
			}

			if (i < n) {
				swap(A[i], A[j]);
			}
		}

		return A;
	}
};