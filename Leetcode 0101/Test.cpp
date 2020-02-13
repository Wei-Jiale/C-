//确定一个字符串 s 的所有字符是否全都不同。
//使用set去重
//判断size
#include<iostream>
class Solution {
public:
	bool isUnique(string astr) {
		return set(astr.begin(), astr.end()).size() == astr.size();
	}
};