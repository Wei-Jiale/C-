#include<iostream>
using namespace std;

// 1.析构函数->完成对象的资源清理工作（函数名在类名前加、无返回值无参数、一个类有且只有一个析构函数、对象生命周期结束编译器自动调用）
// 注意：不是完成对象的销毁
// 资源清理：资源（比如栈中malloc的空间）
class Stack{
public:
	//构造函数
	Stack(int n = 10){
		cout << "Stack()" << this << endl;
		_a = (int*)malloc(sizeof(int)*n);
		_size = 0;
		_capacity = n;
	}
	//析构函数(后进先析构）
	//默认析构函数：针对内置类型不做处理  针对自定义类型会调用对应的析构函数完成清理
	//用户显示定义析构函数后，编译器不再生成默认析构函数
	~Stack(){
		cout << "~Stack()" << this << endl;
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
	}
	void Push(int x);
	void Pop();
	size_t Size();

private:
	int* _a;
	int _size;
	int _capacity;
};

int main(){
	Stack st1;
	Stack st2;

	return 0;
}