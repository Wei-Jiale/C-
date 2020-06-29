#include<iostream>
#include<queue>
#include<functional> // �º���ͷ�ļ�
using namespace std;

void test_priority_queue(){
	// Ĭ�ϴ�����ȼ���
	// ���ȼ����еײ�ʵ����һ�����
	//priority_queue<int> pq;
	// Ӧ�÷º���ʹС�����ȼ���
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(3);
	pq.push(1);
	pq.push(9);
	pq.push(4);
	pq.push(2);

	// ������������֧�ֵ�����
	// ����������ͨ��������������ʣ����������ƻ�����������ԭ������
	while (!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
}

int main(){
	test_priority_queue();
	return 0;
}