#include "StackProblems.h"

std::vector<int>& NearestGreaterToRight(std::vector<int> array)
{
	std::vector<int> ret;
	std::stack<int> stk;
	for (int i = array.size()-1; i >= 0 ; i--)
	{
		if (stk.size() == 0)
		{
			ret.push_back(-1);
		}
		else if (stk.size() > 0 && stk.top() > array[i])
		{
			ret.push_back(stk.top());
		}
		else if (stk.size() > 0 && stk.top() <= array[i])
		{
				while (stk.size() > 0 && stk.top() <= array[i])
				{
					stk.pop();
				}
				if (stk.size() == 0)
					ret.push_back(-1);
				else
					ret.push_back(stk.top());
		}
		stk.push(array[i]);
	}
	std::reverse(ret.begin(), ret.end());
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		std::cout << ret[i] << " ";
	}
	return ret;
}

std::vector<int>& NearestSmallerToRight(std::vector<int> array)
{
	std::vector<int> ret;
	std::stack<int> stk;
	for (int i = array.size() - 1; i >= 0; i--)
	{
		if (stk.size() == 0)
		{
			ret.push_back(-1);
		}
		else if (stk.size() > 0 && stk.top() < array[i])
		{
			ret.push_back(stk.top());
		}
		else if (stk.size() > 0 && stk.top() >= array[i])
		{
			while (stk.size() > 0 && stk.top() >= array[i])
			{
				stk.pop();
			}
			if (stk.size() == 0)
				ret.push_back(-1);
			else
				ret.push_back(stk.top());
		}
		stk.push(array[i]);
	}
	std::reverse(ret.begin(), ret.end());
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		std::cout << ret[i] << " ";
	}
	return ret;
}

std::vector<int>& NearestGreaterToLeft(std::vector<int> array)
{
	std::vector<int> ret;
	std::stack<int> stk;
	for (int i = 0; i < array.size(); i++)
	{
		if (stk.size() == 0)
		{
			ret.push_back(-1);
		}
		else if (stk.size() > 0 && stk.top() > array[i])
		{
			ret.push_back(stk.top());
		}
		else if (stk.size() > 0 && stk.top() <= array[i])
		{
			while (stk.size() > 0 && stk.top() <= array[i])
			{
				stk.pop();
			}
			if (stk.size() == 0)
				ret.push_back(-1);
			else
				ret.push_back(stk.top());
		}
		stk.push(array[i]);
	}
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		std::cout << ret[i] << " ";
	}
	return ret;
}

std::vector<int>& NearestSmallerToLeft(std::vector<int> array)
{
	std::vector<int> ret;
	std::stack<int> stk;
	for (int i = 0; i <array.size(); i++)
	{
		if (stk.size() == 0)
		{
			ret.push_back(-1);
		}
		else if (stk.size() > 0 && stk.top() < array[i])
		{
			ret.push_back(stk.top());
		}
		else if (stk.size() > 0 && stk.top() >= array[i])
		{
			while (stk.size() > 0 && stk.top() >= array[i])
			{
				stk.pop();
			}
			if (stk.size() == 0)
				ret.push_back(-1);
			else
				ret.push_back(stk.top());
		}
		stk.push(array[i]);
	}
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		std::cout << ret[i] << " ";
	}
	return ret;
}

std::vector<int>& NearestGreaterToRightIndex(std::vector<int> array)
{
	static std::vector<int> ret;
	std::stack<std::pair<int, int>> stk;
	for (int i = array.size() - 1; i >= 0; i--)
	{
		if (stk.size() == 0)
		{
			ret.push_back(array.size());
		}
		else if (stk.size() > 0 && stk.top().first > array[i])
		{
			ret.push_back(stk.top().second);
		}
		else if (stk.size() > 0 && stk.top().first <= array[i])
		{
			while (stk.size() > 0 && stk.top().first <= array[i])
			{
				stk.pop();
			}
			if (stk.size() == 0)
				ret.push_back(array.size());
			else
				ret.push_back(stk.top().second);
		}
		stk.push(std::make_pair(array[i], i));
	}
	std::reverse(ret.begin(), ret.end());
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		std::cout << ret[i] << " ";
	}
	return ret;
}

std::vector<int>& NearestSmallerToRightIndex(std::vector<int> array)
{
	static std::vector<int> ret;
	ret.clear();
	std::stack<std::pair<int, int>> stk;
	for (int i = array.size() - 1; i >= 0; i--)
	{
		if (stk.size() == 0)
		{
			ret.push_back(array.size());
		}
		else if (stk.size() > 0 && stk.top().first < array[i])
		{
			ret.push_back(stk.top().second);
		}
		else if (stk.size() > 0 && stk.top().first >= array[i])
		{
			while (stk.size() > 0 && stk.top().first >= array[i])
			{
				stk.pop();
			}
			if (stk.size() == 0)
				ret.push_back(array.size());
			else
				ret.push_back(stk.top().second);
		}
		stk.push(std::make_pair(array[i],i));
	}
	std::reverse(ret.begin(), ret.end());
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		std::cout << ret[i] << " ";
	}
	return ret;
}

std::vector<int>& NearestGreaterToLeftIndex(std::vector<int> array)
{
	static std::vector<int> ret;
	std::stack<std::pair<int, int>> stk;
	for (int i = 0; i < array.size(); i++)
	{
		if (stk.size() == 0)
		{
			ret.push_back(-1);
		}
		else if (stk.size() > 0 && stk.top().first > array[i])
		{
			ret.push_back(stk.top().second);
		}
		else if (stk.size() > 0 && stk.top().first <= array[i])
		{
			while (stk.size() > 0 && stk.top().first <= array[i])
			{
				stk.pop();
			}
			if (stk.size() == 0)
				ret.push_back(-1);
			else
				ret.push_back(stk.top().second);
		}
		stk.push(std::make_pair(array[i], i));
	}
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		std::cout << ret[i] << " ";
	}
	return ret;
}

std::vector<int>& NearestSmallerToLeftIndex(std::vector<int> array)
{
	static std::vector<int> ret;
	ret.clear();
	std::stack<std::pair<int, int>> stk;
	for (int i = 0; i < array.size(); i++)
	{
		if (stk.size() == 0)
		{
			ret.push_back(-1);
		}
		else if (stk.size() > 0 && stk.top().first < array[i])
		{
			ret.push_back(stk.top().second);
		}
		else if (stk.size() > 0 && stk.top().first >= array[i])
		{
			while (stk.size() > 0 && stk.top().first >= array[i])
			{
				stk.pop();
			}
			if (stk.size() == 0)
				ret.push_back(-1);
			else
				ret.push_back(stk.top().second);
		}
		stk.push(std::make_pair(array[i], i));
	}
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		std::cout << ret[i] << " ";
	}
	return ret;
}

std::vector<int>& StockSpanProblem(std::vector<int> array)
{
	std::vector<int> ret;
	std::stack<std::pair<int, int>> stk;
	for (int i = 0; i < array.size(); i++)
	{
		if (stk.size() == 0)
		{
			ret.push_back(-1);
		}
		else if (stk.size() > 0 && stk.top().first > array[i])
		{
			ret.push_back(stk.top().second);
		}
		else if (stk.size() > 0 && stk.top().first <= array[i])
		{
			while (stk.size() > 0 && stk.top().first <= array[i])
			{
				stk.pop();
			}
			if (stk.size() == 0)
				ret.push_back(-1);
			else
				ret.push_back(stk.top().second);
		}
		stk.push(std::make_pair(array[i], i));
	}
	std::cout << std::endl;
	for (int i = 0; i < ret.size(); i++)
	{
		ret[i] = i - ret[i];
		std::cout << i-ret[i] << " ";
	}
	return ret;
}

int AreaOfHisto(std::vector<int> array)
{
	std::vector<int> smlToLeft, smlToRight, area;

	smlToLeft = NearestSmallerToLeftIndex(array);
	smlToRight = NearestSmallerToRightIndex(array);
	std::cout << std::endl;
	for (int i = 0; i < array.size(); i++)
	{
		area.push_back((smlToRight[i] - smlToLeft[i] -1) * array[i]);
	}
	int temp = area[0];
	for (int i = 1; i < array.size(); i++)
	{
		if (temp < area[i])
			temp = area[i];
	}
	std::cout << "\nMax Area of histo is : " << temp << std::endl;
	return temp;
}

int AreaOfBinaryMatrix(std::vector<std::vector<int>> matrix, int row, int col)
{
	std::vector<int> histVect;
	int max = 0;
	for (int i = 0; i <col; i++)
	{
		histVect.push_back(matrix[0][i]);
	}
	max = AreaOfHisto(histVect);

	for (int i = 1; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
				histVect[j] = 0;
			else
				histVect[j] = histVect[j] + matrix[i][j];				
		}
		max = std::max(max, AreaOfHisto(histVect));
	}

	std::cout << "\nMax Area of histo is : " << max << std::endl;
	return max;
}

int RainWaterTrapping(std::vector<int> array)
{
	std::vector<int> maxToLeft(array.size()), maxToRight(array.size()), waterLevel(array.size());
	maxToLeft[0] = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		maxToLeft[i]=std::max(maxToLeft[i - 1], array[i]);
	}
	maxToRight[array.size() - 1] = (array[array.size() - 1]);
	for (int i = array.size()-2; i >= 0; i--)
	{
		maxToRight[i] = (std::max(maxToRight[i + 1], array[i]));
	}
	std::cout << std::endl;
	for (int i = 0; i < array.size(); i++)
	{
		waterLevel[i] = (std::min(maxToLeft[i], maxToRight[i]) - array[i]);
	}
	int temp = 0;
	for (int i = 0; i < array.size(); i++)
	{
			temp += waterLevel[i];
	}
	std::cout << "\nTotal Water level is : " << temp << std::endl;
	return temp;
}


	void MinStack::push(int element)
	{
		stk.push(element);
		if (sstk.empty()  || sstk.top() > element)
			sstk.push(element);
	}
	int MinStack::pop()
	{
		if (!sstk.empty() && !stk.empty())
		{
			int temp = stk.top();
			int stemp = sstk.top();
			if (stemp == temp)
			{
				sstk.pop();
			}
			if (!stk.empty())
				stk.pop();
			return temp;
		}
		else
			return -1;
	}
	int MinStack::getMin()
	{
		if (sstk.size() == 0)
			return -1;
		else
			return sstk.top();
	}

	void MinStackOderOfOne::push(int element)
	{
		if (stk.empty())
		{
			stk.push(element);
			minValue = element;
		}
		else if (minValue > element)
		{
			stk.push(2 * element - minValue);
			minValue = element;
		}
		else
		{
			stk.push(element);
		}
	}
	int MinStackOderOfOne::pop()
	{
		if (!stk.empty())
		{
			int currentTop = stk.top();
			int oldMin = minValue;
			if (currentTop < minValue)
			{
				minValue = 2 * minValue - currentTop;
				stk.pop();
				return oldMin;
			}
			else
			{
				int currentTop = stk.top();
				stk.pop();
				return currentTop;
			}
		}
		else
			return -1;
	}
	int MinStackOderOfOne::getMin()
	{
		if (stk.size() == 0)
			return -1;
		else
			return minValue;
	}

	int MinStackOderOfOne::top()
	{
		if (!stk.empty())
		{
			int currentTop = stk.top();
			int oldMin = minValue;
			if (currentTop < minValue)
			{
				minValue = 2 * minValue - currentTop;
				return oldMin;
			}
			else
			{
				int currentTop = stk.top();
				return currentTop;
			}
		}
		else
			return -1;
	}