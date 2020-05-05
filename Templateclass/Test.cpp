#include<iostream>
using namespace std;

template<class T>
class Vector{
	public：
	Vector(size_t capacity = 10)
	: _pData(new T[capacity])
	, _size(0)
	, _capacity(capacity)
	{}
	// 使用析构函数演示：在类中声明，在类外定义。
	~Vector();
	void PushBack(const T& data)；
		void PopBack()；
		// ...
		size_t Size() { return _size; }
	T& operator[](size_t pos){
		assert(pos < _size);
		return _pData[pos];
	}
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template <class T>
Vector<T>::~Vector(){
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}

int main(){
	// Vector类名，Vector<int>才是类型
	Vector<int> v1;
	Vector<double> v2;
	return 0;
}