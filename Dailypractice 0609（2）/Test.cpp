#include<iostream>
using namespace std;

int gac(int a, int b){
	// Õ·×ªÏà³ý
	int r = 0;
	while (r = a%b){
		a = b;
		b = r;
	}
	return b;
}

int main(){
	int a, b;
	while (cin >> a >> b){
		cout << a*b / gac(a, b) << endl;
	}
	return 0;
}