#include<iostream>
#include<vector>
using namespace std;

int main(){
	// �޲ι���
	vector<int> array1;

	// ���첢��ʼ��n��val
	vector<int> array2(4, 100);

	// ��������
	vector<int> array3(array2);

	// ʹ�õ��������г�ʼ������
	vector<int> array4(array2.begin(), array2.end());

	// ��������ʼ��
	int array[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> array5(array, array + sizeof(array) / sizeof(array[0]));
	for (vector<int>::iterator it = array5.begin(); it != array5.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}