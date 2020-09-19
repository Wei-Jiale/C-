// 设计一个只能在栈上创建对象的类
#include<iostream>
#include<memory>
using namespace std;

class StackOnly{
public:
	static StackOnly GetObject(){
		return StackOnly();
	}

private:
	StackOnly(){}
};

int main(){
	StackOnly sp = StackOnly::GetObject();
	return 0;
}