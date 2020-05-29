#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int Polish(vector<string>& tokens) {
		// ����ջ
		stack<int> st;
		for (auto& str : tokens){
			// ����ǲ�����������
			if (str == "+" || str == "-" || str == "*" || str == "/"){
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();

				// switchֻ֧����������
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
				// ����ǲ���������ջ(��stringת��Ϊ��������)
				st.push(stoi(str));
			}
		}

		return st.top();
	}
};