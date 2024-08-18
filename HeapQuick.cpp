#ifndef _HEAP_QUICK_
#define _HEAP_QUICK_
#include <iostream>
#include <vector>
#endif // !_HEAP_QUICK_

static void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(std::vector<int> vectTree, int i)
{
	int size = vectTree.size();
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<size && vectTree[left]>vectTree[largest])
	{
		largest = left;
	}
	if (right<size && vectTree[right]>vectTree[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(&vectTree[i], &vectTree[largest]);
		heapify(vectTree, largest);
	}
}
