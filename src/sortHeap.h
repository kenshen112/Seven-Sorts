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
      heapify(arrayInput, numInput);
   }
   
   T getMax();
   void deleteMax();
   void sort();
   void heapify(T *arrayInput, int numInput);
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
	heapify(array, num);


	for(int i = num-1; i>=0; i--)
	{
		std::swap(array[0], array[i]);
		heapify(array, i);

	}
}

template<class T>
void Heap<T>::heapify(T * arrayInput, int numInput)
{
	array = arrayInput;
	num = numInput;

	for (int index = num / 2 - 1; index >= 0; index--)
	{
		percolateDown(index);
	}
}

template<class T>
void Heap<T>::percolateDown(int index)
{
	int indexLeft = index * 2 + 1;
	int indexRight = indexLeft + 1;

	if (indexRight < num && array[indexRight] > array[indexLeft] && array[indexRight] > array[index])
	{
		index = indexRight;
	}

	else if (indexLeft < num && array[indexLeft] > array[index])
	{
		index = indexLeft;
	}

	if (array[index] == array[0])
	{
		return;
	}

	else
	{
		std::swap(array[0], array[index]);
	}

	percolateDown(0);
}

template <class T>
void sortHeap(T array[], int num)
{
	Heap<T> heap(array, num); // heapifies
	heap.sort();
}


#endif // SORT_HEAP_H
