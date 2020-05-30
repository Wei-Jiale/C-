#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// �жϳ�ջ˳���Ƿ���ջ����
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		// ��ջ��ģ�����
		stack<int> st;
		// ������ջvector
		int pushi = 0;
		// ������ջvector
		int popi = 0;

		while (pushi < pushed.size()){
			// ��ջջ���л�����������ջ
			st.push(pushed[pushi]);
			pushi++;

			// ÿ����ջ��ɶ�Ҫ�ͳ�ջ���жԱȣ��п���������ջƥ�䣩
			while (!st.empty() && st.top() == popped[popi]){
				// ƥ�����ջ
				st.pop();
				popi++;
			}
		}

		return st.empty();
	}
};