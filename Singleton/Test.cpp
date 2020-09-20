#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;

// ����ģʽ
class Singleton{
public:
	// ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	static Singleton* GetInstance(){
		if (_pinst == nullptr)
		// �ֲ���ͨ�������������ƽ���ʱ����
		{
			// _mtx.lock();
			unique_lock<mutex> lock(_mtx); // (����������ԭ���ԣ�
			if (_pinst == nullptr)
				// ��ֻ��Ҫ������һ�Σ���Ҫ����˫��飩
				_pinst = new Singleton;
			// _mtx.unlock();
		}
		return _pinst;
	}

	Singleton(const Singleton& s) = delete;

	// ʵ��һ����Ƕ����������
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::_pinst)
				delete Singleton::_pinst;
		}
	};

	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;

private:
	// ���캯��˽�л�
	Singleton(){}

	// ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	// ��������ָ��
	static Singleton* _pinst;
	static mutex _mtx;
};

Singleton* Singleton::_pinst = nullptr;
mutex Singleton::_mtx;
Singleton::CGarbo Garbo;


// ����ģʽ
class Singleton2
{
public:
	static Singleton2* GetInstance(){
		return &m_instance;
	}

private:
	// ���캯��˽��
	Singleton2(){};

	Singleton2(Singleton2 const&) = delete;
	Singleton& operator=(Singleton2 const&) = delete;

	// ��������
	static Singleton2 m_instance;
};

Singleton2 Singleton2::m_instance; // �ڳ������֮ǰ����ɵ�������ĳ�ʼ�������ÿ����̰߳�ȫ�����⡣