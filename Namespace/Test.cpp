#include<iostream> //IO流
using namespace std; // C++库的所有东西都放到了std命名空间中（不在乎和库命名冲突展开std）

int main(){
	int num1 = 1;
	double num2 = 2.2;
	cout << "num1=" << num1 << " " << "num2=" << num2 << endl;//cout自动识别变量类型（不需要增加数据格式控制）

	return 0;
}

//C++中的命名空间很好的解决了命名冲突的问题
int main(){
	int cout = 10;
	std::cout << "cout=" << cout << endl;

	return 0;
}

//缺省参数：声明或定义函数时为变量指定的一个默认值
void Func1(int a = 0){ // 形参和缺省参数
	cout << "a=" << a << endl;
}

int main(){
	Func1(10);// 传实参 则缺省参数不给到变量
	Func1();// 不传实参 则缺省参数给到变量

	return 0;
}

//全缺省：缺省全部参数
void Func2(int a = 10, int b = 20, int c = 30){ 
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

}

int main(){
	Func2();
	Func2(1);
	Func2(1, 2);
	Func2(1, 2, 3);

	return 0;
}

//半缺省：缺省部分参数（必须从右往左连续缺省）
void Func3(int a, int b = 20, int c = 30){ //第一个变量没有缺省参数 则必须传实参
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

}

int main(){
	Func3(1);
	Func3(1, 2);
	Func3(1, 2, 3);

	return 0;
}
