#include<iostream>
using namespace std;

// ���Ͳ�ȷ��
template<class T>
class SmartPtr{
	// �����ǹ�����Դ���ͷ�
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr(){
		if (_ptr){
			cout << "delete��" << _ptr << endl;
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
		throw invalid_argument("��0����");
	}
	return a / b;
}

void func(){
	int* ptr = new int;
	// ���ۺ��������������������쳣�����ᵼ��sp�����������ڵ���֮�󣬵�������������
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