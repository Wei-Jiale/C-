//我们定义，在以下情况时，单词的大写用法是正确的：
//全部字母都是大写，比如"USA"。
//单词中所有字母都不是大写，比如"leetcode"。
//如果单词不只含有一个字母，只有首字母大写， 比如 "Google"
#include<iostream>
#include<string>
using namespace std;
//其实只要记录有多少个大写字母即可
//如果大写字母的个数小于正在遍历的下标，说明不符合题解
//不是连续的出现大写字母，如 “AaAa” 遍历到第二个 A 时的情况。
//最终判断是否为全大写或只是首字母大写即可。
class Solution {
public:
	bool detectCapitalUse(string word) {
		int uc = 0;
		for (int i = 0; i < word.size(); i++) {
			if (isupper(word[i]) && ++uc <= i) {
				return false;
			}
		}
		return uc == word.size() || uc <= 1;
	}
};