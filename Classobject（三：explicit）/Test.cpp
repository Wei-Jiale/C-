#include<iostream>
using namespace std;

class Date{
public:
	Date(int year)
		:_year(year)
	{}

	/*explicit Date(int year) 防止隐式类型转换的发生
		:_year(year)
	{}*/

private:
	int _year;
	int _month;
	int _day;
};

void TestDate(){
	Date d1(2018);
	// 用一个整形变量给日期类型对象赋值
	// 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
	d1 = 2019;
}

int main(){
	return 0;
}
