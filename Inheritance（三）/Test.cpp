#include<iostream>
#include<string>
using namespace std;

// ����
class Person{
public:
	// ���๹��
	Person(const char* name = "peter")
		:_name(name)
	{
		cout << "Person()�����๹��" << endl;
	}

	// ���࿽������
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)�����࿽������" << endl;
	}

	// ���ำֵ����
	Person& operator=(const Person& p){
		cout << "Person& operator=(const Person& p)�����ำֵ����" << endl;
		if (this != &p){
			_name = p._name;
		}
		return *this;
	}

	// ��������
	~Person(){
		cout << "~Person()����������" << endl;
	}

protected:
	string _name; // ����
};

// ������
class Student :public Person{
public:
	// �����๹��
	Student(const char* name = "jack", int num = 1)
		:Person(name)
		, _num(num)
	{
		cout << "Student()�������๹��" << endl;
	}

	// �����࿽������
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)�������࿽������" << endl;
	}

	// �����ำֵ����
	Student& operator=(const Student& s){
		cout << "Student& operator= (const Student& s)�������ำֵ����" << endl;
		if (this != &s){
			Person::operator=(s);
			_num = s._num;
		}

		return *this;
	}

	// ����������
	~Student(){
		cout << "~Student()������������" << endl;
	}
		
protected:
	int _num;// ѧ��
};

int main(){
	Student s1;
	Student s2(s1);
	Student s3("lucky", 2);
	s1 = s3;
}