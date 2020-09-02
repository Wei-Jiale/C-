#include<vector>
#include<string>

namespace lee
{
	template<class K>
	struct _Hash
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

	template<>
	struct _Hash<std::string>
	{
		const size_t & operator()(const std::string& key)
		{
			//BKDR�ַ�����ϣ����
			size_t hash = 0;

			for (size_t i = 0; i < key.size(); i++)
			{
				hash *= 131;
				hash += key[i];
			}

			return hash;
		}
	};

	template<class K>
	struct SetKeyOfT
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

	template<class T>
	struct HashNode
	{

		HashNode(const T& data = T())
		: _data(data)
		, _next(nullptr)
		{}

		T _data;
		HashNode<T>* _next;
	};

	template<class K, class T, class KeyofT, class Hash>
	class HashBucket;

	template<class K, class T, class KeyOfT, class Hash>
	struct __HashTableIterator
	{
		typedef HashNode<T> Node;
		typedef HashBucket<K, T, KeyOfT, Hash> HB;
		typedef __HashTableIterator<K, T, KeyOfT, Hash> Self;

		__HashTableIterator(Node* node, HB* hb)
			: _node(node)
			, _phb(hb)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			//�����һ���ڵ㲻Ϊ�գ�ֱ�ӷ�����һ��
			if (_node->_next)
			{
				_node = _node->_next;
			}
			//�����һ��Ϊ�գ����ߵ���һ������
			else
			{
				//ͨ����ȡ��ǰ���ݵ�key���ж���һ�����ݵ�λ��
				KeyOfT koft;
				size_t pos = _phb->HashFunc(koft(_node->_data));
				++pos;

				for (; pos < _phb->_table.size(); pos++)
				{
					Node* cur = _phb->_table[pos];
					//�����һ��Ͱ�����ݲ�Ϊ�գ��򷵻�Ͱ�ĵ�һ���ڵ�
					if (cur != nullptr)
					{
						_node = cur;
						return *this;
					}

				}
				//ʣ�µ�Ͱ��û������
				_node = nullptr;
			}
			return *this;
		}

		Self operator++(int)
		{
			Self temp = *this;

			++this;

			return temp;
		}

		bool operator != (const Self& s)
		{
			return _node != s._node;
		}

		bool operator == (const Self& s)
		{
			return _node == s._node;
		}

		Node* _node;
		HB* _phb;
	};

	template<class K, class T, class KeyofT = SetKeyOfT<T>, class Hash = _Hash<K>>
	class HashBucket
	{
	public:
		typedef __HashTableIterator<K, T, KeyofT, Hash> iterator;
		typedef HashNode<T> Node;
		friend struct iterator;


		HashBucket(size_t capacity = 10)
			: _table(capacity)
			, _size(0)
		{}

		~HashBucket()
		{
			Clear();
		}

		iterator begin()
		{
			//�ҵ���һ���ڵ�
			for (size_t i = 0; i < _table.size(); i++)
			{
				//����ڵ㲻Ϊ���򷵻�
				if (_table[i])
				{
					return iterator(_table[i], this);
				}
			}

			return iterator(nullptr, this);
		}

		//��Ϊ��STL�й�ϣͰ�ĵײ��ǵ�����Ľṹ�����Բ�֧��--������end��ֱ�Ӹ�һ���ռ���
		iterator end()
		{
			return iterator(nullptr, this);
		}

		size_t getNextPrime(size_t num)
		{
			size_t i = 0;

			for (i = 0; i < PRIMECOUNT; i++)
			{
				//���ر��Ǹ��������һ������ 
				if (primeList[i] > num)
				{
					return primeList[i];
				}
			}

			//��������ж��󣬻��Ƿ������һ������Ϊ���һ���Ѿ���32λ�������
			return primeList[PRIMECOUNT - 1];
		}

		size_t HashFunc(const K& key)
		{
			Hash hash;

			return hash(key) % _table.size();
		}

		std::pair<iterator, bool> Insert(const T& data)
		{
			KeyofT koft;

			/*
			��Ϊ��ϣͰ�ǿ�ɢ�е���ʽ�ṹ�������˹�ϣ��ͻ��ֱ���ڶ�Ӧλ��λ�ý���ͷ�壬��Ͱ�ĸ����ǹ̶��ģ�����������ݻ᲻�����࣬
			�������ݵ����࣬�Ϳ��ܻᵼ��ĳһ��Ͱ���أ�ʹ��Ч�ʹ��͡�
			��������������������ÿ��Ͱ����һ�����ݡ���������£�������κ�һ���ط����룬���������ϣ��ͻ�����Ե����ݸ�����Ͱ�ĸ�����ͬʱ��Ҳ���Ǹ�������Ϊ1ʱ����Ҫ�������ݡ�
			*/
			if (_size == _table.size())
			{
				//����������������
				size_t newSize = getNextPrime(_table.size());
				size_t oldSize = _table.size();

				std::vector<Node*> newTable(newSize);
				_table.resize(newSize);

				//���Ž���������ӳ���ȥ
				for (size_t i = 0; i < oldSize; i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						//���¼���ӳ���λ��
						size_t pos = HashFunc(koft(cur->_data));

						//�ҵ�λ�ú�ͷ�����Ӧλ��
						Node* next = cur->_next;

						cur->_next = newTable[pos];
						newTable[pos] = cur;

						cur = next;
					}
					//ԭ�����ÿ�
					_table[i] = nullptr;
				}
				//ֱ�Ӻ��±�����������ȥ�ľɱ��ͺ���ջ֡һ�����١�
				_table.swap(newTable);
			}

			size_t pos = HashFunc(koft(data));
			Node* cur = _table[pos];

			//��Ϊ��ϣͰkeyֵΨһ������Ѿ���Ͱ���򷵻�false
			while (cur)
			{

				if (koft(cur->_data) == koft(data))
				{
					return std::make_pair(iterator(cur, this), false);
				}
				else
				{
					cur = cur->_next;
				}
			}

			//�����ɣ���ʱ��ʼ���룬����ѡ�����ͷ�壬�����Ϳ��Լ������ݱ����Ĵ�����
			Node* newNode = new Node(data);

			newNode->_next = _table[pos];
			_table[pos] = newNode;

			++_size;

			return std::make_pair(iterator(newNode, this), true);
		}

		iterator Erase(const K& key)
		{
			KeyofT koft;

			size_t pos = HashFunc(key);
			Node* cur = _table[pos];
			Node* prev = nullptr;

			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					iterator ret(cur, this);
					++ret;

					//���Ҫɾ�����ǵ�һ���ڵ㣬������һ���ڵ��Ϊ�µ�ͷ�ڵ㣬����ֱ��ɾ����
					if (prev == nullptr)
					{
						_table[pos] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_size;

					return ret;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return end();
		}

		iterator Find(const K& key)
		{
			KeyofT koft;

			size_t pos = HashFunc(key);
			Node* cur = _table[pos];

			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					return iterator(cur, this);
				}
				else
				{
					cur = cur->_next;
				}
			}

			return end();
		}

		void Clear()
		{
			//ɾ�����нڵ�
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];

				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				_table[i] = nullptr;
			}
		}

	private:
		std::vector<Node*> _table;
		size_t _size;
	};
};