//ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��
//ʹ��setȥ��
//�ж�size
#include<iostream>
class Solution {
public:
	bool isUnique(string astr) {
		return set(astr.begin(), astr.end()).size() == astr.size();
	}
};