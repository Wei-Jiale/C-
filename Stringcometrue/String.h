#include<assert.h>
// 避免命名冲突，自定义命名空间。
namespace WJL{
	class string{
	public:
		// 迭代器
		typedef char* iterator;

		iterator begin(){
			return _str;
		}

		iterator end(){
			return _str + _size;
		}

		// 1.构造函数
		string(const char* str = ""){
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		 // 2.析构函数
		~string(){
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// 3.size
		size_t size() const{
			return _size;
		}

		// 4.capacity
		size_t capacity() const{
			return _capacity;
		}

		// 5.operator[]
		char& operator[](size_t i){
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i) const{
			assert(i < _size);
			return _str[i];
		}

		// 6.c_str
		const char* c_str(){
			return _str;
		}

		// 扩容
		void reserve(size_t n){
			if (n > _capacity){
				char* newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}

		// 改变有效字符串个数
		void resize(size_t n, char ch = '\0'){
			if (n < _size){
				_str[n] = '\0';
				_size = n;
			}
			else{
				if (n>_capacity){
					reserve(n);
				}
				for (size_t i = _size; i < n; ++i){
					_str[i] = ch;
				}

				_size = n;
				_str[_size] = '\0';
			}
		}

		// 7.push back
		void push_back(char ch){
			//  检查容量
			if (_size == _capacity){
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				/*char* newstr = new char[newcapacity + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = newcapacity;*/
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			// 插入字符会覆盖‘\0’
			_str[_size] = '\0';
		}

		// 8.append
		void append(const char* str){
			size_t len = strlen(str);
			if (_size + len > _capacity){
				size_t newcapacity = _size + len;
				/*char* newstr = new char[newcapacity + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = newcapacity;*/
				reserve(newcapacity);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		// 9.operator+=
		string& operator+=(char ch){
			this->push_back(ch);
			return *this;
		}

		string& operator+=(char* str){
			this->append(str);
			return *this;
		}

		// 10.insert
		string& insert(int pos, char ch){
			assert(pos < _size);
			if (_size == _capacity){
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}

			// 定义挪动的位置
			int end = _size;
			while (end >= pos){
				// 向后挪数据
				_str[end + 1] = _str[end];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(int pos, const char* str){
			assert(pos < _size);

			// 空间不够先进行增容
			size_t len = strlen(str);
			if (_size + len > _capacity){
				reserve(_size + len);
			}

			// 挪动数据
			int end = _size;
			while (end >= pos){
				_str[end + len] = _str[end];
				--end;
			}

			/*for (size_t i = 0; i < len; ++i)
			{
			_str[pos++] = str[i++];
			}*/
			strncpy(_str + pos, str, len);

			_size += len;

			return *this;
		}

		// 11.erase
		string& erase(size_t pos, size_t len = npos){
			assert(pos < _size);
			// _size-pos：pos到结尾的字符个数
			// 全部删完
			if (len >= _size - pos){
				_str[pos] = '\0';
				_size = pos;
			}
			// 需要挪动数据覆盖被删除的字符
			else{
				// 从i开始向前挪动数据
				size_t i = pos + len;
				while (i <= _size){
					_str[i - len] = _str[i];
					++i;
				}

				_size -= len;
			}

			return *this;
		}

		// 12.find
		size_t find(char ch, size_t pos = 0){
			for (size_t i = pos; i < _size; ++i){
				if (_str[i] == ch){
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0){
			char* p = strstr(_str, str);
			if (p == nullptr){
				return npos;
			}
			else{
				return p - _str;
			}
		}

		// 13.比大小
		bool operator<(const string& s){
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}

		bool operator==(const string& s){
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}

		bool operator<=(const string& s){
			return *this < s || *this == s;
		}

		bool operator>(const string& s){
			return !(*this <= s);
		}

		bool operator>=(const string& s){
			return !(*this < s);
		}

		bool operator!=(const string& s){
			return !(*this == s);
		}


	private:
		// string是管理字符的数组，底层是一个指向数组的指针
		char* _str;
		// 支持扩容
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	size_t string::npos = -1;

	// getline就是没有“ ”
	istream& operator>>(istream& in, string& s){
		while (1){
			char ch;
			ch = in.get();
			if (ch == ' ' || ch == '\n'){
				break;
			}
			else{
				s += ch;
			}
		}

		return in;
	}

	ostream& operator<<(ostream& out, const string& s){
		for (size_t i = 0; i < s.size(); ++i){
			out << s[i];
		}
		return out;
	}

	void test_string1(){
		string s1;
		string s2("hello");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		// 三种遍历方式
		for (size_t i = 0; i < s2.size(); ++i){
			s2[i] += 1;
			cout << s2[i] << " ";
		}
		cout << endl;

		// 迭代器
		string::iterator it = s2.begin();
		while (it != s2.end()){
			*it -= 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		s2.push_back('w');
		s2.push_back('o');
		s2.push_back('r');
		s2.push_back('l');
		s2.push_back('d');

		s2.append("hello");

		// 范围for是由迭代器支持的
		for (auto e : s2){
			cout << e << " ";
		}
		cout << endl;


		s1 += 'w';
		s1 += "orld";
		s1.insert(0, 'x');
		s1.insert(0, "zzz");
		s1.erase(0, 1);

		for (auto e : s1){
			cout << e << " ";
		}
		cout << endl;

		cout << s1.find('z') << endl;
		cout << s1.find("world") << endl;

		string s3;
		cin >> s3;
		cout << s3;
	}
}