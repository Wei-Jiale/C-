#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);

	// 获取vector的size和capacity
	cout << array.size() << endl;
	cout << array.capacity() << endl;
	vector<int>::iterator it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;


	// 改变vector的size为3
	array.resize(3);
	cout << array.size() << endl;
	cout << array.capacity() << endl;
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 改变vector的size为10，多余空间用10填充
	array.resize(10, 10);
	cout << array.size() << endl;
	cout << array.capacity() << endl;
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 为vector预留空间
	array.reserve(100);
	cout << array.capacity() << endl;

}