#include<iostream>
#include<vector>
using namespace std;

void Bubblesort(vector<int>& array){
	int sz = array.size();
	// ���ѭ������ÿһ��ð�ݵĴ���
	for (int out = 0; out < sz - 1; out++){
		bool flag = true;
		// �ڲ�ѭ�����Ƶ�������
		for (int in = 0; in < sz - out - 1; in++){
			if (array[in]>array[in + 1]){
				swap(array[in], array[in + 1]);
				flag = false;
			}
		}
		// һ��������û�н��н���˵���Ѿ�����
		if (flag == true){
			break;
		}
	}
}

int main(){
	vector<int> array = { 9, 3, 1, 4, 2, 7, 8, 6, 5 };
	Bubblesort(array);
	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}