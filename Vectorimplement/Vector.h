#include<memory.h>
#include<assert.h>

namespace WJL{
	template<class T>
	class Vector{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		// 深拷贝
		/*Vector(const Vector<T>& v){
			_start = new T[v.capacity()];
			_finish = _start;
			_endofstorage = _start + v.capacity();

			for (size_t i = 0; i < v.size(); i++){
				*_finish = v[i];
				_finish++;
			}
		}*/

		Vector(const Vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v){
				push_back(e);
			}
		}

		/*Vector<T>& operator=(const Vector<T>& v){
			if(this != &v){
				delete[] _start;
				_start = new T[v.capacity()];
				memcpy(_start, v._start, sizeof(T)*v.size());
			}
			return *this;
		}*/

		// v1 = v3  现代写法
		Vector<T>& operator=(Vector<T> v){
			swap(v);
			return *this;
		}

		// 自定义类型涉及深拷贝建议自己实现swap（仅指针交换代价小）
		void swap(Vector<T>& v){
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		~Vector(){
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		void reserve(size_t n){
			if (n > capacity()){
				// 开辟新空间
				size_t sz = size();
				T* temp = new T[n];
				if (_start){
					//memcpy(temp, _start, sizeof(T)*sz);
					for (size_t i = 0; i < sz; ++i){
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = temp + sz;
				_endofstorage = temp + n;
			}
		}

		void resize(size_t n, const T& val = T()){
			if (n < size()){
				_finish = _start + n;
			}
			else{
				if (n>capacity()){
					reserve(n);
				}
				while (_finish < _start + n){
					*_finish = val;
					++_finish;
				}
			}
		}

		void push_back(const T& val){
			if (_finish == _endofstorage){
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = val;
			++_finish;
		}

		void pop_back(){
			assert(_start < _finish);
			--_finish;
		}

		void insert(iterator pos, const T& val){
			assert(pos >= _start&&pos <= _finish);
			if (_finish == _endofstorage){
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				// 增容原来的pos会失效
				pos = _start + n;
			}
			// 定义开始挪动的位置
			iterator end = _finish - 1;
			while (pos <= end){
				*(end + 1) = *end;
				--end;
			}

			*pos = val;
			++_finish;
		}

		iterator erase(iterator pos){
			assert(pos < _finish);
			iterator it = pos;
			while (it < _finish){
				*it = *(it + 1);
				++it;
			}
			--_finish;

			// 返回当前位置的下一个位置
			return pos;
		}

		T& operator[](size_t i){
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i)const{
			assert(i < size());
			return _start[i];
		}

		size_t size() const{
			return _finish - _start;
		}

		size_t capacity() const{
			return _endofstorage - _start;
		}

		iterator begin(){
			return _start;
		}

		iterator end(){
			return _finish;
		}

		const_iterator begin()const{
			return _start;
		}

		const_iterator end()const{
			return _finish;
		}

	private:
		iterator _start; // 开始位置
		iterator _finish; // 最后一个位置的下一个位置
		iterator _endofstorage; // 相当于capacity
	};

	void test_vector1(){
		Vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.pop_back();

		v.insert(v.begin(), 0);

		v.erase(v.begin());

		v.resize(10);

		Vector<int>::iterator it = v.begin();
		while (it != v.end()){
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (const auto& e : v){
			cout << e << " ";
		}
		cout << endl;

		for (size_t cur = 0; cur < v.size(); cur++){
			cout << v[cur] << " ";
		}
		cout << endl;
	}

	void test_vector2(){
		Vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		Vector<int> v2(v1);

		for (size_t cur = 0; cur < v2.size(); cur++){
			cout << v2[cur] << " ";
		}
		cout << endl;

		Vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);
		v3.push_back(30);
		v3.push_back(40);
		v3.push_back(50);

		v1 = v3;
		for (size_t cur = 0; cur < v1.size(); cur++){
			cout << v1[cur] << " ";
		}
		cout << endl;

	}
}