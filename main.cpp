/********************************************************************
* main.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file is the driver file for the selection program,
*          which inputs a multiset of numbers and finds the element
*          at a specified rank.
*
* Input: - The name of the file containing the multiset of numbers 
*          (all must be able to be represented as a C++ double) is 
*          the first command line argument.
*        - The size of the subarrays for the selection algorithm will
*          be prompted when program runs and is inputted through 
*          stdin. Most examples of selection use 5. Should be a number
*          between 2 and the size of the multiset.
*        - The rank of the element being selected (should be between
*          1 and the size of the multiset).
*
* Output: - The element at inputted rank.
*         - The time, in microseconds, it took for the selection 
*           operation to execute.
*
* Notes: - The selection algorithm will not work for an input that 
*          contains fewer than 2 elements due to the restrictions on
*          the subarray size.
********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "select_definitions.h"
#include "read_input.h"
#include "selection.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2) {
        cerr << "Usage: ./selection arrFile" << endl;
        exit(EXIT_FAILURE);
    }

    /* Stores the set of elements to select from */
    vector<ElemType> elems;
    read_elems(argv[1], elems);

    /* Prompt user for parameters of selection algorithm */
    int rank = -1, subarr_size = 0;
    prompt_input(elems, &rank, &subarr_size);

    /* Invoke selection algorithm, determine runtime, and output value */
    auto start = chrono::high_resolution_clock::now();
    ElemType selected = select(rank, subarr_size, elems);
    auto stop = chrono::high_resolution_clock::now();
    cout << "The element with rank " << rank << " using subarrays of size " 
         << subarr_size << " is " << selected << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "This invocation of selection took " << duration.count() 
         << " microseconds." << endl;

    return 0;
}
