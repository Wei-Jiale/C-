#include<iostream>
#include<vector>
using namespace std;

int main(){
	// n表示元素个数
	int n;
	cin >> n;

	// array中存放每个元素的值
	vector<int> array;
	array.resize(n);

	// 读入vector
	for (int i = 0; i < n; i++){
		cin >> array[i];
	}

	// 遍历数组判断
	int i = 0;
	int count = 0;

	while (i < n){
		// 非递减子序列
		if (array[i] < array[i + 1]){
			// 没有破坏非递减性质就向后遍历
			while (i < n&&array[i] <= array[i + 1]){
				i++;
			}
			count++;
			i++;
		}
		else if (array[i] == array[i + 1]){
			i++;
		}
		// 非递增子序列
		else{
			while (i < n&&array[i] >= array[i + 1]){
				i++;
			}
			count++;
			i++;
		}
	}

	cout << count << endl;
	return 0;
}