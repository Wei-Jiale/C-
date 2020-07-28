#pragma once

template<class K, class V>
struct AVLTreeNode{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // ƽ������
	pair<K, V> _data;

	AVLTreeNode(const pair<K, V>& data)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& data){
		// 1. �Ȱ��������Ĺ�����в���
		if (_root == nullptr){
			_root = new Node(data);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur){
			if (cur->_data.first > data.first){
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_data.first < data.first){
				parent = cur;
				cur = cur->_right;
			}
			else{
				return false;
			}
		}
		// �Ѿ��ҵ����Բ����λ��
		cur = new Node(data);
		if (parent->_data.first < data.first){
			parent->_right = cur;
			cur->_parent = parent;
		}
		else{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 2. ����ƽ������(һ�������룬Ӱ�������������)
		while (parent){
			// ������parent���ң�parent��ƽ������++
			if (parent->_right == cur){
				parent->_bf++;
			}
			// ������parent����parent��ƽ������--
			else{
				parent->_bf--;
			}
			// ������parent��ƽ������Ϊ0����˵��parent�߶Ȳ��䣬���ϲ�û��Ӱ�죬���½����������
			if (parent->_bf == 0){
				break;
			}
			// ������parent��ƽ������Ϊ1����-1����˵��parent�߶ȸı䣬���ϸ���ƽ������
			else if (parent->_bf == 1 || parent->_bf == -1){
				cur = parent;
				parent = parent->_parent;
			}
			// ������parent��ƽ������Ϊ2����-2����˵��parent��������ƽ�⣬��Ҫ��ת����
			else if (parent->_bf == 2 || parent->_bf == -2){
				if (parent->_bf == 2){
					if (cur->_bf == 1){
						RotateL(parent);
					}
					else if (cur->_bf == -1){
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2){
					if (cur->_bf == -1){
						RotateR(parent);
					}
					else if (cur->_bf == 1){
						RotateLR(parent);
					}
				}
				break;
			}
		}
		return true;
	}

	// ����
	void RotateL(Node* parent){
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		parent->_right = SubRL; // subR���� ��ֵ�� parent����
		if (SubRL != nullptr){
			SubRL->_parent = parent;
		}
		SubR->_left = parent; // parent ��ֵ�� subR����
		Node* ppNode = parent->_parent;
		parent->_parent = SubR;

		// 1.ԭ��parent�����ĸ������ڱ�ΪSubR
		if (parent == _root){
			_root = SubR;
			SubR->_parent = nullptr;
		}
		// 2.ԭ��parent�������ĸ�
		else{
			if (ppNode->_left == parent){
				ppNode->_left = SubR;
			}
			else{
				ppNode->_right = SubR;
			}
			SubR->_parent = ppNode;
		}
		// ����ƽ������
		parent->_bf = SubR->_bf = 0;
	}

	// �ҵ���
	void RotateR(Node* parent){
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		parent->_left = SubLR;
		if (SubLR != nullptr){
			SubLR->_parent = parent;
		}
		SubL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = SubL;

		if (parent == _root){
			_root = SubL;
			SubL->_parent = nullptr;
		}
		else{
			if (ppNode->_left == parent){
				ppNode->_left = SubL;
			}
			else{
				ppNode->_right = SubL;
			}
			SubL->_parent = ppNode;
		}
		SubL->_bf = parent->_bf = 0;
	}

	// ����˫��
	void RotateRL(Node* parent){
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		int bf = SubRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);
		if (bf == -1){
			parent->_bf = 0;
			SubR->_bf = 1;
			SubRL->_bf = 0;
		}
		else if (bf == 1){
			parent->_bf = -1;
			SubR->_bf = 0;
			SubRL->_bf = 0;
		}
		else if (bf == 0){
			parent->_bf = 0;
			SubR->_bf = 0;
			SubRL->_bf = 0;
		}
	}

	// ����˫��
	void RotateLR(Node* parent){
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubLR->_bf;
		RotateL(SubL);
		RotateR(parent);

		if (bf == 1){
			parent->_bf = 0;
			SubL->_bf = -1;
			SubLR->_bf = 0;
		}
		else if (bf == -1){
			parent->_bf = 1;
			SubL->_bf = 0;
			SubLR->_bf = 0;
		}
		else if (bf == 0){
			parent->_bf = 0;
			SubL->_bf = 0;
			SubLR->_bf = 0;
		}
	}
private:
	Node* _root;
};