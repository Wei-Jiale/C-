#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& array, int begin, int mid, int end){
	vector<int> array1;
	vector<int> array2;
	for (int i = begin; i <= mid; i++){
		array1.push_back(array[i]);
	}
	for (int i = mid + 1; i <= end; i++){
		array2.push_back(array[i]);
	}

	// i,j�ֱ����array1��array2
	int i = 0;
	int j = 0;
	// begin��ԭʼ����Ŀ�ʼ
	int k = begin;
	while (i < array1.size() && j < array2.size()){
		if (array1[i] <= array2[j]){
			array[k] = array1[i];
			i++;
			k++;
		}
		else{
			array[k] = array2[j];
			j++;
			k++;
		}
	}

	while (i < array1.size()){
		array[k] = array1[i];
		i++;
		k++;
	}
	while (j < array2.size()){
		array[k] = array2[j];
		j++;
		k++;
	}
}

void Mergesort(vector<int>& array){
	int N = array.size();
	// �����鲢 ÿ�εõ�����Ϊsz����������
	// ��ֹ�������õ�һ������ΪN����������
	for (int sz = 1; sz < N; sz *= 2){
		// ���ƹ鲢ʱ ÿ�鿪ʼ��Ԫ���±�
		for (int begin = 0; begin + sz < N; begin += 2 * sz){
			int mid = begin + sz - 1;
			int end = begin + 2 * sz - 1;
			if (end>N - 1){
				end = N - 1;
			}
			Merge(array, begin, mid, end);
		}
	}
}

int main(){
	vector<int> array = { 8, 4, 5, 7, 1, 3, 6, 2 };
	Mergesort(array);
	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}