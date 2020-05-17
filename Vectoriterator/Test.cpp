#include<iostream>
#include<vector>
using namespace std;

void PrintVector(const vector<int>& array){
	// const对象使用const迭代器进行遍历打印
	vector<int>::const_iterator it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main(){
	vector<int> array;

	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);

	// 使用正向迭代器进行遍历(可修改)
	vector<int>::iterator it = array.begin();
	while (it != array.end()){
		*it *= 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 使用反向迭代器进行遍历
	vector<int>::reverse_iterator rit = array.rbegin();
	while (rit != array.rend()){
		*rit /= 2;
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// const迭代器
	PrintVector(array);
}