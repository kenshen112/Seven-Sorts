/***********************************************************************
 * Module:
 *    Week 11, Sort Heap
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Heap Sort
 ************************************************************************/

#ifndef SORT_HEAP_H
#define SORT_HEAP_H
#include <iostream>
#include <algorithm>

/*****************************************************
 * SORT HEAP
 * Perform the heap sort
 ****************************************************/
template <class T>
class Heap
{
private:
	T *array;
	int num;
public:
	Heap()
	{
		array = NULL;
		num = 0;
	}

	Heap(T arrayInput, int numInput)
	{
		array = arrayInput;
		num = numInput;

		for (int index = (num / 2); index < num; index++)
		{
			percolateDown(index);
		}
	}

	void percolateDown(int index);
};


template<class T>
void Heap<T>::percolateDown(int index)
{
	int indexLeft = index * 2;
	int indexRight = indexLeft + 1;

	if (indexRight < num && array[indexRight] > array[indexLeft] 
		&& array[indexRight] > array[index])
	{
		std::swap(index, indexRight);
		percolateDown(indexRight);
	}

	else if (indexLeft < num && array[indexLeft] > array[index])
	{
		std::swap(index, indexLeft);
		percolateDown(indexLeft);
	}
}

template <class T>
void sortHeap(T array[], int num)
{
	Heap<T> heap;

	while (num > 1)
	{
		num--;
		heap.percolateDown(1);
	}
}


#endif // SORT_HEAP_H
