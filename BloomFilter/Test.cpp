#include<iostream>
#include<vector>
#include<string>

class bitmap{
public:
	bitmap(size_t N){
		_bits.resize(N / 32 + 1, 0); // �࿪һ������32bit
		_num = 0;
	}

	// ���
	void set(size_t x){
		// Ѱ��x�ı�Ǵ���ڵڼ�������
		size_t index = x / 32;
		// Ѱ��x�ı����������͵ĵڼ���λ
		size_t pos = x % 32;

		//���������λ�ƶ�
		_bits[index] |= (1 << pos);
	}

	void reset(size_t x){
		// Ѱ��x�ı�Ǵ���ڵڼ�������
		size_t index = x / 32;
		// Ѱ��x�ı����������͵ĵڼ���λ
		size_t pos = x % 32;

		// ��pos��λ����Ϊ0
		_bits[index] &= ~(1 << pos);
	}

	// �ж�x��ӳ��λ�Ƿ�Ϊ1
	bool test(size_t x){
		// Ѱ��x�ı�Ǵ���ڵڼ�������
		size_t index = x / 32;
		// Ѱ��x�ı����������͵ĵڼ���λ
		size_t pos = x % 32;

		return _bits[index] & (1 << pos);
	}

private:
	std::vector<int> _bits;
	size_t _num; // �洢�����ݸ���
};

// ��¡������
struct HashStr1{
	// BKDR��ϣ�㷨
	size_t operator()(const std::string& str){
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); ++i){
			hash *= 131;
			hash += str[i];
		}
		return hash;
	}
};

struct HashStr2{
	// RS��ϣ�㷨
	size_t operator()(const std::string& str){
		size_t hash = 0;
		size_t magic = 63689;
		for (size_t i = 0; i < str.size(); ++i){
			hash *= magic;
			hash += str[i];
			magic *= 378551;
		}
		return hash;
	}
};

struct HashStr3{
	// SDBM��ϣ�㷨
	size_t operator()(const std::string& str){
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); ++i){
			hash *= 65599;
			hash += str[i];
		}
		return hash;
	}
};

template<class K = std::string, class Hash1 = HashStr1, class Hash2 = HashStr2, class Hash3 = HashStr3>
class bloomfilter{
public:
	bloomfilter(size_t num){
		_bs(-1);
	}
	void set(const K& key){
		// ͨ�������ϣ����������ӳ�䵽λͼ��
		size_t index1 = Hash1()(key);
		size_t index2 = Hash2()(key);
		size_t index3 = Hash3()(key);

		_bs.set(index1);
		_bs.set(index2);
		_bs.set(index3);
	}

	// ������ɾ������
	void reset(const K& key){
		// ��֧��ɾ��
	}

	bool test(const K& key){
		// �ж����ǲ�׼ȷ�ģ����ܴ������У��жϲ�����׼ȷ�ġ�
		size_t index1 = Hash1()(key);
		if (_bs.test(index1) == false)
			return false;
		size_t index2 = Hash2()(key);
		if (_bs.test(index2) == false)
			return false;
		size_t index3 = Hash3()(key);
		if (_bs.test(index3) == false)
			return false;

		return true;
	}
private:
	// �ײ���ʵ��һ��λͼ
	bitmap _bs;
	size_t len;
};