#include<iostream>
using namespace std;

// 类型不确定
template<class T>
class SmartPtr{
	// 帮我们管理资源的释放
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr(){
		if (_ptr){
			cout << "delete：" << _ptr << endl;
			delete _ptr;
		}
	}
private:
	T* _ptr;
};

int div(){
	int a, b;
	cin >> a >> b;
	if (b == 0){
		throw invalid_argument("除0错误");
	}
	return a / b;
}

void func(){
	int* ptr = new int;
	// 无论函数是正常结束还是抛异常，都会导致sp对象生命周期到了之后，调用析构函数。
	SmartPtr<int> sp(ptr);
	cout << div() << endl;
}

int main(){
	try{
		func();
	}
	catch (exception& e){
		cout << e.what() << endl;
	}
	return 0;
}