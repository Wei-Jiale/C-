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
	// �Ƚϳ���
	for (size_t i = 1; i < v.size(); i++){
		if (v[i - 1].size() >= v[i].size()){
			lenSym = false;
			break;
		}
	}
	// �Ƚ�ASCII
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