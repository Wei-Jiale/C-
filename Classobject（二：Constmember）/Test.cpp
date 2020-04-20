#include<iostream>
using namespace std;

class Date{
public:
	Date(int year = 0, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}
	// const修饰*this 指向的对象
	void Print()const{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	// const Date *p1：修饰*p1 指针指向的内容
	// Date const *p2：修饰*p2 指针指向的内容
	// Date* const p3：修饰 p3 指针本身 
private:
	int _year;
	int _month;
	int _day;
};
// 对象调用成员函数
void func(const Date& d){
	d.Print();
}

int main(){
	Date d1 = (2020, 4, 20);
	func(d1);
	return 0;
}