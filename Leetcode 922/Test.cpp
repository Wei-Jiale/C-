//����һ���Ǹ��������� A�� A ��һ��������������һ��������ż����
//�� A[i] Ϊ����ʱ��i Ҳ���������� A[i] Ϊż��ʱ�� i Ҳ��ż����
//[4,2,5,7]
//�����[4, 5, 2, 7]

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