#include<iostream>
using namespace std;

// ��������أ����ǿ���ͨ���������ָ�������������ǵ��Զ������ͣ��Զ��������ڱȽϵ�ʱ���൱�ڵ������غ�����
class Date{
public:
	Date(int year = 0, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//���������
	//d1 == d2  (&d1,d2)
	bool operator==(const Date& d){
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	//d1 > d2
	bool operator>(const Date& d){
		if (_year > d._year){
			return true;
		}
		else if (_year == d._year&&_month > d._month){
			return true;
		}
		else if (_year == d._year&&_month == d._month&&_day > d._day){
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

// ��������غ���(��������ʾ����̫�ࡢ�����޷�����˽�г�Ա��
//bool operator==(const Date& d1, const Date& d2){
//	return d1._year == d2._year&& d1._month == d2._month&& d1._day == d2._day;
//}

int main(){
	Date d1(2020, 4, 14);
	Date d2(2020, 4, 15);
	cout << (d1 == d2) << endl;
	cout << (d1 > d2) << endl;

	return 0;
}
