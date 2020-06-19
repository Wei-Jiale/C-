// 第一行输入一个数n，1 <= n <= 1000，下面输入n行数据，每一行有两个数，分别是x y。
// 输出一组x y，该组数据是所有数据中x最小，且在x相等的情况下y最小的。 
#include<iostream>
using namespace std;

int main(){
	int n, a, b, tempa = 0x7fffffff, tempb = 0x7fffffff;
	cin >> n;
	while (n--){
		cin >> a >> b;
		// 先比较整数a 若a<tempa 则不用比较b 直接使tempb = b;
		if (a < tempa){
			tempa = a;
			tempb = b;
		}
		// 若a = tempa 则 比较b与tempb
		else if (a == tempa && b < tempb){
			tempb = b;
		}
	}
	cout << tempa << " " << tempb << endl;
	return 0;
}