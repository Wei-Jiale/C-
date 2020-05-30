#include<stack>
using namespace std;

class MinStack {
public:
	// ��������ջ����Сջ
	stack<int> normal;
	stack<int> min;

	MinStack() {

	}

	void push(int x) {
		// normalջ����������
		normal.push(x);
		// minջ���бȽ�ѡ������������
		if (min.empty() || x <= min.top()){
			min.push(x);
		}
		else{
			min.push(min.top());
		}
	}

	// ɾ��ջ��Ԫ��
	void pop() {
		// ɾ��ջ��Ԫ�أ�normal��minһ����
		normal.pop();
		min.pop();
	}

	// ��ȡջ��Ԫ��
	int top() {
		return normal.top();
	}

	// ����ջ����С��Ԫ��
	int getMin() {
		return min.top();
	}
};