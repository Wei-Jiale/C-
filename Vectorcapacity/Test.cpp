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

	// ��ȡvector��size��capacity
	cout << array.size() << endl;
	cout << array.capacity() << endl;
	vector<int>::iterator it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;


	// �ı�vector��sizeΪ3
	array.resize(3);
	cout << array.size() << endl;
	cout << array.capacity() << endl;
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// �ı�vector��sizeΪ10������ռ���10���
	array.resize(10, 10);
	cout << array.size() << endl;
	cout << array.capacity() << endl;
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ΪvectorԤ���ռ�
	array.reserve(100);
	cout << array.capacity() << endl;

}