//2����
//����: 1
//���: true
//����: 218
//���: false

#include<iostream>
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 1) return true;
		long mi = 2;//��ֹ���������long����
		while (mi <= n)
		{
			if (mi == n)
				return true;
			else
			{
				mi *= 2;
				if (mi>INT_MAX)
					break;
			}
		}
		return false;
	}
};