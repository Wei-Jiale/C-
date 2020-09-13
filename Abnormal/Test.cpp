#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	try{
		vector<int> v = { 1, 2, 3, 4, 5, 6 };
		for (int cur = 0; cur <= v.size(); cur++){
			cout << v.at(cur) << " ";
		}
		cout << endl;
	}
	catch (exception& e){
		cout << e.what() << endl;
	}
	return 0;
}

// 要求可以抛出自己定义的异常，但是必须继承这个基类。
// 这样的话，外层捕获就只需要捕获基类就可以
class Exception{
protected:
	int _errid; // 错误码
	string _errmsg; // 错误描述
};

class SqlException :public Exception{
	// 数据库错误处理
};

class NetException :public Exception{
	// 网络错误处理
};

int main()
{
	try{
		// server.Start();
		// 抛出对象都是派生类对象
	}
	catch (const Exception& e){
		// 这里捕获父类对象就可以
	}
	catch (...){
		cout << "Unkown Exception" << endl;
	}

	return 0;
}