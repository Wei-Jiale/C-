#include<iostream>
using namespace std;

// 1.��������->��ɶ������Դ��������������������ǰ�ӡ��޷���ֵ�޲�����һ��������ֻ��һ�����������������������ڽ����������Զ����ã�
// ע�⣺������ɶ��������
// ��Դ������Դ������ջ��malloc�Ŀռ䣩
class Stack{
public:
	//���캯��
	Stack(int n = 10){
		cout << "Stack()" << this << endl;
		_a = (int*)malloc(sizeof(int)*n);
		_size = 0;
		_capacity = n;
	}
	//��������(�����������
	//Ĭ����������������������Ͳ�������  ����Զ������ͻ���ö�Ӧ�����������������
	//�û���ʾ�������������󣬱�������������Ĭ����������
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