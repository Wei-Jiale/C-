#pragma once
#include<vector>
#include<list>

// 用STL容器封装适配转换实现出来的stack（复用性）
namespace WJL{
	// Container：容器
	template<class T, class Container>
	class Stack{
	public:
		void push(const T& x){
			_con.push_back(x);
		}

		void pop(){
			_con.pop_back();
		}

		size_t size(){
			return _con.size();
		}

		bool empty(){
			return _con.empty();
		}

		T& top(){
			return _con.back();
		}
	private:
		Container _con;
	};


	void Test(){
		Stack<int, vector<int>> st;

		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);

		while (!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;

	}
}