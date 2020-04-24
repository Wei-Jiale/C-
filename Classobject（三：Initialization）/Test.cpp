#include <iostream>
using namespace std;
class A
{
public:
	A(int x = 4, int y = 5) :_x(x), _y(y)
	{

	}
	int GetX()
	{
		return _x;
	}
	int GetY()
	{
		return _y;
	}
private:
	int _x;
	int _y;
};
class Test
{
public:
	Test(int a, int& b, int c, A d) :_a(a), _b(b), _c(c), _d(d)
	{
		cout << _a << "\t" << _b << "\t" << _c << "\t" << _d.GetX() << "\t" << d.GetY() << endl;
		cout << "building seccess" << endl;
	}
private:
	const int _a;
	int& _b;
	int _c;
	A _d;

};
int main()
{
	int b = 2;
	A d;
	Test(1, b, 3, d);
}