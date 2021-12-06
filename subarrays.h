/********************************************************************
* subarrays.h
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the interface for functions that 
*          involve dividing into subarrays and performing procedures
*          on those subarrays.
********************************************************************/

#ifndef SUBARRAYS 
#define SUBARRAYS

#include <vector>

#include "select_definitions.h"

/*
 * Based on the inputted subarray size, generates subarrays of 
 * that size and stores inputted elements into those subarrays
 * Input:
 *  - Reference to vector of elements; those elements are to 
 *    be split into subarrays.
 *  - Size of each subarray. Expected to be between 2 and the 
 *    number of elements
 *  - Reference to a vector of subarrays, each of which is a 
 *    vector. Elements get stored in these subarrays.
 */
void get_subarrays(std::vector<ElemType> &elems, int subarr_size,
                   std::vector<std::vector<ElemType>> &subarrays);

/* 
 * Sort each subarray in inputted list of subarrays
 * Input:
 *  - Reference to a vector of subarrays, each of which is a vector.
 *  - Size of each subarray
 */
void sort_subarrays(std::vector<std::vector<ElemType>> &subarrays, 
                    int subarr_size);

/* 
 * Retrieves the median of all median elements of subarrays.
 * Input:
 *  - A vector of sorted subarrays, each of which are vectors.
 *  - Size of each subarray
 * Output:
 *  - The median of all median elements of subarrays.
 *
 * Notes: 
 *  - Assumes there are at least 2 subarrays
 *  - The median of any incompletely filled subarrays (may be the last subarray)
 *    are not included when computing the median of medians.
 */
ElemType get_median_of_medians(std::vector<std::vector<ElemType>> 
                               &sorted_subarrays,
                               int subarr_size);

/* Testing function for contents of subarrays (not in selection algorithm) */
void test_subarrays(std::vector<std::vector<ElemType>> &subarrays);

#endif
