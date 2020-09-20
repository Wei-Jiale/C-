#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;

// 懒汉模式
class Singleton{
public:
	// 静态成员函数只能访问静态成员变量
	static Singleton* GetInstance(){
		if (_pinst == nullptr)
		// 局部域（通过作用域来控制解锁时机）
		{
			// _mtx.lock();
			unique_lock<mutex> lock(_mtx); // (保护操作的原子性）
			if (_pinst == nullptr)
				// 锁只需要保护第一次（需要进行双检查）
				_pinst = new Singleton;
			// _mtx.unlock();
		}
		return _pinst;
	}

	Singleton(const Singleton& s) = delete;

	// 实现一个内嵌垃圾回收类
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::_pinst)
				delete Singleton::_pinst;
		}
	};

	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;

private:
	// 构造函数私有化
	Singleton(){}

	// 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	// 单例对象指针
	static Singleton* _pinst;
	static mutex _mtx;
};

Singleton* Singleton::_pinst = nullptr;
mutex Singleton::_mtx;
Singleton::CGarbo Garbo;


// 饿汉模式
class Singleton2
{
public:
	static Singleton2* GetInstance(){
		return &m_instance;
	}

private:
	// 构造函数私有
	Singleton2(){};

	Singleton2(Singleton2 const&) = delete;
	Singleton& operator=(Singleton2 const&) = delete;

	// 单例对象
	static Singleton2 m_instance;
};

Singleton2 Singleton2::m_instance; // 在程序入口之前就完成单例对象的初始化，不用考虑线程安全的问题。