#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int Polish(vector<string>& tokens) {
		// 借助栈
		stack<int> st;
		for (auto& str : tokens){
			// 如果是操作符则运算
			if (str == "+" || str == "-" || str == "*" || str == "/"){
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();

				// switch只支持内置类型
				switch (str[0]){
				case '+':
					st.push(left + right);
					break;
				case '-':
					st.push(left - right);
					break;
				case '*':
					st.push(left * right);
					break;
				case '/':
					st.push(left / right);
					break;
				}
			}
			else{
				// 如果是操作数则入栈(将string转换为其他类型)
				st.push(stoi(str));
			}
		}

		return st.top();
	}
};