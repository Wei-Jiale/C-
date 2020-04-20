#include<iostream>
using namespace std;

class Date{
public:
	Date(int year = 0, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}
	// const����*this ָ��Ķ���
	void Print()const{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	// const Date *p1������*p1 ָ��ָ�������
	// Date const *p2������*p2 ָ��ָ�������
	// Date* const p3������ p3 ָ�뱾�� 
private:
	int _year;
	int _month;
	int _day;
};
// ������ó�Ա����
void func(const Date& d){
	d.Print();
}

int main(){
	Date d1 = (2020, 4, 20);
	func(d1);
	return 0;
}