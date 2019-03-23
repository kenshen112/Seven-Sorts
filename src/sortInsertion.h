/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
int binarySearch(T array[], T search, int iBegin, int iEnd);

template <class T>
void sortInsertion(T array[], int num)
{
   T valuePivot;
   int iShift;
   for(int iPivot = num - 2; iPivot > 0 || iPivot == 0; iPivot--)
   {
      valuePivot = array[iPivot];
      int iInsert = binarySearch(array, valuePivot, iPivot + 1, num - 1);
      iInsert--;

      for(iShift = iPivot; iShift < iInsert; iShift++)
      {
         array[iShift] = array[iShift + 1];
      }
      array[iShift] = valuePivot;
   }
}

template <class T>
int binarySearch(T array[], T search, int iBegin, int iEnd)
{
   int iMiddle = (iBegin + iEnd) / 2;

   if(iBegin > iEnd)
   {
      return iBegin;
   }
   if(array[iMiddle] == search)
   {
      return iMiddle;
   }
   if(search > array[iMiddle])
   {
      return binarySearch(array, search, iMiddle + 1, iEnd);
   }
   else
   {
      return binarySearch(array, search, iBegin, iMiddle - 1);
   }
}
#endif // SORT_INSERTION_H
