/***********************************************************************
 * Module:
 *    Week 11, Sort Quick
 *    Brother Helfrich, CS 235
 * Author:
 *    <author>
 * Summary:
 *    This program will implement the Quick Sort
 ************************************************************************/

#ifndef SORT_QUICK_H
#define SORT_QUICK_H
#include <iostream>
#include <algorithm>
/*****************************************************
 * SORT QUICK
 * Perform the quick sort
 ****************************************************/
template <class T>
void sortQuick(T array[], int num)
{
	int iDown;
	int iEnd;
	int iUp;	
	T pivotValue; // element to be placed

	if (num < 1)
	{
		return;
	}
	
	iDown = iEnd = num - 1;
	iUp = 0;

	pivotValue = array[iEnd / 2];

	std::cerr << "Pivot: " << pivotValue << std::endl;

	std::cerr << "iDown: " << iDown << std::endl;
	std::cerr << "iEnd: " << iEnd << std::endl;
	std::cerr << "iUp: " << iUp << std::endl;

	std::cerr << "Array: " << array[iUp] << std::endl;


	while (iUp < iDown)
	{
		while (iUp <= iEnd && pivotValue > array[iUp])
		{
			std::cerr << "While" << std::endl;
			iUp++;				

			while (iDown > 0 && array[iDown] > pivotValue)			
			{
				iDown--;	
			
				if (iUp < iDown)	
				{
					std::swap(array[iUp++], array[iDown--]);
				}
			}
		}	
	}

	sortQuick(array, iUp);
	sortQuick(array + iUp, iEnd - iUp + 1);

}


#endif // SORT_QUICK_H
