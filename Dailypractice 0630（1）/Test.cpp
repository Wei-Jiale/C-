// 小猫是否能进到碗里
// n：猫的长度
// r：碗的半径
#include<iostream>
using namespace std;
int main(){
	double n, r;
	while (cin >> n >> r){
		if (n > (2 * r * 3.14)){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
	}
	return 0;
}