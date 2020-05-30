#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// 判断出栈顺序是符合栈定义
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		// 用栈来模拟进出
		stack<int> st;
		// 遍历入栈vector
		int pushi = 0;
		// 遍历出栈vector
		int popi = 0;

		while (pushi < pushed.size()){
			// 入栈栈序列还有数据则入栈
			st.push(pushed[pushi]);
			pushi++;

			// 每次入栈完成都要和出栈序列对比（有可能连续出栈匹配）
			while (!st.empty() && st.top() == popped[popi]){
				// 匹配则出栈
				st.pop();
				popi++;
			}
		}

		return st.empty();
	}
};