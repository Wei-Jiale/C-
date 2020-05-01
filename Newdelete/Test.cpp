#include <iostream>                                 
#include <stdlib.h>  
using namespace std;
class Stu{
public:
	Stu(){
		cout << "default building" << endl;
	}

	Stu(int num, string name) :_num(num), _name(name){
		cout << "custom building" << endl;
	}

	~Stu(){
		cout << "destroying" << endl;
	}
private:
	int _num;
	string _name;
};

int main(){
	cout << "malloc:" << endl;
	Stu* a = (Stu*)malloc(sizeof(Stu));
	cout << "new:" << endl;
	Stu* b = new Stu(1, "张三");
	cout << "malloc:" << endl;
	Stu* c = (Stu*)malloc(sizeof(Stu)* 5);
	cout << "new:" << endl;
	Stu* d = new Stu[5];
	cout << "free:" << endl;
	free(a);
	cout << "delete:" << endl;
	delete b;
	cout << "free:" << endl;
	free(c);
	cout << "delete:" << endl;
	delete[] d;
}
// 针对自定义类型的内存分配和释放，new不但可以在分配内存的时候手动调用指定的构造函数还会在分配多个对象的空间时自动调用默认构造函数
// delete也会自动调用析构函数