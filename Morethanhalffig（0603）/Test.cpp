#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()){
			return 0;
		}

		// ��������
		sort(numbers.begin(), numbers.end());
		// ȡ�������м���
		int middle = numbers[numbers.size() / 2];

		// �ж��м������ִ����Ƿ񳬹����鳤�ȵ�һ��
		int count = 0;
		for (int i = 0; i<numbers.size(); i++){
			if (middle == numbers[i]){
				count++;
			}
		}
		return (count>numbers.size() / 2) ? middle : 0;
	}
};