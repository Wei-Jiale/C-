#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int>& array){
	// 1.�ж����г���
	if (array.size() <= 1){
		return;
	}

	// 2.ֱ�Ӳ�������
	int sz = array.size();
	for (int disorder = 1; disorder < sz; disorder++){
		int goal = disorder;
		// ��δ���򲿷ֵĵ�һ��Ԫ�غ����򲿷ֵ����һ��Ԫ�رȽ�
		while (goal>0 && array[goal] < array[goal - 1]){
			swap(array[goal], array[goal - 1]);
			goal--;
		}
	}
}

int main(){
	vector<int> array = { 5, 2, 4, 6, 1, 3 };
	InsertSort(array);
	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}