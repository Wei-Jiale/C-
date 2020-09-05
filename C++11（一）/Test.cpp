// C++11 列表初始化
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>

using namespace std;

class Point{
public:
	Point(int x = 0, int y = 0)
		:_x(x)
		, _y(y)
	{}
private:
	int _x;
	int _y;
};

int main(){
	// C++11
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	vector<int> v2{1, 2, 3, 4, 5, 6};

	list<int> l1 = { 1, 2, 3, 4, 5, 6 };
	list<int> l2{ 1, 2, 3, 4, 5, 6 };

	map<string, int> m1 = { { "苹果", 1 }, { "西瓜", 2 } };
	map<string, int> m2{ { "苹果", 1 }, { "西瓜", 2 } };

	Point p1(1, 2);
	Point p2{ 1, 2 };
	Point p3 = { 1, 2 };

}