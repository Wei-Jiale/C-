#include<stdio.h>
using namespace std;
class Date{
public:
	//Date(int year = 0, int month = 1, int day = 1){
	//	// �������ڸ�ֵ
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	Date(int year = 0, int month = 1, int day = 1)
		// ��ʼ���б�����ʼ ���ָ���
		// ��ʼ���б�������Ϊ�Ƕ���ĳ�Ա��������ĵط�
		// ��ʼ���б��Ǻ͹��캯��д��һ��ģ�����ִ�г�Ա����������֮ǰ�������ó�ʼ���б�Գ�Ա���������ֵ��
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	// Ϊʲô����ֳ�ʼ���б��أ�
	// ��Щ��Ա���������ڳ�ʼ���б�����г�ʼ�������ã������ʼ������const���Σ������ʼ������û��Ĭ�ϵĹ��캯��(�Զ��������Զ������캯����ʼ��)
	// Ĭ�����ɵ��޲ι��캯��������г�Ա�����ĳ�ʼ��

	// ע����Ա���������Ĵ���������ڳ�ʼ���б��еĳ�ʼ��˳��

private:
	int _year;
	int _month;
	int _day;
};
int main(){

	return 0;
}