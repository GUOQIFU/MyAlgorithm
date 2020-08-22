#include"Leetcode.h"

bool IsValid(vector<string> &board, int rows, int col)
{
	int n = board.size();
	//检查同列
	for (int i = 0; i < rows; i++) {
		if (board[i][col] == 'Q') {
			return false;
		}
	}
	//右上对角线
	for (int i = rows - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}
	//左上对角线
	for (int i = rows - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}
	return true;
 }

void backtrace(vector<string> &board, int rows, vector<vector<string>> &res)//res 存储最后结果
{
	//返回条件
	if (rows == board.size())
	{
		res.push_back(board);
		return;
	}
		
	//for 选择
	for (size_t col = 0; col < board[rows].size(); col++)
	{
		if (!IsValid(board, rows, col))
		{
			continue;
		}
		//做选择与撤销选择
		board[rows][col] = 'Q';
		backtrace(board, rows + 1, res);
		board[rows][col] = '*';
	}
}

vector<vector<string>>SolveNQueens(int n)//N皇后问题
{
	vector<vector<string>> res;
	//初始化棋盘
	vector<string> board(n, string(n, '*'));
	backtrace(board, 0, res);
	return res;
}