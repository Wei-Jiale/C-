// 继承的概念
#include<iostream>
#include<string>
using namespace std;

// 基类
class Person{
public:
	void Print(){
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter";
	int _age = 18;
};

// 派生类
class Student :public Person{
protected:
	int _stuid;
};

class Teacher :public Person{
protected:
	int _jobid;
};

int main(){
	Student s;
	Teacher t;
	s.Print();
	t.Print();

	return 0;
}
//Person类为基类，Student类和Teacher类继承了Person类
//基类的成员函数和成员变量都会变为派生类的一部分，实现成员变量和成员函数的复用，并且Student类和Teacher类也有自己特有的成员。