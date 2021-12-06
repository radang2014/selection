/********************************************************************
* selection.h
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the interface for the selection 
*          algorithm, both the brute force way (for small input 
*          sizes) and the recursive way (for larger input sizes)
********************************************************************/

#ifndef SELECTION 
#define SELECTION 

#include <vector>

#include "select_definitions.h"

/* 
 * Selects the element in a vector that is at the inputted rank.
 * Input:
 *  - Rank of element to be selected. Expected to be between 1 and 
 *    the number of elements.
 *  - Size of subarrays for selection algorithm. 5 is commonly 
 *    used.
 *  - Reference to vector of elements to select from
 * Output:
 *  - Element at the inputted rank in the vector of elements
 */
ElemType select(int rank, int subarr_size, std::vector<ElemType> &elems);

/*
 * Selects the element in a vector at the inputted rank by brute force.
 * Only recommended for small element sizes.
 * Input: 
 *  - Rank of element to be selected. Expected to be between 1 and 
 *    the number of elements.
 *  - Reference to vector of elements to select from
 * Output:
 *  - Element at the inputted rank in the vector of elements
 * 
 * Notes:
 *  - Assumes rank is in range 1 <= rank <= elems.size()
 */
ElemType brute_force_select(int rank, std::vector<ElemType> &elems);

#endif