//������������
//arr2 �е�Ԫ�ظ�����ͬ
//arr2 �е�ÿ��Ԫ�ض������� arr1 ��
//�� arr1 �е�Ԫ�ؽ�������ʹ arr1 ��������˳��� arr2 �е����˳����ͬ��δ�� arr2 �г��ֹ���Ԫ����Ҫ����������� arr1 ��ĩβ��
//���룺arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//�����[2,2,2,1,4,3,3,9,6,7,19]

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		int tmp = 0;
		for (int i = 0; i<arr2.size(); ++i)
		for (int j = 0; j<arr1.size(); ++j){
			if (arr1[j] == arr2[i]){
				swap(arr1[j], arr1[tmp]); ++tmp;
			}
		}
		sort(arr1.begin() + tmp, arr1.end());
		return arr1;
	}
};