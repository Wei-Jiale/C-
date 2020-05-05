template<class T>
T Add(const T& left, const T& right){
	return left + right;
}

int main(){
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	// 隐式实例化
	Add(a1, a2);
	Add(d1, d2);
	return 0;
}

template<class T>
T Add(const T& left, const T& right){
	return left + right;
}

int main(){
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	// 显示实例化
	Add<int>(a1, d1);
	return 0;
}