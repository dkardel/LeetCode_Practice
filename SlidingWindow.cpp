#include"SlidingWindow.h"

int CountOfAnagram(const std::string array, const std::string pattern)
{
	std::unordered_map<char, int> charMap;
	for (int i = 0; i < pattern.size(); i++)
	{
		if (charMap.find(pattern[i]) != charMap.end())
		{
			charMap[pattern[i]]++;
		}
		else
		{
			charMap.insert(std::make_pair(pattern[i], 1));
		}
	}
	int j = 0;
	int i = 0;
	int k = pattern.size();
	int count = charMap.size();
	int ans = 0;
	while (j < array.size())
	{
		if (charMap.find(array[j]) != charMap.end())
		{
			charMap[array[j]]--;
			if (charMap[array[j]] == 0)
				count--;
		}
		if (j - i + 1 < k)
		{
			j++;
		}
		else if(j-i+1==k)
		{  
			if (count == 0)
			{
				ans++;
			}
			if (charMap.find(array[i]) != charMap.end())
			{
				charMap[array[i]]++;
				if (charMap[array[i]] == 1)
					count++;
			}
			i++;
			j++;
		}	
	}
	return ans;
}

int MaximumSumOfSubArray(std::vector<int> array, int k)
{
	int mxsum = 0;
	int sum = 0;
	int i = 0;
	int j = 0;

	while (j < array.size())
	{   
		sum = sum + array[j];
		if (j - i + 1 < k)
		{
			j++;
		}
		else if (j - i + 1 == k)
		{
			mxsum = std::max(mxsum, sum);
			sum = sum - array[i];
			i++;
			j++;
		}
	}
	return mxsum;
}

std::vector<int>& FirstNegativeNumberInWindow(std::vector<int> array, int k)
{
	static std::vector<int> negativeNumbers;
	std::vector<int> negativeNumbersInWindow;

	int sum = 0;
	int i = 0;
	int j = 0;

	while (j < array.size())
	{
		if (array[j] < 0)
		{
			negativeNumbersInWindow.push_back(array[j]);
		}
		if (j - i + 1 < k)
		{
			j++;
		}
		else if (j - i + 1 == k)
		{
			if (negativeNumbersInWindow.size()==0)
			{
				negativeNumbers.push_back(0);
			}
			else
			{
				negativeNumbers.push_back(negativeNumbersInWindow[0]);
				if (negativeNumbersInWindow[0] == array[i])
				{
					negativeNumbersInWindow.erase(negativeNumbersInWindow.begin() + 0);
				}
			}
			i++;
			j++;
		}
	}
	return negativeNumbers;
}

std::vector<int>& MaxOfSubArray(std::vector<int> array, int k)
{
	static std::vector<int> maxArray;

	int sum = 0;
	int i = 0;
	int j = 0;
	int max = 0;

	while (j < array.size())
	{
		if (array[j] > max)
		{
			max = array[j];
		}
		if (j - i + 1 < k)
		{
			j++;
		}
		else if (j - i + 1 == k)
		{
			maxArray.push_back(max);
			if (max == array[i])
			{
				i++;
				max = array[i];
			}
			else
			{
				i++;
			}
			j++;
		}
	}
	return maxArray;
}

int SumOfLargestSubArray(std::vector<int> array, int k)
{
	int mxsize = 0;
	int sum = 0;
	int i = 0;
	int j = 0;

	while (j < array.size())
	{
		sum = sum + array[j];
		if (sum < k)
		{
			j++;
		}
		else if (sum == k)
		{
			int temp = j - i + 1;
			mxsize = std::max(temp, mxsize);
			j++;
		}
		else
		{
			while (sum > k)
			{
				sum = sum - array[i];
				i++;
			}
			j++;
		}
	}
	return mxsize;
}