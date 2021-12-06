/********************************************************************
* main.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the interface for partition and 
*          helper functions.
********************************************************************/

#ifndef PARTITION 
#define PARTITION 

#include <vector>

#include "select_definitions.h"

/* 
 * Partitions elements in inputted vector around the pivot, i.e. 
 * rearranges elements such that all elements less than the pivot 
 * are to the left of the pivot and all elements greater than the 
 * pivot are to the right of the pivot.
 * Input:
 *  - The pivot element, or the element to partition around.
 *  - Reference to element vector where elements will be rearranged
 *    as described.
 * Output: 
 *  - Index of element where the pivot element is at the end of the 
 *    algorithm. If there are duplicates, return approximately the 
 *    middle index of those duplicates.
 */
int partition(ElemType pivot, std::vector<ElemType> &elems);

/*
 * Retrieves a contiguous subarray from the elements vector and 
 * stores resulting elements in the subset vector.
 * Input:
 *  - Reference to element vector to retrieve subarray from.
 *  - Index of first element in subarray to retrieve.
 *  - Index of last element in subarray to retrieve.
 *  - Reference to subarray vector to store subarray in.
 *
 * Notes:
 *  - minIndex has to be >= 0 and maxIndex has to be < elems.size()
 *  - subset is expected to be initially empty.
 */
void get_subset(std::vector<ElemType> &elems, int minIndex, int maxIndex, 
                std::vector<ElemType> &subset);

#endif