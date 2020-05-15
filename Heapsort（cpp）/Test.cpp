#include<iostream>
#include<vector>
using namespace std;

void Adjustdown(vector<int>& array, int start, int end){
	int parent = start;
	int child = parent * 2 + 1;
	
	while (child < end){
		// 选出左右孩子中较大的
		if (child + 1 < end && array[child + 1] > array[child]){
			child++;
		}
		// 孩子和父亲比较
		if (array[child] > array[parent]){
			// 孩子大于父亲则交换
			swap(array[child], array[parent]);
			// 向下继续传递
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

void Heapsort(vector<int>& array){
	// 建堆：从最后一个非叶子结点(最后一个结点的父结点）开始进行向下调整
	int sz = array.size();
	for (int index = (sz - 1 - 1) / 2; index >= 0; index--){
		Adjustdown(array, index, sz);
	}
	// 堆排序
	while (sz > 0){
		swap(array[0], array[sz - 1]);
		sz--;
		Adjustdown(array, 0, sz);
	}

}

int main(){
	vector<int> array = { 4, 6, 8, 5, 9 };
	Heapsort(array);
	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}