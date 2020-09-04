// ���⣺����100�ڸ�����������㷨�ҵ�ֻ����һ�ε�����
// ��������λͼ��λͼ1��λͼ2�Ķ�Ӧλ���ṩһ��λ��������ݡ�

#include<iostream>
#include<bitset>
using namespace std;

template<size_t N>
class solution{
public:
	void set(size_t x){
		if (_bs1.test(x) == false && _bs2.test(x) == false){
			// 00 �� 01
			_bs2.set(x);
		}
		else if (_bs1.test(x) == false && _bs2.test(x) == true){
			// 01��10
			_bs1.set(x);
			_bs2.reset(x);
		}
	}
private:
	bitset _bs1;
	bitset _bs2;
};