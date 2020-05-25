#include<iostream>
#include<list>
using namespace std;

int main(){
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	list<int>::iterator it = lt.begin();
	while (it != lt.end()){
		if (*it % 2 == 0){
			// lt.erase(it)：会造成迭代器失效
			it = lt.erase(it);
		}
		else{
			it++;
		}
	}

	for (const auto& e : lt){
		cout << e << " ";
	}
	cout << endl;
}