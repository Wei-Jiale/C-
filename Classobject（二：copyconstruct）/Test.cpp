#include<iostream>
using namespace std;

// �������캯��������ʵ������ĳһ������ͬ�Ķ���ģ����Ὣ�ö����������ȫ����һ����ͬ�ĳ���
// ���ԣ��ǹ��캯����������ʽ���������캯���Ĳ���ֻ��һ���ұ���ʹ�����ô��Σ���ֵ����������ݹ飩
// ����ݹ��ԭ�򣺵��þ��ǿ�������  ���ú���ʱҪ�ȴ���  ���εĹ�������һ���������죨d1��ʼ��d�����ÿ������죩
class Date{
public:
	Date(int year = 0, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}
	// Date d2(d1)�������ʼ��ʱ�Զ����ÿ�������
	// �������촫���ã�Date& d2 = d1;
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
	Date d2(d1);// �������죺d1��d2�Ŀ���
	d1.Print();
	d2.Print();

}

// Ĭ�Ͽ������캯����δ��ʾ���忽����������������Զ����ɣ�����ֻ����ɼ򵥵�ǳ������
// ���������Ҫ�Ը��ӵ�����������п������죬����Ҫ�Լ�����

