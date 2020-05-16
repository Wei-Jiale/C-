#include<iostream>
#include<vector>
using namespace std;

int main(){
	// 无参构造
	vector<int> array1;

	// 构造并初始化n个val
	vector<int> array2(4, 100);

	// 拷贝构造
	vector<int> array3(array2);

	// 使用迭代器进行初始化构造
	vector<int> array4(array2.begin(), array2.end());

	// 迭代器初始化
	int array[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> array5(array, array + sizeof(array) / sizeof(array[0]));
	for (vector<int>::iterator it = array5.begin(); it != array5.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}