// 井字棋
#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		int row = board.size();
		int i, j, sum;
		// 行
		for (i = 0; i < row; i++){
			sum = 0;
			for (j = 0; j < row; j++){
				sum = sum + board[i][j];
			}
			if (sum == row){
				return true;
			}
		}

		// 列
		for (i = 0; i < row; i++){
			sum = 0;
			for (j = 0; j < row; j++){
				sum = sum + board[j][i];
			}
			if (sum == row){
				return true;
			}
		}

		// 主对角线
		sum = 0;
		for (i = 0; i < row; i++){
			sum = sum + board[i][i];
		}
		if (sum == row){
			return true;
		}

		// 副对角线
		sum = 0;
		for (i = 0; i<row; i++){
			sum = sum + board[i][row - i - 1];
		}
		if (sum == row){
			return true;
		}

		return false;
	}
};