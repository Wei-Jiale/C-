#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto& str : v){
		cin >> str;
	}

	bool lenSym = true;
	bool lexSym = true;
	// 比较长度
	for (size_t i = 1; i < v.size(); i++){
		if (v[i - 1].size() >= v[i].size()){
			lenSym = false;
			break;
		}
	}
	// 比较ASCII
	for (size_t i = 1; i < v.size(); i++){
		if (v[i - 1] >= v[i]){
			lexSym = false;
			break;
		}
	}

	if (lenSym && lexSym){
		cout << "both" << endl;
	}
	else if (!lenSym && lexSym){
		cout << "lexicographically" << endl;
	}
	else if (lenSym && !lexSym){
		cout << "lengths" << endl;
	}
	else{
		cout << "none" << endl;
	}
	return 0;
}