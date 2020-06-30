// 基类和派生类中有同名成员，派生类成员将屏蔽基类对同名成员的直接访问,这种情况叫隐藏，也叫重定义
// 在派生类成员函数中，可以使用 <基类 :: 基类成员> 指定作用域，显示访问基类中的同名成员。
#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
	string _name = "小李"; // 姓名
	int _num = 11; // 身份证号
};
class Student : public Person{
public:
	void Print(){
		cout << " 姓名:" << _name << endl;
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 99; // 学号
};
void Test(){
	Student s1;
	s1.Print();
};

int main(){
	Test();
	return 0;
}