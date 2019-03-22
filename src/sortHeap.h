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
			array = new T[num];
		}

		catch(std::bad_alloc)
		{
			std::cerr << "Bad Malloc" << '\n';
		}


		array = arrayInput;
		num = numInput;

		for (int index = (num / 2); index > 0; index--)
		{
			std::cerr << "Heapify: " << index << std::endl;
			percolateDown(index);
		}
	}


	T getMax();
	void deleteMax();
	void sort();
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
		std::cerr << "IndexRight" << std::endl;
		std::swap(index, indexRight);
		percolateDown(indexRight);
	}

	else if (indexLeft < num && array[indexLeft] > array[index])
	{
		std::cerr << "Index Left: " << indexLeft << std::endl;
		std::cerr << "Index: " << index << std::endl;
		std::swap(index, indexLeft);
		percolateDown(indexLeft);
	}
}

template <class T>
void sortHeap(T array[], int num)
{
	Heap<T> heap(array, num); // heapffy
}


#endif // SORT_HEAP_H
