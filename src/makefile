###############################################################
# Program:
#     Assignment 11, Sorts
#     Brother Kirby, CS235
# Author:
#        Ken Smith
#        Jessica Smith
#        Tim O'Barr
# Summary:
#     implaments a series of sorting algorithms for their use and comparison
#  Time:
#     Group:
#     solo:
#      Ken: 3 hours
#      Jessica: 
#      Tim: 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment11.o
	g++ -o a.out assignment11.o -g -std=c++11
	tar -cf assignment11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment11.o     : the driver program
##############################################################
assignment11.o: assignment11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h bst.h queue.h
	g++ -c assignment11.cpp -g -std=c++11

