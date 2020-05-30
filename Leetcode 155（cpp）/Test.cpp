#include<stack>
using namespace std;

class MinStack {
public:
	// 定义正常栈和最小栈
	stack<int> normal;
	stack<int> min;

	MinStack() {

	}

	void push(int x) {
		// normal栈正常入数据
		normal.push(x);
		// min栈进行比较选择入哪类数据
		if (min.empty() || x <= min.top()){
			min.push(x);
		}
		else{
			min.push(min.top());
		}
	}

	// 删除栈顶元素
	void pop() {
		// 删除栈顶元素：normal和min一起处理
		normal.pop();
		min.pop();
	}

	// 获取栈顶元素
	int top() {
		return normal.top();
	}

	// 检索栈中最小的元素
	int getMin() {
		return min.top();
	}
};