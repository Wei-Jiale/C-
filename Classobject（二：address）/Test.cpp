#include<iostream>
using namespace std;
class Student{
	// Ĭ�����ɵ�ȡ��ַ��constȡ��ַ����������
	Student* operator&()
	{
		return this;
	}

	const Student* operator&() const
	{
		return this;
	}
};
// ������Ĭ�ϳ�Ա����������������Ĭ�����ɵĳ�Ա������һ������²���Ҫ������ʽ����
// �����������ñ���ͨ��ȡ��ַ�����ָ�������ݡ�
