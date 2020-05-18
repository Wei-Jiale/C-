#include<iostream>
#include<vector>
using namespace std;

void Bubblesort(vector<int>& array){
	int sz = array.size();
	// 外层循环控制每一趟冒泡的次数
	for (int out = 0; out < sz - 1; out++){
		bool flag = true;
		// 内层循环控制单趟排序
		for (int in = 0; in < sz - out - 1; in++){
			if (array[in]>array[in + 1]){
				swap(array[in], array[in + 1]);
				flag = false;
			}
		}
		// 一趟排序中没有进行交换说明已经有序
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