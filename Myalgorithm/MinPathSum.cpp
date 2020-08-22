#include"Leetcode.h"

int MinPathSum(vector<vector<int>> &grid)
{
	if (grid.size() == 0 || grid[0].size() == 0) return 0;
	int rows = grid.size();
	int cloum = grid[0].size();
	vector<vector<int>> dp(rows,vector<int>(cloum));
	//int *dp = new int[rows][cloum];
	dp[0][0] = grid[0][0];
	for (int i = 1; i < rows; i++)
	{
		dp[i][0] = grid[i][0] + dp[i - 1][0];
	}
	for (int j = 1; j < cloum; j++)
	{
		dp[0][j] = grid[0][j] + dp[0][j - 1];
	}
	for (int i = 1 ; i < rows; i++)
	{
		for (int j = 1 ; j < cloum; j++)
		{
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	return dp[rows - 1][cloum - 1];
}
