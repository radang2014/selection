/********************************************************************
* subarrays.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the implementation for functions that 
*          involve dividing into subarrays and performing procedures
*          on those subarrays.
********************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

#include "select_definitions.h"
#include "subarrays.h"
#include "sort.h"
#include "selection.h"

using namespace std;

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
void get_subarrays(vector<ElemType> &elems, int subarr_size, 
                   vector<vector<ElemType>> &subarrays)
{
    int num_subarrays = ceil((double)elems.size() / subarr_size);
    for (int i = 0; i < num_subarrays; i++) {
        vector<ElemType> subarray;
        subarrays.push_back(subarray);
        
        for (int j = 0; j < subarr_size; j++) {
            unsigned index = i * subarr_size + j;
            if (index < elems.size()) {
                subarrays[i].push_back(elems[index]);
            } else {
                /* Fill in extra space with NIL value as necessary */
                subarrays[i].push_back(NIL);
            }
        }
    }
}

/* 
 * Sort each subarray in inputted list of subarrays
 * Input:
 *  - Reference to a vector of subarrays, each of which is a vector.
 *  - Size of each subarray
 * 
 * Notes:
 *  - Only sorts elements within subarrays; does NOT change the order of the 
 *    subarrays themselves.
 *  - Inputted subarray size is used to determine sorting method.
 */
void sort_subarrays(vector<vector<ElemType>> &subarrays, int subarr_size)
{
    /* Use brute force (selection sort) for small sizes, quick sort otherwise */
    for (unsigned i = 0; i < subarrays.size(); i++) {
        if (subarr_size <= 20) {
            brute_force_sort(subarrays[i]);
        } else {
            quick_sort(subarrays[i]);
        }
    }
}

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
ElemType get_median_of_medians(vector<vector<ElemType>> &sorted_subarrays, 
                               int subarr_size)
{
    /* Store all medians of sorted subarrays in array of medians */
    vector<ElemType> medians;
    for (unsigned i = 0; i < sorted_subarrays.size(); i++) {
        int subarr_size = sorted_subarrays[i].size();
        if (not isnan(sorted_subarrays[i][subarr_size - 1])) {
            medians.push_back(sorted_subarrays[i][subarr_size / 2]);
        }
    }

    /* Return median of the vector of medians */
    return select(medians.size() / 2 + 1, subarr_size, medians);
}

/* 
 * A test function that prints out all valid numbers in subarrays in 
 * order, testing that subarrays stored elements correctly. This is 
 * not called anywhere in the selection algorithm.
 */
void test_subarrays(vector<vector<ElemType>> &subarrays)
{
    for (unsigned i = 0; i < subarrays.size(); i++) {
        for (unsigned j = 0; j < subarrays[i].size(); j++) {
            if (not isnan(subarrays[i][j] != NIL)) {
                cout << subarrays[i][j] << endl;
            }
        }
    }
}