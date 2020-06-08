#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int main(){
	int m, n;
	cin >> m >> n;
	bool flag = false;
	string s, table = "0123456789ABCDEF";

	// 如果是负数则转正，并标记
	if (m < 0){
		m = 0 - m;
		flag = true;
	}

	while (m){
		s = s + table[m%n];
		m = m / n;
	}

	if (flag){
		s = s + '-';
	}

	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}