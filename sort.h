/********************************************************************
* sort.h
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the interface for the quick sort
*          algorithm and a brute force sorting method called 
*          selection sort.
********************************************************************/

#ifndef QUICK_SORT 
#define QUICK_SORT

#include <vector>

#include "select_definitions.h"

/* 
 * Sorts the inputted vector using quick sort. 
 * Input:
 *  - Reference to vector of elements to sort
 * 
 * Notes:
 *  - It is advised to avoid calling this on a nearly sorted or 
 *    nearly reverse sorted list.
 */
void quick_sort(std::vector<ElemType> &array);

/*
 * Sorts the inputted vector using selection sort.
 * Input:
 *  - Reference to vector containing elements to sort
 * 
 * Notes:
 *  - This sorting method should be avoided on inputs of a 
 *    large size.
 */
void brute_force_sort(std::vector<ElemType> &array);

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
ElemType find_min(std::vector<ElemType> &elems, int *minIndex);

#endif