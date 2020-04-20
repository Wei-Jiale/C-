#include<stdio.h>
using namespace std;
class Date{
public:
	//Date(int year = 0, int month = 1, int day = 1){
	//	// 函数体内赋值
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	Date(int year = 0, int month = 1, int day = 1)
		// 初始化列表（：开始 ，分隔）
		// 初始化列表可以理解为是对象的成员变量定义的地方
		// 初始化列表是和构造函数写在一起的，会在执行成员函数函数体之前优先利用初始化列表对成员变量赋予初值。
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	// 为什么会出现初始化列表呢？
	// 有些成员变量必须在初始化列表里进行初始化：引用（必须初始化），const修饰（必须初始化），没有默认的构造函数(自定义类型自动调构造函数初始化)
	// 默认生成的无参构造函数不会进行成员变量的初始化

	// 注：成员变量声明的次序就是其在初始化列表中的初始化顺序

private:
	int _year;
	int _month;
	int _day;
};
int main(){

	return 0;
}