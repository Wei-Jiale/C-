#pragma warning(disable : 4996)
// 避免命名冲突，自定义命名空间。
namespace WJL{
	class string{
	public:
		//// 1.构造函数无参
		//string()
		//	// 解决空指针问题
		//	:_str(new char[1])
		//{
		//	_str[0] = '\0';
		//}

		// 2.构造函数带参
		string(char* str = "")
			:_str(new char[strlen(str)+1])
		{
			// _str指向的空间在堆上（可进行灵活操作:修改、扩容）
			strcpy(_str, str);
		}

		// 3.析构函数
		~string(){
			delete[] _str;
			_str = nullptr;
		}

		// 4.拷贝构造（解决浅拷贝：同一空间释放两次） string s2(s1);
		string(const string& s)
			// 深拷贝：拷贝空间
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		// 5.赋值（解决浅拷贝）s1 = s3;
		string& operator=(const string& s){
			// 防止自己给自己赋值
			if (this != &s){
				// 开辟和s3相同大小的临时空间
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				// 释放s1的空间
				delete[] _str;
				// s1指向新空间
				_str = temp;
			}

			return *this;
		}

	private:
		// string是管理字符的数组，底层是一个指向数组的指针
		char* _str;
	};

	void test_string1(){
		// 构造函数和析构函数
		string s1;
		string s2("hello");
	}

	void test_string2(){
		// 拷贝构造
		string s1("hello");
		string s2(s1);

		// 赋值
		string s3("world");
		s1 = s3;
	}
}