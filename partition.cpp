/********************************************************************
* main.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the implementation of partition and 
*          helper functions.
********************************************************************/

#include <vector>

#include "partition.h"

using namespace std;

/*
 * partition
 * 
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
 *
 * Notes: 
 *  - This assumes that the inputted pivot element is an element in 
 *    the vector; undefined behavior may result otherwise.
 *  - This algorithm is NOT in place for ease of implementation and 
 *    making code more understandable at a basic level, but this
 *    could easily be done in place.
 */
int partition(ElemType pivot, vector<ElemType> &elems)
{
    /* Stores elements less than, greater than, and equal to the pivot */
    vector<ElemType> less;
    vector<ElemType> greater;
    unsigned num_equal = 0;

    /* Split elements in different structures based on relationship to pivot */
    for (unsigned i = 0; i < elems.size(); i++) {
        if (elems[i] < pivot) {
            less.push_back(elems[i]);
        } else if (elems[i] > pivot) {
            greater.push_back(elems[i]);
        } else {
            num_equal++;
        }
    }

    /* Copy all elements less than pivot back into array */
    int index = 0;
    for (unsigned i = 0; i < less.size(); i++) {
        elems[index] = less[i];
        index++;
    }

    /* Copy all elements equal to pivot back into array */
    int pivot_start = index;
    for (unsigned i = 0; i < num_equal; i++) {
        elems[index] = pivot;
        index++;
    }

    /* Copy all elements greater than pivot back into array */
    for (unsigned i = 0; i < greater.size(); i++) {
        elems[index] = greater[i];
        index++;
    }

    return pivot_start + (num_equal / 2);
}

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
void get_subset(vector<ElemType> &elems, int minIndex, int maxIndex,
                vector<ElemType> &subset)
{
    for (int i = minIndex; i <= maxIndex; i++) {
        subset.push_back(elems[i]);
    }
}