#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	// ���������
	int team;
	// IO��OJ�����ж���������������������������Ķ����������
	while (cin >> team){
		// ������ÿ����Աˮƽֵ������
		vector<int> array;
		array.resize(3 * team);
		for (int i = 0; i < 3 * team; i++){
			cin >> array[i];
		}

		// ����
		sort(array.begin(), array.end());

		// ȡ���±�Ϊ3n-2��3n-4......�����ۼ����
		long sum = 0;
		int index = 2;
		// �м���index���м���Ŀ��ֵ�ۼ�
		int teamindex = team;
		while (teamindex>0){
			sum = sum + array[3 * team - index];
			index = index + 2;
			teamindex--;
		}

		cout << sum << endl;
	}
}