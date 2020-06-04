#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	// 定义分组数
	int team;
	// IO型OJ可能有多组测试用例，这里持续接收输入的多组测试用例
	while (cin >> team){
		// 定义存放每个成员水平值的容器
		vector<int> array;
		array.resize(3 * team);
		for (int i = 0; i < 3 * team; i++){
			cin >> array[i];
		}

		// 排序
		sort(array.begin(), array.end());

		// 取出下标为3n-2、3n-4......的数累加输出
		long sum = 0;
		int index = 2;
		// 有几组index就有几个目标值累加
		int teamindex = team;
		while (teamindex>0){
			sum = sum + array[3 * team - index];
			index = index + 2;
			teamindex--;
		}

		cout << sum << endl;
	}
}