#include<iostream>
#include<queue>
#include<functional> // 仿函数头文件
using namespace std;

void test_priority_queue(){
	// 默认大的优先级高
	// 优先级队列底层实际是一个大堆
	//priority_queue<int> pq;
	// 应用仿函数使小的优先级高
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(3);
	pq.push(1);
	pq.push(9);
	pq.push(4);
	pq.push(2);

	// 容器适配器不支持迭代器
	// 容器适配器通常包含特殊的性质，迭代器会破坏容器适配器原有性质
	while (!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
}

int main(){
	test_priority_queue();
	return 0;
}