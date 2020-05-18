#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> array;
	// β��
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	vector<int>::iterator it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// βɾ
	array.pop_back();
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// insert
	// ע��posλ���ǵ�����
	array.insert(array.begin(), 0);
	array.insert(array.begin()+3, 3);
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// erase
	// ע��posλ���ǵ�����
	array.erase(array.begin());
	it = array.begin();
	while (it != array.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// operator[]���ж�д
	array[0] = 0;
	for (int cur = 0; cur < array.size(); cur++){
		cout << array[cur] << " ";
	}
	cout << endl;

	// swap
	// ������array��Ϊ��
	vector<int> v;
	v.swap(array);
	for (const auto& e : v){
		cout << e << " ";
	}
	cout << endl;

	// find
	// ɾ��vector�м�ֵΪ3��Ԫ��
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	if (pos != v.end()){
		v.erase(pos);
	}
	for (const auto& e : v){
		cout << e << " ";
	}
	cout << endl;
}