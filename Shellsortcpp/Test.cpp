#include<iostream>
#include<vector>
using namespace std;

void Shellsort(vector<int>& array){
	// 设置增量并逐步缩小增量
	int sz = array.size();
	for (int gap = sz / 2; gap > 0; gap /= 2){
		// 从第gap个元素，逐个对其所在组进行直接插入排序操作
		for (int disorder = gap; disorder < sz; disorder++){
			int goal = disorder;
			while (goal - gap >= 0 && array[goal] < array[goal - gap]){
				swap(array[goal], array[goal - gap]);
				goal -= gap;
			}
		}
	}
}

int main(){
	vector<int> array = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	Shellsort(array);
	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}
