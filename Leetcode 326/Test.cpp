//3����
//����: 27
//���: true
//����: 45
//���: false
#include<iostream>
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n == 1){
			return true;
		}

		long min = 3;

		while (min <= n){
			if (min == n){
				return true;
			}
			else{
				min *= 3;
				if (min>INT_MAX){
					break;
				}
			}
		}

		return false;
	}
};