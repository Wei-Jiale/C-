#include<iostream>
using namespace std;

class Person {
public:
	virtual void BuyTicket() { cout << "ÂòÆ±-È«¼Û" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "ÂòÆ±-°ë¼Û" << endl; }
};

void Func(Person& p){
	p.BuyTicket();
}

int main(){
	Person ps;
	Student st;
	Func(ps);
	Func(st);

	return 0;
}