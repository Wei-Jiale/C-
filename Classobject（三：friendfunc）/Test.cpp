#include<iostream>
using namespace std;

class Date{
	//友元函数
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

//不放在类中是因为有隐含this指针干扰
//返回ostream 解决了连续输出的问题
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
