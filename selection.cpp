/********************************************************************
* selection.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the implementation of the selection 
*          algorithm, both the brute force way (for small input 
*          sizes) and the recursive way (for larger input sizes)
********************************************************************/

#include <vector>

#include "select_definitions.h"
#include "selection.h"
#include "subarrays.h"
#include "partition.h"
#include "sort.h"

using namespace std;

/* 
 * Recursive algorithm that selects the element in a vector that is 
 * at the inputted rank.
 * Input:
 *  - Rank of element to be selected. Expected to be between 1 and 
 *    the number of elements.
 *  - Size of subarrays for selection algorithm. 5 is commonly 
 *    used.
 *  - Reference to vector of elements to select from
 * Output:
 *  - Element at the inputted rank in the vector of elements
 * 
 * Notes:
 *  - The inputted rank is ONE indexed, so it is one more than what 
 *    would be the index of the element in a sorted array.
 *  - This algorithm calls the brute force select algorithm on small
 *    input sizes, currently set to input sizes < 54. This functions 
 *    as the "base case".
 *  - There are aspects of this algorithm that could be done in place,
 *    but for ease of implementation, space was not considered.
 */
ElemType select(int rank, int subarr_size, vector<ElemType> &elems)
{    
    /* Brute force if few elements */
    if (elems.size() < 54 or (int)elems.size() <= subarr_size) {
        return brute_force_select(rank, elems);
    }
    
    /* Break up input into subarrays specified by subarray size */
    vector<vector<ElemType>> subarrays;
    get_subarrays(elems, subarr_size, subarrays);

    /* Sort subarrays */
    sort_subarrays(subarrays, subarr_size);

    /* Find median of medians and partition around that */
    ElemType median_of_medians = get_median_of_medians(subarrays, subarr_size);
    int m_of_m_rank = partition(median_of_medians, elems) + 1;

    /* Select in subarray containing element being searched for */
    vector<ElemType> subset;
    if (rank < m_of_m_rank) {
        get_subset(elems, 0, m_of_m_rank - 2, subset);
        return select(rank, subarr_size, subset);
    } else if (rank > m_of_m_rank) {
        get_subset(elems, m_of_m_rank, elems.size() - 1, subset);
        return select(rank - m_of_m_rank, subarr_size, subset);
    }
    return median_of_medians;
}

/*
 * Selects the element in a vector at the inputted rank by brute force.
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
ElemType brute_force_select(int rank, vector<ElemType> &elems)
{    
    brute_force_sort(elems);
    return elems[rank - 1];
}
