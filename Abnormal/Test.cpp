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

// Ҫ������׳��Լ�������쳣�����Ǳ���̳�������ࡣ
// �����Ļ�����㲶���ֻ��Ҫ�������Ϳ���
class Exception{
protected:
	int _errid; // ������
	string _errmsg; // ��������
};

class SqlException :public Exception{
	// ���ݿ������
};

class NetException :public Exception{
	// ���������
};

int main()
{
	try{
		// server.Start();
		// �׳����������������
	}
	catch (const Exception& e){
		// ���ﲶ�������Ϳ���
	}
	catch (...){
		cout << "Unkown Exception" << endl;
	}

	return 0;
}