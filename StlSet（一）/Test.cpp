#include<iostream>
#include<set>
using namespace std;

void TestSet(){
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(7);
	// ����+ȥ��
	set<int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ������������νṹ��
	set<int> copy(s);
	for (const auto& e : s){
		cout << e << " ";
	}
	cout << endl;

	// ����ɾ��������
	// O(logN)
	set<int>::iterator pos = s.find(3);
	// ���ҵ���ɾ��
	// ��û�ҵ�����endλ�ý���ɾ���Ƿ����Ա�������ж�
	if (pos != s.end()){
		s.erase(pos);
	}
	for (const auto& e : s){
		cout << e << " ";
	}
	cout << endl;

	// ����ɾ��ֵ
	s.erase(4);
	for (const auto& e : s){
		cout << e << " ";
	}
	cout << endl;
}

int main(){
	TestSet();
	return 0;
}