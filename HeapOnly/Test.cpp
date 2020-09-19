// ���һ��ֻ���ڶ��ϴ����������
#include<iostream>
#include<memory>
using namespace std;

class HeapOnly{
public:
	// ��̬��Ա����ͨ���������ܱ�����
	static HeapOnly* GetObject(){
		return new HeapOnly;
	}

	// ��������
	HeapOnly(const HeapOnly&) = delete;

private:
	// ���캯��
	HeapOnly(){}
};

int main(){
	shared_ptr<HeapOnly> sp1(HeapOnly::GetObject());
	// HeapOnly sp2(*sp1);
	return 0;
}