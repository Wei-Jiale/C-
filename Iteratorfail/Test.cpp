#include<iostream>
#include<vector>
using namespace std;

void Test_iterator1(){
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);

	vector<int>::iterator it = array.begin();

	array.push_back(6);
	// 1.���ݿ��ܵ��µ�����ʧЧ��push_back,insert,resize,reserve��
	// array.push_back(7); 
	// ����7�����������ʧЧ����
	// vector�ռ䲻�������ݣ������µĿռ䣬�����ݿ������¿ռ����ͷžɿռ�
	// ��ʱit��ָ��ɿռ��Ѿ����ͷţ��Ӷ�����itʧЧ
	// ��Ҫ�ڵ���������֮����п������ݵĲ���

	while (it != array.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void Test_iterator2(){
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);

	// 2.it������ı䵼�µ�����ʧЧ
	// Ҫ��ɾ�������е�����ż��
	// ɾ��2����3��4��5��6��ǰŲһλ����ʱitָ��3��++it��3û�б��жϣ����µ�����ʧЧ
	// vs�½��м��ᱨ��  gcc�²����鵼�½��������
	/*vector<int>::iterator it = array.begin();
	while (it != array.end()){
		if (*it % 2 == 0){
			array.erase(it);
		}
		
		++it;
	}*/

	// ���
	// erase����ɾ��it����һ��λ�õĵ�����
	vector<int>::iterator it = array.begin();
	while (it != array.end()){
		if (*it % 2 == 0){
			it = array.erase(it);
		}
		else{
			++it;
		}
	}

	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}

int main(){
	Test_iterator1();
	Test_iterator2();
}