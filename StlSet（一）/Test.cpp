#include<iostream>
#include<set>
using namespace std;

void TestSet(){
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(7);
	// 排序+去重
	set<int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 拷贝（深拷贝树形结构）
	set<int> copy(s);
	for (const auto& e : s){
		cout << e << " ";
	}
	cout << endl;

	// 查找删除迭代器
	// O(logN)
	set<int>::iterator pos = s.find(3);
	// 若找到则删除
	// 若没找到返回end位置进行删除非法所以必须加以判断
	if (pos != s.end()){
		s.erase(pos);
	}
	for (const auto& e : s){
		cout << e << " ";
	}
	cout << endl;

	// 查找删除值
	s.erase(4);
	for (const auto& e : s){
		cout << e << " ";
	}
	cout << endl;
}

int main(){
	TestSet();
	return 0;
}