#include"Leetcode.h"

int maxProfit_1(vector<int> &price) //1次交易
{
	if (price.size() == 0)return 0;
	int minprice = price[0];
	int maxprofie = 0;
	for (size_t i = 1; i < price.size(); i++)
	{
		if (minprice < price[i])
		{
			minprice = price[i];
		}
		maxprofie = max(maxprofie, price[i] - minprice);
	}
	return maxprofie;
}

int maxProfit_2(vector<int> &price) //股票最大利润问题，2次交易
{
	if (price.size() == 0) return 0;
	int n = price.size();
	int dp[5];
	// 初始化
	dp[0] = 0;
	dp[1] = -price[0];
	dp[2] = INT_MIN;
	dp[3] = INT_MIN;
	dp[4] = INT_MIN;
	for (int i = 1; i < n; i++)
	{
		dp[0] = 0;
		dp[1] = max(dp[1], dp[0] - price[i]);
		dp[2] = max(dp[2], dp[1] + price[i]);
		dp[3] = max(dp[3], dp[2] - price[i]);
		dp[4] = max(dp[4], dp[3] + price[i]);
	}
	return max(dp[2], dp[4]);
}



int maxProfit_more(vector<int> &price) //股票最大利润问题，多次交易,贪心算法
{
	if (price.size() == 0) return 0;
	int maxprofie = 0;
	for (size_t i = 0; i < price.size(); i++)
	{
		int profie = price[i] - price[i-1];
		if (profie > 0)
		{
			maxprofie += profie;
		}
	}
	return maxprofie;
}