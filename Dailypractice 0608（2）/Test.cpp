#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> st;
		for (auto e : A){
			switch (e){
			case'(':
				st.push(e);
				break;
			case')':
			{
				if (st.empty() || st.top() != '('){
					return false;
				}
				else{
					st.pop();
				}
			}
			break;
			default:
				return false;
			}
		}
		return true;
	}
};