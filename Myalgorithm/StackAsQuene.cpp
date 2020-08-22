#include"myheadfile.h"

class MyQuene
{
	stack<int> inputStack;
	stack<int> outputStack;

	void input2outputStack()
	{

	}

	void push(int x)
	{
		if (outputStack.empty())
		{
			outputStack.push(x);
		}
		else {
			while (!outputStack.empty())
			{
				inputStack.push(outputStack.top());
				outputStack.pop();
			}
			inputStack.push(x);
			while (!inputStack.empty())
			{
				outputStack.push(inputStack.top());
				inputStack.pop();
			}
		}
		/*if (outputStack.empty())
		{
			outputStack.push(x);
		}
		else if(inputStack.empty()) {
			while (outputStack.top())
			{
				inputStack.push(outputStack.top());
				outputStack.pop();
			}
		}
		else {
			while (inputStack.top())
			{
				outputStack.push(inputStack.top());
				inputStack.pop();
			}
		}
		if (inputStack.empty())
		{
			inputStack.push(x);
			outputStack.push(inputStack.top());
		}*/
	}
	void pop()
	{
		outputStack.pop();
	}
	int peek()
	{
		return outputStack.top();
	}
	bool empty()
	{
		return outputStack.empty() && inputStack.empty();
	}
};