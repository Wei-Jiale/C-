#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int GetMiddle(vector<int>& array, int begin, int end){
	if (array.size() >= 3){
		// ��ȡ��λ���±�
		int mid = (begin + end) >> 1;
		// �����Ƚ�
		if (array[begin] < array[mid]){
			if (array[mid] < array[end]){
				// begin < mid < end
				return mid;
			}
			else if (array[begin] < array[end]){
				// mid > end > begin
				return end;
			}
			else{
				// mid > begin > end
				return begin;
			}
		}
		else{
			// begin > mid
			if (array[end] < array[mid]){
				// begin > mid > end
				return mid;
			}
			else if (array[begin]>array[end]){
				// begin > end > mid
				return end;
			}
			else{
				// end > begin > mid 
				return begin;
			}
		}
	}
	else{
		if (array[begin] > array[end]){
			swap(array[begin], array[end]);
		}
		return 0;
	}
}

// ǰ��ָ��
int Partsort(vector<int>& array, int begin, int end){
	// ��׼ֵ
	int midindex = GetMiddle(array, begin, end);
	swap(array[end], array[midindex]);

	int cur = begin;
	int prev = begin - 1;

	while (cur < end){
		// �ҵ�С�ڻ�׼ֵ��Ԫ��
		// ����ָ��һ���ߣ����������ڻ�׼ֵ��Ԫ��ǰָ��ͣ�£���ָ�����++
		if (array[cur] < array[end] && ++prev != cur){
			swap(array[cur], array[prev]);
		}
		cur++;
	}

	prev++;
	// �ͻ�׼ֵ����
	swap(array[prev], array[end]);
	return prev;
}

// �ݹ���ܻᵼ��ջ���
// ���Ż���ջģ��ʵ�ַǵݹ�
void QuicksortNonr(vector<int>& array, int begin, int end){
	if (end - begin < 1){
		return;
	}

	stack<int> st;
	st.push(begin);
	st.push(end);

	while (!st.empty()){
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();

		int keyindex = Partsort(array, left, right);
		if (left < keyindex - 1){
			// �����������������ջ
			st.push(left);
			st.push(keyindex - 1);
		}
		if (keyindex + 1 < end){
			st.push(keyindex + 1);
			st.push(end);
		}

	}
}

int main(){
	vector<int> array = { 4, 5, 7, 8, 1, 2, 3, 6 };
	QuicksortNonr(array, 0, array.size() - 1);

	for (const auto& e : array){
		cout << e << " ";
	}
	cout << endl;
}