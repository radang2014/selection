/********************************************************************
* sort.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the implementation for the quick sort
*          algorithm and a brute force sorting method called 
*          selection sort.
********************************************************************/

#include <vector>
#include <cmath>

#include "sort.h"
#include "select_definitions.h"
#include "partition.h"

using namespace std;

/* 
 * Sorts the inputted vector using quick sort. 
 * Input:
 *  - Reference to vector of elements to sort
 * 
 * Notes:
 *  - This sorting algorithm could be done in place,
 *    but for ease of implementation, this was not 
 *    done.
 *  - The pivot to partition around is the first 
 *    element of the array, so it is advised to 
 *    avoid calling this on a nearly sorted or 
 *    nearly reverse sorted list.
 */
void quick_sort(vector<ElemType> &array)
{
    /* Already sorted if size is <= 1 */
    if (array.size() > 1) {
        /* Partition array around first element */
        int pivot = partition(array[0], array);

        /* Retrieve subarray before and after pivot */
        vector<ElemType> subarr_1;
        get_subset(array, 0, pivot - 1, subarr_1);

        vector<ElemType> subarr_2;
        get_subset(array, pivot + 1, array.size() - 1, subarr_2);

        /* Sort subarrays */
        quick_sort(subarr_1);
        quick_sort(subarr_2);

        /* Copy subarray contents back into larger array */
        for (unsigned i = 0; i < subarr_1.size(); i++) {
            array[i] = subarr_1[i];
        }

        for (unsigned i = 0; i < subarr_2.size(); i++) {
            array[pivot + 1 + i] = subarr_2[i];
        }
    }
}

/*
 * Sorts the inputted vector using selection sort.
 * Input:
 *  - Reference to vector containing elements to sort
 * 
 * Notes:
 *  - This sorting method should be avoided on inputs of a 
 *    large size.
 */
void brute_force_sort(vector<ElemType> &array)
{    
    vector<ElemType> aux;

    /* Add elements in ascending order to auxiliary array */
    while (not array.empty()) {
        int minIndex = -1;
        ElemType min = find_min(array, &minIndex);
        aux.push_back(min);
        array.erase(array.begin() + minIndex);
    }

    /* Copy sorted elements of auxiliary array back into array */
    int subarr_size = aux.size();
    for (int i = 0; i < subarr_size; i++) {
        array.push_back(aux[i]);
    }
}

/* 
 * Finds the minimum element and index of minimum element in a 
 * vector of elements.
 * Input:
 *  - Reference to vector of elements
 *  - Pointer to index of minimum element
 * Output:
 *  - The minimum element in inputted vector
 *  - If inputted vector is empty, will return the NIL value
 * 
 * Notes:
 *  - The initial value of *minIndex does not matter; after 
 *    this function is run, *minIndex will be changed to 
 *    the index of the minimum element in the inputted vector.
 */
ElemType find_min(vector<ElemType> &elems, int *minIndex)
{
    if (elems.empty()) {
        return NIL;
    }

    /* Iteratively find smallest element */
    ElemType min = elems[0];
    *minIndex = 0;
    for (unsigned i = 1; i < elems.size(); i++) {
        if (elems[i] < min) {
            min = elems[i];
            *minIndex = i;
        }
    }

    return min;
}