#include<iostream>
using namespace std;
// 1.C++中的class和struct
// C语言中结构体内部只能定义成员变量，不能定义函数，在C++ 中结构体中可以定义成员函数
// C++中我们更崇尚于用class来代替struct
// 在struct中的成员默认是公有的(public)，而class中成员默认是私有的(private)
struct AddStruct{
	int num1;
	int num2;

	int AddNum(){
		return num1 + num2;
	}
};

class AddClass{
	int num1;
	int num2;

	int AddNum(){
		return num1 + num2;
	}
};

// 2.类的访问限定符
// public：公有的访问限定符范围内的成员可以被类外部进行访问，我们可以在类外和类内随意使用类中public的成员
// private：私有的访问限定符范围内的成员不能被类外部进行访问，我们只能在类内调用或使用private的成员
// 不能对类内的数据随意修改，保护数据的安全性
class AddClass{
private:
	int _num1;
	int _num2;
public:
	void GetNum1(int num1){
		_num1 = num1;
	}
	void GetNum2(int num2){
		_num2 = num2;
	}
	int AddNum(){
		return _num1 + _num2;
	}
};

// 3.类的作用域
// 域内定义的成员函数会默认作为内联函数对待
// 我们可以通过域限定符来在类外定义函数，这样我们就可以将声明和定义分开，使代码可读性更高
class AddClass{
private:
	int _num1;
	int _num2;
public:
	//默认内联但为了可读性我们还是加上内联的标志
	inline void GetNum1(int num1){
		_num1 = num1;
	}
	inline void GetNum2(int num2){
		_num2 = num2;
	}
	//在类内声明
	int AddNum();
};
//在类外定义
int AddClass::AddNum(){
	return _num1 + _num2;
}

// 4.类的实例化
// 用类来建立我们真正要使用的对象
class AddClass{
private:
	int _num1;
	int _num2;
public:
	//默认内联但为了可读性我们还是加上内联的标志
	inline void GetNum1(int num1){
		_num1 = num1;
	}
	inline void GetNum2(int num2){
		_num2 = num2;
	}
	//在类内声明
	int AddNum();
};
//在类外定义
int AddClass::AddNum(){
	return _num1 + _num2;
}

int main(){
	AddClass add;//类的实例化
	add.GetNum1(1);//成员调用
	add.GetNum2(2);
	cout << add.AddNum() << endl;
}

// 5.this指针
// 函数都存在同一块区域中，那么编译器怎么区分是哪个对象调用了成员函数呢？这就牵扯到了每个类中隐藏的成员this指针
// 这是一个指向类自身的指针。它会默认作为成员函数调用的第一个参数，将调用成员函数的对象地址传入在函数内部找到对象中的成员
class AddClass{
private:
	int _num1;
	int _num2;
public:
	//默认内联但为了可读性我们还是加上内联的标志
	inline void GetNum1(int num1)
	//inline void GetNum1(AddClass* this, int num1)
	{
		_num1 = num1;
	}
	inline void GetNum2(int num2)
	{
		_num2 = num2;
	}
	//在类内声明
	int AddNum();
	//int AddNum(AddClass* this);
};
//在类外定义
int AddClass::AddNum(){
	return _num1 + _num2;
}

int main(){
	AddClass add;
	add.GetNum1(1);
	//add.GetNum1(&add, 1);
	add.GetNum2(2);
	cout << add.AddNum() << endl;
	//AddNum(&add);
}

// 注意：1、this指针不存储在类中，每个编译器对this指针存储的地方都有所不同，在vs中this指针存储在寄存器中
// 注意：2、this指针可以为空，但是一旦调用需要访问对象中成员的函数就会由于this为空发生内存越界而导致崩溃