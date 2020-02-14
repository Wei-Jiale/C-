//给定两个字符串 s1 和 s2，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
//输入: s1 = "abc", s2 = "bca"
//输出: true 
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		return s1 == s2;
	}
};