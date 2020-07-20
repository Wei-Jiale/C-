// 后缀表达式求值
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main(){
	int n;
	int a, b, ret;
	while (cin >> n){
		vector<string> s(n);
		stack<int> st;
		for (int i = 0; i<n; i++){
			cin >> s[i];
		}
		for(int i = 0; i<n; i++){
			if (s[i][0] >= '0'&&s[i][0] <= '9'){
				st.push(atoi(s[i].data()));
			}
			else{
				a = st.top();
				st.pop();
				b = st.top();
				st.pop();
				switch (s[i][0]){
					case '+': st.push(a + b); break;
					case '-': st.push(b - a); break;
					case '*': st.push(a*b); break;
					case '/': st.push(b / a); break;
				}
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}