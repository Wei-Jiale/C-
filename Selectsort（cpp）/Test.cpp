#include<iostream>
#include<vector>
using namespace std;

void Selectsort(vector<int>& array){
	int sz = array.size();
	for (int disorder = 0; disorder < sz - 1; disorder++){
		// 设置min存储最小元素的下标（无序区间的首元素）
		int min = disorder;
		// 遍历寻找无序区间中的最小元素的下标
		for (int goal = disorder + 1; goal < sz; goal++){
			if (array[goal] < array[min]){
				min = goal;
			}
		}
		// 如果最小元素不是无序区间中的第一个元素则与无序区间的首元素交换
		if (min != disorder){
			swap(array[min], array[disorder]);
		}
	}
}

int main(){
	vector<int> array = { 7, 4, 5, 9, 8, 2, 1 };
	Selectsort(array);
	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}