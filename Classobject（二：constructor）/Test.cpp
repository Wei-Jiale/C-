#include<iostream>
using namespace std;

// 1.构造函数->完成对象的初始化工作（与类名相同、实例化自动调用、无返回值、支持重载）
class Date{
public:
	//带参构造函数 
	/*Date(int year = 0, int month = 1, int day = 1){
	_year = year;
	_month = month;
	_day = day;
	}*/
	// 全缺省 将带参和无参合二为一（全缺省也是默认构造函数）
	// 注意：全缺省可能会和无参冲突（全缺省和无参不能同时存在）调用时产生歧义
	Date(int year = 0, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}

	//如果没有初始化会造成数据的不准确性
	/*void Init(int year, int month, int day){
	_year = year;
	_month = month;
	_day = day;
	}*/

	//无参构造函数（没有显示定义构造函数，则编译器会自动生成一个默认的无参构造函数）
	// 默认构造函数针对内置类型的成员变量没有做处理
	// 默认构造函数针对自定义类型的成员变量，调用构造函数完成初始化

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
	Date d1(2020, 4, 13);// 调用：对象+参数
	d1.Print();

	Date d2;
	d2.Print();

	return 0;
}