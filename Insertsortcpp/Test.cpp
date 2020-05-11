#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int>& array){
	// 1.判断序列长度
	if (array.size() <= 1){
		return;
	}

	// 2.直接插入排序
	int sz = array.size();
	for (int disorder = 1; disorder < sz; disorder++){
		int goal = disorder;
		// 将未排序部分的第一个元素和有序部分的最后一个元素比较
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