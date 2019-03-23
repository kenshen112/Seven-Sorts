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
	Heap(T *arrayInput, int numInput) //this is heapify
	{
		try
		{
			array = new T[numInput];
		}

		catch(std::bad_alloc)
		{
			std::cerr << "Bad Malloc" << '\n';
		}


		array = arrayInput;
		num = numInput;

		for (int index = (num / 2 - 1); index > 0; index--)
		{
			percolateDown(index);
		}
	}

	T getMax();
	void deleteMax();
	void sort();
	void percolateDown(int index);
};


template<class T>
T Heap<T>::getMax()
{
	return array[0];
}

template<class T>
void Heap<T>::deleteMax()
{
	array[0] = NULL;
}

template<class T>
void Heap<T>::sort()
{
	while (num > 0)
	{
		std::swap(array[num], array[0]);
		num = num - 1;
		percolateDown(0);
		
	}

}

template<class T>
void Heap<T>::percolateDown(int index)
{
	int indexLeft = index * 2;
	int indexRight = indexLeft + 1;

	if (indexRight < num && array[indexRight] > array[indexLeft] 
		&& array[indexRight] > array[0])
	{
		std::swap(array[index], array[indexRight]);
		percolateDown(indexRight);
	}

	else if (indexLeft < num && array[indexLeft] > array[0])
	{
		std::swap(array[index], array[indexLeft]);
		percolateDown(indexLeft);
	}

	if (array[index] == array[0])
	{
		return;
	}

	else
	{
		std::swap(array[0], array[index]);
	}

}

template <class T>
void sortHeap(T array[], int num)
{
	Heap<T> heap(array, num); // heapifies
	std::cerr << "Before Sort" << std::endl;
	heap.sort();
	std::cerr << "After Sort" << std::endl;
}


#endif // SORT_HEAP_H
