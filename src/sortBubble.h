/***********************************************************************
 * Module:
 *    Week 11, Sort Bubble
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Bubble Sort
 ************************************************************************/
#include <algorithm> //for the std::swap function
#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

/*****************************************************
 * SORT BUBBLE
 * Perform the bubble sort
 ****************************************************/
template <class T>
void sortBubble(T array[], int num)
{
   bool swapped = false;

   for(int iPivot = num - 1; iPivot > 0; i--)
   {
      for(int iCheck = 0; iCheck < iPivot - 1; ++iCheck)
      {
         if(array[iCheck] > array[iCheck+1])
         {
            std::swap(iCheck, iCheck+1);
            swapped = true;
         }
      }
      if(!swapped)
      {
         return;
      }
   }
}


#endif // SORT_BUBBLE_H
