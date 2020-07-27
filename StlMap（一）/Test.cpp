#include<iostream>
#include<map>
#include<string>
using namespace std;

void TestMap(){
	map<int,int> m;
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(2, 2));
	m.insert(make_pair(4, 4));

	map<int, int>::iterator it = m.begin();
	while (it != m.end()){
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& e : m){
		cout << e.first << ":" << e.second << endl;
	}
}

void Count(){
	string strArray[] = { "西瓜", "苹果", "西瓜", "樱桃", "西瓜", "苹果" };
	map<string, int> countMap;
	for (auto& str : strArray){
		pair<map<string, int>::iterator,bool> ret = countMap.insert(make_pair(str, 1));
		if (ret.second == false){
			// 插入失败
			// 返回结点所在迭代器
			ret.first->second++;
		}
	}
	for (auto& e : countMap){
		cout << e.first << ":" << e.second << endl;
	}
}

void TestCount(){
	string strArray[] = { "西瓜", "苹果", "西瓜", "樱桃", "西瓜", "苹果" };
	map<string, int> countMap;
	for (auto& str : strArray){
		countMap[str]++;
	}
	for (auto& e : countMap){
		cout << e.first << ":" << e.second << endl;
	}
}

int main(){
	//TestMap();
	//TestCount();
	Count();
	return 0;
} 