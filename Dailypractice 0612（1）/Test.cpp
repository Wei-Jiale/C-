// 满二叉树的最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b){
			if (a>b){
				a = a / 2;
			}
			else{
				b = b / 2;
			}
		}

		return a;
	}
};