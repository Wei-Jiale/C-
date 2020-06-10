#include<iostream>
#include<vector>
using namespace std;

int main(){
	int w, h, res = 0;
	cin >> w >> h;
	// �����ά����array
	vector<vector<int>> array;
	array.resize(w);
	for (auto& e : array){
		e.resize(h, 1);
	}

	for (int row = 0; row < w; row++){
		for (int col = 0; col < h; col++){
			if (array[row][col] == 1){
				res++;
				// ��ǲ��ܷŵ����λ��
				if ((row + 2) < w){
					array[row + 2][col] = 0;
				}
				if ((col + 2) < h){
					array[row][col + 2] = 0;
				}
			}
		}
	}
	cout << res;
	return 0;
}