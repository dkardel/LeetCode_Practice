#include "BinSearch.h"

int BinarySearch(std::vector<int> array, int key)
{
	int start = 0, end = array.size()-1, mid = start + ((end-start)/2);
	while (start <= end)
	{
		if (array[mid] == key)
			return mid;
		else if (array[mid] < key)
		{
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}

		mid = start + (end - start) / 2;
	}
	return -1;
}
int BinarySearch(std::vector<int> array, int start, int end, int key)
{
	int mid = start + ((end - start) / 2);
	while (start <= end)
	{
		if (array[mid] == key)
			return mid;
		else if (array[mid] < key)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

		mid = start + (end - start) / 2;
	}
	return -1;
}


int BinarySearchRev(std::vector<int> array, int key) 
{
	int start = 0, end = array.size() - 1, mid = start + ((end - start) / 2);
	while (start <= end)
	{
		if (array[mid] == key)
			return mid;
		else if (array[mid] < key)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}

		mid = start + (end - start) / 2;
	}
	return -1;
}

int NumberOfRotationInSortedArray(std::vector<int> array)
{
	int N = array.size();
	int start = 0, end = N - 1, mid = start + ((end - start) / 2);
	while (start <= end)
	{
		int next = (mid + 1) % N;
		int prev = (mid + N - 1) % N;
		if (array[mid] < array[next] && array[prev]>array[mid])
			return mid;
		else if (array[mid] < array[end])
		{
			end = (mid- 1);
		}
		else
		{
			start = (mid + 1);
		}

		mid = (start + (end - start) / 2);
	}
	return -1;
}

int FindNumberInSortedRotatedArray(std::vector<int> array, int key)
{
	int N = array.size();
	int start = 0, end = N - 1, mid = start + ((end - start) / 2);
	int minEleIndx = 0;
	while (start <= end)
	{
		int next = (mid + 1) % N;
		int prev = (mid + N - 1) % N;
		if (array[mid] < array[next] && array[prev]>array[mid])
		{
			minEleIndx =  mid;
			break;
		}
		else if (array[mid] < array[end])
		{
			end = (mid - 1);
		}
		else
		{
			start = (mid + 1);
		}

		mid = (start + (end - start) / 2);
	}

	int k = BinarySearch(array, minEleIndx, N - 1, key);
	int j = BinarySearch(array, 0, minEleIndx - 1, key);
	if (j == -1 && k == -1)
		return -1;
	else if (j == -1)
	{
		return k;
	}
	else
	{
		return j;
	}
}