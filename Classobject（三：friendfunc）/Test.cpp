#include<iostream>
using namespace std;

class Date{
	//��Ԫ����
	friend ostream& operator<<(ostream& out, Date& d);
public:
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;
};

//��������������Ϊ������thisָ�����
//����ostream ������������������
ostream& operator<<(ostream& out, Date& d){
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

int main(){
	Date d1;
	d1.Print();
	cout << d1;

	return 0;
}
