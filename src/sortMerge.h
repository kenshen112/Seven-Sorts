/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    <author>
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/
#include <algorithm>
#include <iostream>
#include <utility>
#ifndef SORT_MERGE_H
#define SORT_MERGE_H

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void merge(T array[], T source1[], int size1, T source2[], int size2);


template <class T>
void sortMerge(T array[], int num)
{
   int numMerges = 0;
   int iBegin1 = 0;
   int iBegin2 = 0;
   int iEnd1 = 0;
   int iEnd2 = 0;
   int numIterations = 0;
   T source[num];
   T * destination;
    source[0] = array[0];

   do
   {
      while(iBegin1 < num)
      {
         numIterations++;
         
         for(iEnd1 = iBegin1 + 1; iEnd1 < num && !(source[iEnd1 - 1] > source[iEnd1]); iEnd1++)
         {
            iBegin2 = iEnd1 + 1;
         }
         
         for(iEnd2 = iBegin2 + 1; iEnd2 < num && !(source[iEnd2-1] > source[iEnd2]); iEnd2++)
            {
               if(iBegin2 < num)
               {
                  merge(destination,
                        source + iBegin1,
                        iEnd1 - iBegin1 + 1, source + iBegin2,
                        iEnd2 - iBegin2 + 1);
                  numMerges++;
               }
               iBegin1 = iEnd2 + 1;
            }
      }
      //swap pointers to source and destination
//      std::swap(source, destination);
   } while(numMerges > 1);

   if(array[0] == source[0])
   {
      return;
   }
   else
   {
      for(int i = 0; i < num -1; i++)
      {
         array[i] = source[i];
      }
   }
      
   
}
template <class T>
void merge(T destination[], T source1[], int size1, T source2[], int size2)
{
   int i1 = 0;
   int i2 = 0;

   for(int iDestination = 0; iDestination < (size1 + size2) || iDestination == (size1 + size2); iDestination++)
   {
      if(i1 < size1 && (i2 == size2 || source1[i1] < source2[i2]))
         destination[iDestination] = source1[i1++];
      else
         destination[iDestination] = source2[i2++];
   }

}

#endif // SORT_MERGE_H
