// ���һ��ֻ����ջ�ϴ����������
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