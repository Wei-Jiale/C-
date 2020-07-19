// Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。
// 为了提高性能，架构师决定复用已经创建的连接。
// 当收到请求，并且连接池中没有剩余可用的连接时，系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。
// 现在提供你处理请求的日志，请你分析一下连接池最多需要创建多少个连接。
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main(){
	// 请求的数量
	int n;
	while (cin >> n){
		set<string> pool;
		string id, con;
		int maxSize = 0;
		for (int i = 0; i < n; ++i){
			cin >> id >> con;
			if (con == "connect"){
				pool.insert(id);
			}
			else if (con == "disconnect"){
				pool.erase(id);
			}
			int size = pool.size();
			maxSize = max(maxSize, size);
		}
		cout << maxSize << endl;
	}
	return 0;
}