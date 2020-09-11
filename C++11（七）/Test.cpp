#include<iostream>
#include<thread>
#include<atomic>
using namespace std;

// 仿函数
atomic<int> x = 0;
struct Add{
	void operator()(int n){
		for (int i = 0; i <= n; i++){
			++x;
		}
	}
};
int main(){
	Add add;
	thread th1(add, 1000000);
	thread th2(add, 1000000);

	th1.join();
	th2.join();
	return 0;
}

//lambda表达式
int main(){
	atomic<int> x = 0;
	auto add = [&x](int n){
		for (int i = 0; i < n; i++){
			++x;
		}
	};
	thread th1(add, 1000000);
	thread th2(add, 1000000);

	th1.join();
	th2.join();
	return 0;
}
