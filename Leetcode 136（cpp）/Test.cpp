//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int val = 0;
		for (auto e : nums){
			val ^= e;
		}

		return val;
	}
};

// �κ����� 0 ��������㣬�����Ȼ��ԭ������
// �κ�������������������㣬����� 0