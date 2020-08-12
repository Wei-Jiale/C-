#pragma once

template<class K>
struct SetKeyOfT{
	const K& operator()(const K& key){
		return key;
	}
};

enum State{
	EMPTY,
	EXITS,
	DELETE,
};

template<class T>
struct HashData{
	HashData(const T& data = T(), const State& state = EMPTY)
		: _data(data)
		, _state(state)
	{}

	T _data;
	State _state;
};

// unordered_set<K> -> HashTable<K, K>
// unordered_map<K, V> -> HashTable<K, pair<K, V>>
template<class K,class T, class KeyOfT>
class HashTable{
public:
	typedef HashData<T> HashData;
	bool Insert(const T& val){
		// �������� = ������� / ��Ĵ�С���ռ任ʱ�䣩
		// ������ϣ�����ĳ̶�
		// ��ϣ���������˲�����
		// ��ϣ��Խ�ӽ�������ͻ�ĸ��ʾ�Խ��Ч�ʾ�Խ��
		// ��������ԽС����ͻ����ԽС��Ч����ߵ�ͬʱ�������ſռ���˷ѡ�
		if (_tables.size() == 0 || _num*10 / _tables.size() >= 7){
			// ���ݣ�ֱ�ӽ�ԭ�����ݿ�����������ɱ��������󣬶�ԭ�е�ӳ���ϵ�����ı�����⣩
			// 1. ��һ�������Ŀռ�
			HashTable<K,T,KeyOfT> newHT;
			size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			newHT._tables.resize(newsize);
			for (size_t i = 0; i < _tables.size(); i++){
				if (_tables[i]._state == EXITS){
					newHT.Insert(_tables[i]._data);
				}
			}

			_tables.swap(newHT._tables);
			// 2. ���ɱ����������ӳ�䵽�±�
			// 3. �ͷžɱ�Ŀռ�

		}

		KeyOfT koft;
		// ����val�е�key�ڱ���ӳ���λ��
		size_t index = koft(val) % _tables.size();
		while (_tables[index]._state == EXITS){
			if (koft(_tables[index].data) == koft(val)){
				return false;
			}
			++index;
			if (index == _tables.size()){
				index = 0;
			}
		}
		_tables[index]._data = val;
		_tables[index]._state = EXITS;
		_num++;
	}

	HashData* Find(const K& key){
		KeyOfT koft;
		// ����val�е�key�ڱ���ӳ���λ��
		size_t index = key % _tables.size();
		while (_tables[index]._state != EMPTY){
			if (koft(_tables[index]._data) == key){
				if (_tables[index]._state == EXITS){
					return &_tables[index];
				}
				else if (_tables[index]._state == DELETE){
					return nullptr;
				}
			}
			++index;
			if (index == _tables.size()){
				index = 0;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key){
		HashData* ret = Find(key);
		if (ret){
			ret->_state == DELETE;
			--_num;
			return true;
		}
		else{
			return false;
		}
	}
private:
	vector<HashData> _tables;
	size_t _num = 0; // �洢��Ч���ݵĸ���
};