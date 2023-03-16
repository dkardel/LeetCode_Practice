int kthMinElement( std::vector<int> array, int k)
{
	std::priority_queue<int> mxheap;
	for (int i = 0; i < array.size(); i++)
	{
		mxheap.push(array[i]);
		if (mxheap.size() > k)
		{
			mxheap.pop();
		}
	}
	return mxheap.top();
}
int kthMaxElement(std::vector<int> array, int k)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	for (int i = 0; i < array.size(); i++)
	{
		minHeap.push(array[i]);
		if (minHeap.size() > k)
		{
			minHeap.pop();
		}
	}
	return minHeap.top();
}
void kMaxElement(std::vector<int> array, int k)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	for (int i = 0; i < array.size(); i++)
	{
		minHeap.push(array[i]);
		if (minHeap.size() > k)
		{
			minHeap.pop();
		}
	}
	std::cout << "Top " << k << " Elements : ";
	for (int i = 0; i < k; i++)
	{
		if (!minHeap.empty())
		{
			std::cout << minHeap.top() << " ";
			minHeap.pop();
		}
	}
}
void kMinElement(std::vector<int> array, int k)
{
	std::priority_queue<int, std::vector<int>> minHeap;
	for (int i = 0; i < array.size(); i++)
	{
		minHeap.push(array[i]);
		if (minHeap.size() > k)
		{
			minHeap.pop();
		}
	}
	std::cout << "Top " << k << " Elements : ";
	for (int i = 0; i < k; i++)
	{
		if (!minHeap.empty())
		{
			std::cout << minHeap.top() << " ";
			minHeap.pop();
		}
	}
}
void kClosestElement(std::vector<int> array, int k)
{
	std::priority_queue<std::pair<int, int>> maxHeap;
	for (int i = 0; i < array.size(); i++)
	{
		maxHeap.push(std::make_pair(abs(array[i]-k), array[i]));
		if (maxHeap.size() > 3)
		{
			maxHeap.pop();
		}
	}
	std::cout << "\nTop 3 closest Elements : ";
	for (int i = 0; i < 3; i++)
	{
		if (!maxHeap.empty())
		{
			std::cout << maxHeap.top().second << " ";
			maxHeap.pop();
		}
	}
}
class Compare
{
	public:
		bool operator()(std::pair<int, int> a, std::pair<int, int> b)
	{
		return a.second > b.second;
	}
};
void TopFreqNumbers(std::vector<int> array)
{
	std::unordered_map<int, int> mp;
	for (int i = 0; i < array.size(); ++i)
	{
		if (mp.find(array[i]) != mp.end())
			mp[array[i]]++;
		else
			mp.insert(std::make_pair(array[i], 1));
	}
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> maxHeap;
	for (auto it = mp.begin(); it!=mp.end(); it++)
	{
		maxHeap.push(*it);
		if (maxHeap.size() > 2)
		{
			maxHeap.pop();
		}
	}
	std::cout << "\nTop 2 Freq Elements : ";
	for (int i = 0; i < 2; i++)
	{
		if (!maxHeap.empty())
		{
			std::cout << maxHeap.top().first << " ";
			maxHeap.pop();
		}
	}
}
void SortAsFreqNumbers(std::vector<int> array)
{
	std::unordered_map<int, int> mp;
	for (int i = 0; i < array.size(); ++i)
	{
		if (mp.find(array[i]) != mp.end())
			mp[array[i]]++;
		else
			mp.insert(std::make_pair(array[i], 1));
	}
	std::priority_queue<std::pair<int, int>> maxHeap;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		maxHeap.push(std::make_pair(it->second, it->first));
	}
	std::cout << "\nSorted As per Freq Elements : ";
	for (int i = 0; i < mp.size(); i++)
	{
		if (!maxHeap.empty())
		{
			std::cout << maxHeap.top().second << " ";
			maxHeap.pop();
		}
	}
}
void KPointsClosestFromOrigin(std::vector<std::pair<int, int>> array, int k)
{

	std::priority_queue<std::pair<int, std::pair<int, int>>> maxHeap;
	for (int i=0; i<array.size(); ++i)
	{
		int distance = array[i].second * array[i].second + array[i].first * array[i].first;
		maxHeap.push(std::make_pair(distance, array[i]));
		if (maxHeap.size() > k)
		{
			maxHeap.pop();
		}
	}
	std::cout << "\nSorted As per Freq Elements : ";
	for (int i = 0; i < k; i++)
	{
		if (!maxHeap.empty())
		{
			std::cout << "{ " << maxHeap.top().second.first << ", " << maxHeap.top().second.second << "}, ";
			maxHeap.pop();
		}
	}
}
void LowestCostForRope(std::vector<int> array)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> maxHeap;
	for (int i = 0; i < array.size(); i++)
	{
		maxHeap.push(array[i]);
	}
	std::cout << "\nMinimal Cost of Rope : ";
	int cost = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (!maxHeap.empty())
		{   
			int temp = maxHeap.top();
			maxHeap.pop();
			if (!maxHeap.empty())
			{
				temp = temp + maxHeap.top();
				maxHeap.pop();
				maxHeap.push(temp);
			}
			else
				break;
			cost += temp;
		}
	}
	std::cout << cost;
}
