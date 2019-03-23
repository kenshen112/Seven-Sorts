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

		for (int index = (num / 2); index > 0; index--)
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
	while (num > 1)
	{
		std::swap(array[1], array[num]);
		num--;
		percolateDown(1);
	}

}

template<class T>
void Heap<T>::percolateDown(int index)
{
	int indexLeft = index * 2;
	int indexRight = indexLeft + 1;

	if (array[indexRight] < array[num] && array[indexRight] > array[indexLeft] 
		&& array[indexRight] > array[index])
	{
		std::swap(array[index], array[indexRight]);
		percolateDown(indexRight);
	}

	else if (array[indexLeft] < array[num] && array[indexLeft] > array[index])
	{
		std::swap(array[index], array[indexLeft]);
		percolateDown(indexLeft);
	}
}

template <class T>
void sortHeap(T array[], int num)
{
	Heap<T> heap(array, num); // heapiffy
	std::cerr << "Before Sort" << std::endl;
	heap.sort();
	std::cerr << "After Sort" << std::endl;
}


#endif // SORT_HEAP_H
