#include"myheadfile.h"

class MyStack
{
	queue<int> que;

	void push(int x)
	{
		que.push(x);
		int i = que.size();
		while (i-- > 1)
		{
			que.push(que.front());
			que.pop();
		}
	}

	int pop()
	{
		int a = que.front();
		 que.pop();
		 return a;
	}

	int top()
	{
		return que.front();
	}

	bool empty()
	{
		return que.empty();
	}

};