#include<iostream>
#include<vector>
using namespace std;

int main(){
	// n��ʾԪ�ظ���
	int n;
	cin >> n;

	// array�д��ÿ��Ԫ�ص�ֵ
	vector<int> array;
	array.resize(n);

	// ����vector
	for (int i = 0; i < n; i++){
		cin >> array[i];
	}

	// ���������ж�
	int i = 0;
	int count = 0;

	while (i < n){
		// �ǵݼ�������
		if (array[i] < array[i + 1]){
			// û���ƻ��ǵݼ����ʾ�������
			while (i < n&&array[i] <= array[i + 1]){
				i++;
			}
			count++;
			i++;
		}
		else if (array[i] == array[i + 1]){
			i++;
		}
		// �ǵ���������
		else{
			while (i < n&&array[i] >= array[i + 1]){
				i++;
			}
			count++;
			i++;
		}
	}

	cout << count << endl;
	return 0;
}