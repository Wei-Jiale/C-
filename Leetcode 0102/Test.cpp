//���������ַ��� s1 �� s2��ȷ������һ���ַ������ַ��������к��ܷ�����һ���ַ�����
//����: s1 = "abc", s2 = "bca"
//���: true 
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		return s1 == s2;
	}
};