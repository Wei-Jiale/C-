#include<iostream>
using namespace std;

// 1.���캯��->��ɶ���ĳ�ʼ����������������ͬ��ʵ�����Զ����á��޷���ֵ��֧�����أ�
class Date{
public:
	//���ι��캯�� 
	/*Date(int year = 0, int month = 1, int day = 1){
	_year = year;
	_month = month;
	_day = day;
	}*/
	// ȫȱʡ �����κ��޲κ϶�Ϊһ��ȫȱʡҲ��Ĭ�Ϲ��캯����
	// ע�⣺ȫȱʡ���ܻ���޲γ�ͻ��ȫȱʡ���޲β���ͬʱ���ڣ�����ʱ��������
	Date(int year = 0, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}

	//���û�г�ʼ����������ݵĲ�׼ȷ��
	/*void Init(int year, int month, int day){
	_year = year;
	_month = month;
	_day = day;
	}*/

	//�޲ι��캯����û����ʾ���幹�캯��������������Զ�����һ��Ĭ�ϵ��޲ι��캯����
	// Ĭ�Ϲ��캯������������͵ĳ�Ա����û��������
	// Ĭ�Ϲ��캯������Զ������͵ĳ�Ա���������ù��캯����ɳ�ʼ��

	/*Date(){
	_year = 0;
	_month = 1;
	_day = 1;
	}*/

	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main(){
	Date d1(2020, 4, 13);// ���ã�����+����
	d1.Print();

	Date d2;
	d2.Print();

	return 0;
}