#include<iostream>
#include<vector>
using namespace std;

void Test_iterator1(){
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);

	vector<int>::iterator it = array.begin();

	array.push_back(6);
	// 1.增容可能导致迭代器失效（push_back,insert,resize,reserve）
	// array.push_back(7); 
	// 插入7则产生迭代器失效问题
	// vector空间不够则增容，开辟新的空间，将数据拷贝到新空间再释放旧空间
	// 这时it是指向旧空间已经被释放，从而导致it失效
	// 不要在迭代器定义之后进行可能增容的操作

	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void Test_iterator2(){
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);

	// 2.it的意义改变导致迭代器失效
	// 要求删除容器中的所有偶数
	// 删除2：将3、4、5、6向前挪一位，此时it指向3，++it后3没有被判断，导致迭代器失效
	// vs下进行检查会报错  gcc下不会检查导致结果出问题
	/*vector<int>::iterator it = array.begin();
	while (it != array.end()){
		if (*it % 2 == 0){
			array.erase(it);
		}
		
		++it;
	}*/

	// 解决
	// erase返回删除it的下一个位置的迭代器
	vector<int>::iterator it = array.begin();
	while (it != array.end()){
		if (*it % 2 == 0){
			it = array.erase(it);
		}
		else{
			++it;
		}
	}

	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}

int main(){
	Test_iterator1();
	Test_iterator2();
}