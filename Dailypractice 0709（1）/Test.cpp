// һֻ���������ÿ���ܲ���һ̥����
// ÿֻС���ӵĳ�������һ��
// ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ����
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long array[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++)
	{
		array[i] = array[i - 1] + array[i - 2];
	} 
	int month;
	while (cin >> month)
	{
		printf("%lld\n", array[month - 1]);
	}
}