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

	// i,j分别遍历array1和array2
	int i = 0;
	int j = 0;
	// begin是原始数组的开始
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
	// 两两归并 每次得到长度为sz的有序序列
	// 终止条件：得到一个长度为N的有序序列
	for (int sz = 1; sz < N; sz *= 2){
		// 控制归并时 每组开始的元素下标
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