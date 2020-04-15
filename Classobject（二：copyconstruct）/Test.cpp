#include<iostream>
using namespace std;

// 拷贝构造函数：用来实例化与某一对象相同的对象的，他会将该对象的数据完全复制一份相同的出来
// 特性：是构造函数的重载形式、拷贝构造函数的参数只有一个且必须使用引用传参（传值会引发无穷递归）
// 无穷递归的原因：调用就是拷贝构造  调用函数时要先传参  传参的过程又是一个拷贝构造（d1初始化d，调用拷贝构造）
class Date{
public:
	Date(int year = 0, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}
	// Date d2(d1)：对象初始化时自动掉用拷贝构造
	// 拷贝构造传引用：Date& d2 = d1;
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main(){
	Date d1(2020, 4, 14);
	Date d2(d1);// 拷贝构造：d1是d2的拷贝
	d1.Print();
	d2.Print();

}

// 默认拷贝构造函数：未显示定义拷贝构造则编译器会自动生成（但是只能完成简单的浅拷贝）
// 如果我们想要对复杂的如链表类进行拷贝构造，则需要自己定义

