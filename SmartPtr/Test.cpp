#include<iostream>
using namespace std;

namespace WJL{
	template<class T>
	class auto_ptr{
		// �����ǹ�����Դ���ͷ�
	public:
		// ���캯��������Դ
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		// ���������ͷ���Դ
		~auto_ptr(){
			if (_ptr){
				cout << "delete��" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		// ����Ȩת��
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ��ֵ s1 = s2
		auto_ptr<T>& operator=(const auto_ptr<T>& ap){
			if (this != &ap){
				auto_ptr<T> PtrTemp(ap);

				T* pTemp = PtrTemp._ptr;
				PtrTemp._ptr = _ptr;
				_ptr = pTemp;
			}

			return *this;
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

	private:
		T* _ptr;
	};


	// ���������򵥴ֱ���
	template<class T>
	class unique_ptr{
		// �����ǹ�����Դ���ͷ�
	public:
		// ���캯��������Դ
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator = (unique_ptr<T>& up) = delete;

		// ���������ͷ���Դ
		~unique_ptr(){
			if (_ptr){
				cout << "delete��" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

	private:
		T* _ptr;
	};


	// ֧�ֿ���������ָ�룬shared_ptr��
	template<class T>
	class shared_ptr{
		// �����ǹ�����Դ���ͷ�
	public:
		// ���캯��������Դ
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, p_count(new int(1))
		{}

		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, p_count(sp.p_count)
		{
			++(*p_count);
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp){
			if (this != &sp){
				if (--(*p_count) == 0){
					delete _ptr;
					delete p_count;
				}

				_ptr = sp._ptr;
				p_count = sp.p_count;
				++(*p_count);
			}
			return *this;
		}

		// ���������ͷ���Դ
		~shared_ptr(){
			if (--(*p_count) == 0 && _ptr){
				cout << "delete��" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;

				delete p_count;
				p_count = nullptr;
			}
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

	private:
		T* _ptr;
		int* p_count; // ���ü�������¼�ж��ٸ�����һ���������Դ��
	};
}

int main(){
	WJL::auto_ptr<int> ap1(new int);
	WJL::auto_ptr<int> ap2 = ap1;

	WJL::unique_ptr<int> up1(new int);
	// WJL::unique_ptr<int> up2 = up1;

	WJL::shared_ptr<int> sp1(new int);
	WJL::shared_ptr<int> sp2 = sp1;

	return 0;
}