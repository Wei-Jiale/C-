// µœ÷strstr
#include<iostream>
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		int pos = haystack.find(needle);
		return pos;
	}
};