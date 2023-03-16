#pragma once
#include <iostream>
#include <vector>
#include <stack>

std::vector<int>& NearestGreaterToRight(std::vector<int> array);
std::vector<int>& NearestSmallerToRight(std::vector<int> array);
std::vector<int>& NearestSmallerToLeft(std::vector<int> array);
std::vector<int>& NearestGreaterToLeft(std::vector<int> array);
std::vector<int>& StockSpanProblem(std::vector<int> array);
int AreaOfHisto(std::vector<int> array);
int AreaOfBinaryMatrix(std::vector<std::vector<int>> matrix, int row, int col);
int RainWaterTrapping(std::vector<int> array);

class MinStack
{
	std::stack<int> stk;
	std::stack<int> sstk;
public:
	void push(int element);
	int pop();
	int getMin();
};

class MinStackOderOfOne
{
	std::stack<int> stk;
	int minValue;
public:
	void push(int element);
	int pop();
	int getMin();
	int top();
};