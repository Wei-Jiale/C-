// 一只成熟的兔子每天能产下一胎兔子
// 每只小兔子的成熟期是一天
// 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子
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