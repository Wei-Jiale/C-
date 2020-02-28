//找不同
//输入：s = "abcd"、t = "abcde"
//输出：e
//字符串相减ASCII之和
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int sum = 0;
		for (int i = 0; i<t.length(); i++)
		{
			sum += t[i];
			if (i < s.length())
				sum -= s[i];
		}
		return (char)sum;
	}
};