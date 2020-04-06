//引用
//引用：给已经存在的变量取了一个别名，和这个变量共用同一块内存空间
#include<iostream>
using namespace std;

// 1.引用
int mian(){
	int a = 10;
	int& b = a;//b是a的别名

	//权限可以缩小但不能放大
	int c = 20;
	const int& d = c;

	//const int e = 30;
	//int& f = e; 权限放大错误

	return 0;
}

// 2.引用做参数
// 少创建子一个临时变量 提高效率
void Swap_c(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Swap_cpp(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int a = 10;
	int b = 20;
	Swap_c(&a, &b);//传地址（开空间）
	Swap_cpp(a, b);//传引用（不开空间）

	return 0;
}

// 3.引用做返回值
// 注：返回变量的生命周期应该随工程 否则不安全(空间可能被修改）
// 少创建子一个临时变量 提高效率
int Count1(){
	static int n = 0;
	n++;

	return n;//返回临时变量n（开空间）相当于拷贝
}

int& Count2(){
	static int n = 0;
	n++;

	return n;//返回引用（不开空间）相当于自身
}

int main(){

	return 0;
}

//引用的特性：必须初始化/一个变量可以有多个引用/一旦引用一个实体不能再引用其它实体