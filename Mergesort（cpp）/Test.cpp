#include<iostream>
#include<vector>
using namespace std;

//void Merge(vector<int>& array, int begin, int mid, int end){
//	vector<int> array1;
//	vector<int> array2;
//	for (int i = begin; i <= mid; i++){
//		array1.push_back(array[i]);
//	}
//	for (int i = mid + 1; i <= end; i++){
//		array2.push_back(array[i]);
//	}
//
//	// i,j分别遍历array1和array2
//	int i = 0;
//	int j = 0;
//	// begin是原始数组的开始
//	int k = begin;
//	while (i < array1.size() && j < array2.size()){
//		if (array1[i] <= array2[j]){
//			array[k] = array1[i];
//			i++;
//			k++;
//		}
//		else{
//			array[k] = array2[j];
//			j++;
//			k++;
//		}
//	}
//
//	while (i < array1.size()){
//		array[k] = array1[i];
//		i++;
//		k++;
//	}
//	while (j < array2.size()){
//		array[k] = array2[j];
//		j++;
//		k++;
//	}
//}
//
//void Mergesort(vector<int>& array, int begin, int end){
//	if (end - begin >= 1){
//		// 未排序序列中至少有两个数据
//		int mid = (begin + end) >> 1;
//		// 分
//		Mergesort(array, begin, mid);
//		Mergesort(array, mid + 1, end);
//		// 治
//		Merge(array, begin, mid, end);
//	}
//}

void Merge(vector<int>& array, int begin, int mid, int end){
	vector<int> array1;
	for (int i = begin; i <= mid; i++){
		array1.push_back(array[i]);
	}

	// i,j分别遍历array1和array2
	int i = 0;
	int j = mid + 1;
	// begin是原始数组的开始
	int k = begin;
	while (i < array1.size() && j <= end){
		if (array1[i] <= array[j]){
			array[k] = array1[i];
			i++;
			k++;
		}
		else{
			array[k] = array[j];
			j++;
			k++;
		}
	}

	while (i < array1.size()){
		array[k] = array1[i];
		i++;
		k++;
	}
}

void Mergesort(vector<int>& array, int begin, int end){
	if (end - begin >= 1){
		// 未排序序列中至少有两个数据
		int mid = (begin + end) >> 1;
		// 分
		Mergesort(array, begin, mid);
		Mergesort(array, mid + 1, end);
		// 治
		Merge(array, begin, mid, end);
	}
}

int main(){
	vector<int> array = { 8, 4, 5, 7, 1, 3, 6, 2 };
	Mergesort(array, 0, array.size() - 1);
	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}