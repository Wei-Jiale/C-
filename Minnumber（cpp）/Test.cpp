// ��һ������һ����n��1 <= n <= 1000����������n�����ݣ�ÿһ�������������ֱ���x y��
// ���һ��x y����������������������x��С������x��ȵ������y��С�ġ� 
#include<iostream>
using namespace std;

int main(){
	int n, a, b, tempa = 0x7fffffff, tempb = 0x7fffffff;
	cin >> n;
	while (n--){
		cin >> a >> b;
		// �ȱȽ�����a ��a<tempa ���ñȽ�b ֱ��ʹtempb = b;
		if (a < tempa){
			tempa = a;
			tempb = b;
		}
		// ��a = tempa �� �Ƚ�b��tempb
		else if (a == tempa && b < tempb){
			tempb = b;
		}
	}
	cout << tempa << " " << tempb << endl;
	return 0;
}