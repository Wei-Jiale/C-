#pragma once
#include<vector>
#include<list>

// 用STL容器封装适配转换实现出来的queue（复用性）
namespace WJL{
	// Container：容器
	template<class T, class Container>
	class Queue{
	public:
		void push(const T& x){
			_con.push_back(x);
		}

		void pop(){
			// vector不提供pop_front()接口
			_con.pop_front();
		}

		size_t size(){
			return _con.size();
		}

		bool empty(){
			return _con.empty();
		}

		T& front(){
			return _con.front();
		}

		T& back(){
			return _con_back();
		}
	private:
		Container _con;
	};


	void Test(){
		Queue<int, list<int>> q;

		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);

		while (!q.empty()){
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;

	}
}