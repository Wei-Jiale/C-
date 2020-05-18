#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> array;
	// 尾插
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	vector<int>::iterator it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// 尾删
	array.pop_back();
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// insert
	// 注意pos位置是迭代器
	array.insert(array.begin(), 0);
	array.insert(array.begin()+3, 3);
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// erase
	// 注意pos位置是迭代器
	array.erase(array.begin());
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// operator[]进行读写
	array[0] = 0;
	for (int cur = 0; cur < array.size(); cur++){
		cout << array[cur] << " ";
	}
	cout << endl;

	// swap
	// 交换后array变为空
	vector<int> v;
	v.swap(array);
	for (const auto& e : v){
		cout << e << " ";
	}
	cout << endl;

	// find
	// 删掉vector中键值为3的元素
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	if (pos != v.end()){
		v.erase(pos);
	}
	for (const auto& e : v){
		cout << e << " ";
	}
	cout << endl;
}