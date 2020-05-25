#include<assert.h>
namespace WJL{
	// 1.List�Ľ����
	template<class T>
	struct _List_node{
		_List_node<T>* _next;
		_List_node<T>* _prev;
		T _data;

		_List_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	// 2.List��ĵ�����
	template<class T, class Ref, class Ptr>
	struct _List_iterator{
		typedef _List_node<T> Node;
		typedef _List_iterator<T, Ref, Ptr> Self;
		Node* _node;

		_List_iterator(Node* node)
			:_node(node)
		{}

		// ������
		Ref operator*(){
			return _node->_data;
		}

		// operator++(++it)
		Self& operator++(){
			_node = _node->_next;
			return *this;
		}

		// operator++(it++)
		Self operator++(int){
			Self tmp(*this);
			//_node = _node->_next;
			++(*this);

			return tmp;
		}

		// operator--(--it)
		Self& operator--(){
			_node = _node->_prev;
			return *this;
		}

		// operator--(it--)
		Self operator--(int){
			Self tmp(*this);
			//_node = _node->_prev;
			--(*this);

			return tmp;
		}

		// !=
		bool operator!=(const Self& it){
			return _node != it._node;
		}

		// ==
		bool operator==(const Self& it){
			return _node == it._node;
		}

		 // ->
		Ptr operator->(){
			return &_node->_data;
		}
	};

	// 3.List��
	template<class T>
	class List{
		typedef _List_node<T> Node;
	public:
		typedef _List_iterator<T, T&, T*> iterator;
		typedef _List_iterator<T, const T&, const T*> const_iterator;

		iterator begin(){
			return iterator(_head->_next);
		}

		iterator end(){
			return iterator(_head);
		}

		// ����ֵ��const�������������޸ģ�
		const_iterator begin()const{
			return const_iterator(_head->_next);
		}

		const_iterator end()const{
			return const_iterator(_head);
		}

		// ��ͷ˫��ѭ������
		List(){
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		// ���
		List(const List<T>& lt){
			// ͷ���
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			/*const_iterator it = lt.begin();
			while (it != lt.end()){
				push_back(*it);
				++it;
			}*/
			for (const auto& e : lt){
				push_back(e);
			}
		}

		/*List<T>& operator=(const List<T>& lt){
			if (this != &lt){
				clear();
				for (const auto& e : lt){
					push_back(e);
				}
			}

			return *this;
		}*/

		// operator�ִ�д��
		List<T>& operator=(List<T> lt){
			// lt�Ǵ�ֵ�������������
			swap(_head, lt._head);
			// ����֮�� lt�����������ͷŵ�����ֵ�Ŀռ�
			return *this;
		}

		~List(){
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear(){
			iterator it = begin();
			while (it != end()){
				erase(it++);
			}
		}

		// β��
		void push_back(const T& x){
			//Node* newnode = new Node(x);
			//Node* tail = _head->_prev; // ԭlist�е����һ�����

			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;
			insert(end(), x);
		}

		// ͷ��
		void push_front(const T& x){
			insert(begin(), x);
		}

		// βɾ
		void pop_back(){
			//erase(iterator(_head->_prev));
			erase(--end());
		}

		// ͷɾ
		void pop_front(){
			erase(begin());
		}

		// posλ�ò���
		void insert(iterator pos, const T& x){
			// ȡ��posλ�ý���ָ��
			Node* cur = pos._node;
			Node* newnode = new Node(x);
			Node* prev = cur->_prev;
			// prev cur newnode
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		// posλ��ɾ��
		void erase(iterator pos){
			// ͷ��㲻��ɾ
			assert(pos != end());
			// ȡ��posλ�ý���ָ��
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			delete cur;
			prev->_next = next;
			next->_prev = prev;
		}

	private:
		Node* _head;

	};

	void test_list1(){
		List<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		for (const auto& e : lt){
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();

		List<int> lt2(lt);

		List<int>::iterator it = lt2.begin();
		while (it != lt2.end()){
			cout << *it << " ";
			++it;
		}
		cout << endl;

		List<int> lt3;
		lt3 = lt;
		for (const auto& e : lt3){
			cout << e << " ";
		}
		cout << endl;
	}
}