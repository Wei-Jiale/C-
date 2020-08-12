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
		// 负载因子 = 表的数据 / 表的大小（空间换时间）
		// 衡量哈希表满的程度
		// 哈希表并不是满了才增容
		// 哈希表越接近满，冲突的概率就越大，效率就越低
		// 负载因子越小，冲突概率越小，效率提高的同时，伴随着空间的浪费。
		if (_tables.size() == 0 || _num*10 / _tables.size() >= 7){
			// 增容（直接将原表数据拷贝下来会造成表容量增大，而原有的映射关系发生改变的问题）
			// 1. 开一个二倍的空间
			HashTable<K,T,KeyOfT> newHT;
			size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			newHT._tables.resize(newsize);
			for (size_t i = 0; i < _tables.size(); i++){
				if (_tables[i]._state == EXITS){
					newHT.Insert(_tables[i]._data);
				}
			}

			_tables.swap(newHT._tables);
			// 2. 将旧表的数据重新映射到新表
			// 3. 释放旧表的空间

		}

		KeyOfT koft;
		// 计算val中的key在表中映射的位置
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
		// 计算val中的key在表中映射的位置
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
	size_t _num = 0; // 存储有效数据的个数
};