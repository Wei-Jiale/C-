//2的幂
//输入: 1
//输出: true
//输入: 218
//输出: false

#include<iostream>
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 1) return true;
		long mi = 2;//防止溢出所以用long类型
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