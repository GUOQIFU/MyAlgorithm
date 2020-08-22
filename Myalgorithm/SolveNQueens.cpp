#include"Leetcode.h"

bool IsValid(vector<string> &board, int rows, int col)
{
	int n = board.size();
	//���ͬ��
	for (int i = 0; i < rows; i++) {
		if (board[i][col] == 'Q') {
			return false;
		}
	}
	//���϶Խ���
	for (int i = rows - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}
	//���϶Խ���
	for (int i = rows - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 'Q') {
			return false;
		}
	}
	return true;
 }

void backtrace(vector<string> &board, int rows, vector<vector<string>> &res)//res �洢�����
{
	//��������
	if (rows == board.size())
	{
		res.push_back(board);
		return;
	}
		
	//for ѡ��
	for (size_t col = 0; col < board[rows].size(); col++)
	{
		if (!IsValid(board, rows, col))
		{
			continue;
		}
		//��ѡ���볷��ѡ��
		board[rows][col] = 'Q';
		backtrace(board, rows + 1, res);
		board[rows][col] = '*';
	}
}

vector<vector<string>>SolveNQueens(int n)//N�ʺ�����
{
	vector<vector<string>> res;
	//��ʼ������
	vector<string> board(n, string(n, '*'));
	backtrace(board, 0, res);
	return res;
}