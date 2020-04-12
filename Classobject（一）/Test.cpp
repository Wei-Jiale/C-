#include<iostream>
using namespace std;
// 1.C++�е�class��struct
// C�����нṹ���ڲ�ֻ�ܶ����Ա���������ܶ��庯������C++ �нṹ���п��Զ����Ա����
// C++�����Ǹ���������class������struct
// ��struct�еĳ�ԱĬ���ǹ��е�(public)����class�г�ԱĬ����˽�е�(private)
struct AddStruct{
	int num1;
	int num2;

	int AddNum(){
		return num1 + num2;
	}
};

class AddClass{
	int num1;
	int num2;

	int AddNum(){
		return num1 + num2;
	}
};

// 2.��ķ����޶���
// public�����еķ����޶�����Χ�ڵĳ�Ա���Ա����ⲿ���з��ʣ����ǿ������������������ʹ������public�ĳ�Ա
// private��˽�еķ����޶�����Χ�ڵĳ�Ա���ܱ����ⲿ���з��ʣ�����ֻ�������ڵ��û�ʹ��private�ĳ�Ա
// ���ܶ����ڵ����������޸ģ��������ݵİ�ȫ��
class AddClass{
private:
	int _num1;
	int _num2;
public:
	void GetNum1(int num1){
		_num1 = num1;
	}
	void GetNum2(int num2){
		_num2 = num2;
	}
	int AddNum(){
		return _num1 + _num2;
	}
};

// 3.���������
// ���ڶ���ĳ�Ա������Ĭ����Ϊ���������Դ�
// ���ǿ���ͨ�����޶����������ⶨ�庯�����������ǾͿ��Խ������Ͷ���ֿ���ʹ����ɶ��Ը���
class AddClass{
private:
	int _num1;
	int _num2;
public:
	//Ĭ��������Ϊ�˿ɶ������ǻ��Ǽ��������ı�־
	inline void GetNum1(int num1){
		_num1 = num1;
	}
	inline void GetNum2(int num2){
		_num2 = num2;
	}
	//����������
	int AddNum();
};
//�����ⶨ��
int AddClass::AddNum(){
	return _num1 + _num2;
}

// 4.���ʵ����
// ������������������Ҫʹ�õĶ���
class AddClass{
private:
	int _num1;
	int _num2;
public:
	//Ĭ��������Ϊ�˿ɶ������ǻ��Ǽ��������ı�־
	inline void GetNum1(int num1){
		_num1 = num1;
	}
	inline void GetNum2(int num2){
		_num2 = num2;
	}
	//����������
	int AddNum();
};
//�����ⶨ��
int AddClass::AddNum(){
	return _num1 + _num2;
}

int main(){
	AddClass add;//���ʵ����
	add.GetNum1(1);//��Ա����
	add.GetNum2(2);
	cout << add.AddNum() << endl;
}

// 5.thisָ��
// ����������ͬһ�������У���ô��������ô�������ĸ���������˳�Ա�����أ����ǣ������ÿ���������صĳ�Աthisָ��
// ����һ��ָ���������ָ�롣����Ĭ����Ϊ��Ա�������õĵ�һ�������������ó�Ա�����Ķ����ַ�����ں����ڲ��ҵ������еĳ�Ա
class AddClass{
private:
	int _num1;
	int _num2;
public:
	//Ĭ��������Ϊ�˿ɶ������ǻ��Ǽ��������ı�־
	inline void GetNum1(int num1)
	//inline void GetNum1(AddClass* this, int num1)
	{
		_num1 = num1;
	}
	inline void GetNum2(int num2)
	{
		_num2 = num2;
	}
	//����������
	int AddNum();
	//int AddNum(AddClass* this);
};
//�����ⶨ��
int AddClass::AddNum(){
	return _num1 + _num2;
}

int main(){
	AddClass add;
	add.GetNum1(1);
	//add.GetNum1(&add, 1);
	add.GetNum2(2);
	cout << add.AddNum() << endl;
	//AddNum(&add);
}

// ע�⣺1��thisָ�벻�洢�����У�ÿ����������thisָ��洢�ĵط���������ͬ����vs��thisָ��洢�ڼĴ�����
// ע�⣺2��thisָ�����Ϊ�գ�����һ��������Ҫ���ʶ����г�Ա�ĺ����ͻ�����thisΪ�շ����ڴ�Խ������±���