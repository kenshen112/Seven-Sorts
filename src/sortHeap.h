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
   void swap(int t1, int t2);
};

/************************************
 *takes two elements from the array and swaps their places
 **************************************************/
template<class T>
void Heap<T>::swap(int t1, int t2)
{
   T temp = array[t1];
   array[t1] = array[t2];
   array[t2] = temp;
}

/*************************************************************
 * returns the value at the head of the rray
 ************************************************************/
template<class T>
T Heap<T>::getMax()
{
   return array[0];
}

/****************************************************
 * delete max
 * why does whe even have that lever?
 *******************************************/
template<class T>
void Heap<T>::deleteMax()
{
   array[0] = NULL;
}

/****************************************************
 * SORT
 * organizes the heavy lifting
 ***********************************************/
template<class T>
void Heap<T>::sort()
{
   while (num > 1)
   {
      swap(0, num);
      num--;
      percolateDown(0);
   }
   

   
   /*heapify(array, num);
   
   
   for(int i = num-1; i>=0; i--)
   {
      std::swap(array[0], array[i]);
      heapify(array, i);
      
      }*/
}

/************************************************************
 * HEAPIFY
 * called in the constructor is helps set up up
 *******************************************************/
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

/**************************************************************
 * PERCOLATE DOWN
 * enforces the heap based structure throughout the array
 ************************************************************/
template<class T>
void Heap<T>::percolateDown(int index)
{
   int indexLeft = index * 2 + 1;
   int indexRight = indexLeft + 1;
   
   if (indexRight <= num && array[indexRight] > array[indexLeft] && array[indexRight] > array[index])
   { 
      swap(index, indexRight);
      percolateDown(indexRight);
   }
   else if (indexLeft <= num && array[indexLeft] > array[index])
   {
      swap(index, indexLeft);
      percolateDown(indexLeft);
   }
/*   
   if (array[index] == array[0])
   {
      return;
   }
   
   else
   {
      std::swap(array[0], array[index]);
   }
   
   percolateDown(0);*/
}

/********************************************
 * SORT HEAP
 * allows the client to interface with the heap
 * object as if it were an ordinary algorithm
 ******************************************/
template <class T>
void sortHeap(T array[], int num)
{
   Heap<T> heap(array, num); // heapifies
   heap.sort(); //sortifies
}


#endif // SORT_HEAP_H
