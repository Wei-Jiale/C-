#include<vector>
namespace WJL{
	// �º�������������
	template<class T>
	// class����Ա���ֹ��� ����˽��
	// struct����Աȫ������
	struct less{
		bool operator()(const T& x1, const T& x2){
			return x1 < x2;
		}
	};

	template<class T>
	struct greater{
		bool operator()(const T& x1, const T& x2){
			return x1 > x2;
		}
	};

	// Ĭ�ϴ��
	template<class T,class Container = vector<T>,class Compare = less<T>>
	class priority_queue{
	public:
		// ���ϵ����㷨
		void AdjustUp(int child){
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0){
				// child > parent
				if (com(_con[parent], _con[child])){
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else{
					break;
				}
			}
		}
		void push(const T& x){
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		//���µ����㷨
		void AdjustDown(int root){
			Compare com;
			size_t parent = root;
			size_t child = parent * 2 + 1;
			while (child < _con.size()){
				// ѡ�����Һ����нϴ��
				if (child+1 < _con.size()&&com(_con[child],_con[child + 1])){
					child++;
				}
				// child > parent
				if (com(_con[parent], _con[child])){
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else{
					break;
				}
			}
		}

		void pop(){
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		T& top(){
			return _con[0];
		}

		size_t size(){
			return _con.size();
		}

		bool empty(){
			return _con.empty();
		}
	private:
		Container _con;
	};

	void test_priority(){
		//priority_queue<int> pq;
		priority_queue<int,vector<int>,greater<int>> pq;

		pq.push(3);
		pq.push(1);
		pq.push(9);
		pq.push(4);
		pq.push(2);
		while (!pq.empty()){
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}