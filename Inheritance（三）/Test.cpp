#include<iostream>
#include<string>
using namespace std;

// 基类
class Person{
public:
	// 基类构造
	Person(const char* name = "peter")
		:_name(name)
	{
		cout << "Person()：基类构造" << endl;
	}

	// 基类拷贝构造
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)：基类拷贝构造" << endl;
	}

	// 基类赋值构造
	Person& operator=(const Person& p){
		cout << "Person& operator=(const Person& p)：基类赋值构造" << endl;
		if (this != &p){
			_name = p._name;
		}
		return *this;
	}

	// 基类析构
	~Person(){
		cout << "~Person()：基类析构" << endl;
	}

protected:
	string _name; // 姓名
};

// 派生类
class Student :public Person{
public:
	// 派生类构造
	Student(const char* name = "jack", int num = 1)
		:Person(name)
		, _num(num)
	{
		cout << "Student()：派生类构造" << endl;
	}

	// 派生类拷贝构造
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)：派生类拷贝构造" << endl;
	}

	// 派生类赋值构造
	Student& operator=(const Student& s){
		cout << "Student& operator= (const Student& s)：派生类赋值构造" << endl;
		if (this != &s){
			Person::operator=(s);
			_num = s._num;
		}

		return *this;
	}

	// 派生类析构
	~Student(){
		cout << "~Student()：派生类析构" << endl;
	}
		
protected:
	int _num;// 学号
};

int main(){
	Student s1;
	Student s2(s1);
	Student s3("lucky", 2);
	s1 = s3;
}