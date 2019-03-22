/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H
#include <iostream>
#include <algorithm>

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T sArray[], int num)
{
	int iPivot = 0;
	int iLargest = 0;
	for (iPivot = num - 1; iPivot > 0; iPivot--)
	{
		iLargest = 0;

		for (int iCheck = 1; iCheck < iPivot; iCheck++)
		{		
			if (sArray[iLargest] < sArray[iCheck])
				iLargest = iCheck;

			if (sArray[iLargest] > sArray[iPivot])
				std::swap(sArray[iLargest], sArray[iPivot]);
		}	
	}
}


#endif // SORT_SELECTION_H
