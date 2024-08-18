#include "Sort.h"
template <typename T>
void swap(T* num1, T* num2)
{
    T temp = std::move(*num1);
    *num1 = std::move(*num2);
    *num2 = std::move(temp);
}

template <typename T>
void selectionsort(T array[], int size)
{
    int i, j, min_idx = 0;
    for (i = 0; i < size; i++)
    {
        min_idx = i;
        for (j = i; j < size; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }
        if (i != min_idx)
        {
            swap(&array[i], &array[min_idx]);
        }
    }
}

template <typename T>
void bublesort(T array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

template <typename T>
void insertionsort(T array[], int size)
{
    int i, j;
    T key;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && key < array[j])
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

template <typename T>
int partition(T array[], int lb, int ub)
{
    T pivot = array[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (array[start] <= pivot)
        {
            start++;
        }
        while (pivot < array[end])
        {
            end--;
        }
        if (start < end)
            swap(&array[start], &array[end]);
    }
    swap(&array[lb], &array[ub]);
    return end;
}


template<typename T>
void bublesort(T array[], size_t size)
{
}

template <typename T>
void QuickSort(T array[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(array, lb, ub);
        QuickSort(array, lb, loc - 1);
        QuickSort(array, loc + 1, ub);
    }
}


