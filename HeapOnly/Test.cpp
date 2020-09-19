// 设计一个只能在堆上创建对象的类
#include<iostream>
#include<memory>
using namespace std;

class HeapOnly{
public:
	// 静态成员函数通过类名就能被调用
	static HeapOnly* GetObject(){
		return new HeapOnly;
	}

	// 拷贝构造
	HeapOnly(const HeapOnly&) = delete;

private:
	// 构造函数
	HeapOnly(){}
};

int main(){
	shared_ptr<HeapOnly> sp1(HeapOnly::GetObject());
	// HeapOnly sp2(*sp1);
	return 0;
}