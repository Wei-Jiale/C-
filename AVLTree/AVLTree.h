#pragma once

template<class K, class V>
struct AVLTreeNode{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // 平衡因子
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
		// 1. 先按搜索树的规则进行插入
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
		// 已经找到可以插入的位置
		cur = new Node(data);
		if (parent->_data.first < data.first){
			parent->_right = cur;
			cur->_parent = parent;
		}
		else{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 2. 更新平衡因子(一个结点插入，影响的是它的祖先)
		while (parent){
			// 新增在parent的右：parent的平衡因子++
			if (parent->_right == cur){
				parent->_bf++;
			}
			// 新增在parent的左：parent的平衡因子--
			else{
				parent->_bf--;
			}
			// 更新完parent的平衡因子为0，则说明parent高度不变，对上层没有影响，更新结束插入完成
			if (parent->_bf == 0){
				break;
			}
			// 更新完parent的平衡因子为1或者-1，则说明parent高度改变，向上更新平衡因子
			else if (parent->_bf == 1 || parent->_bf == -1){
				cur = parent;
				parent = parent->_parent;
			}
			// 更新完parent的平衡因子为2或者-2，则说明parent的子树不平衡，需要旋转处理
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

	// 左单旋
	void RotateL(Node* parent){
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		parent->_right = SubRL; // subR的左 赋值给 parent的右
		if (SubRL != nullptr){
			SubRL->_parent = parent;
		}
		SubR->_left = parent; // parent 赋值给 subR的左
		Node* ppNode = parent->_parent;
		parent->_parent = SubR;

		// 1.原来parent是树的根，现在变为SubR
		if (parent == _root){
			_root = SubR;
			SubR->_parent = nullptr;
		}
		// 2.原来parent不是树的根
		else{
			if (ppNode->_left == parent){
				ppNode->_left = SubR;
			}
			else{
				ppNode->_right = SubR;
			}
			SubR->_parent = ppNode;
		}
		// 更新平衡因子
		parent->_bf = SubR->_bf = 0;
	}

	// 右单旋
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

	// 右左双旋
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

	// 左右双旋
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