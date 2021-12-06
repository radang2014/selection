/********************************************************************
* read_input.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the implementation of functions that 
*          read in the inputted multiset and selection parameters.
********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "select_definitions.h"
#include "read_input.h"

using namespace std;

/* 
 * read_elems
 *
 * Reads in elements from multiset stored in inputted filename 
 * and stores them in inputted vector.
 * Input:
 *  - Name of file containing multiset. Should be the name of 
 *    a valid file in current directory.
 *  - Reference to a vector to store multiset elements in.
 *    Expected to be initially empty.
 *
 * Elements MUST be the type ElemType as defined in 
 * select_definitions.h. It is an unchecked runtime error
 * for elements in the file to be of a different type. Also,
 * there should be some amount of whitespace between each 
 * element in the file.
 */
void read_elems(string filename, vector<ElemType> &elems)
{
    /* Open file and check that it is successfully opened */
    ifstream infile(filename);
    if (infile.fail()) {
        cerr << "Could not open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    
    /* Read next element in file and add to vector */
    ElemType next;
    while (infile >> next) {
        elems.push_back(next);
    }

    infile.close();
}

/* 
 * Prompt user for subarray size and rank of element to select, both 
 * important parameters for the selection algorithm.
 * Input:
 *  - Reference to vector containing inputted multiset of elements to 
 *    select.
 *  - Pointer to the rank of element to select.
 *  - Pointer to subarray size
 * 
 * Notes:
 *  - The initial values of *rank and *subarr_size do not matter. When 
 *    this function is called, they will be changed to the values that 
 *    the user inputs.
 *  - User will input selection parameters via stdin.
 */
void prompt_input(vector<ElemType> &elems, int *rank, int *subarr_size)
{
    /* Prompt user for subarray size for selection algorithm */
    bool first_input = true;
    while (*subarr_size < 2 or *subarr_size > (int)elems.size()) {
        if (not first_input) {
            cout << "Subarray size must be at least 2 and no more than number " 
                 << "of elements." << endl;
        }
        cout << "What size subarrays? (please enter an integer)" << endl;
        cin >> *subarr_size;
        first_input = false;
    }

    /* Prompt user for the rank of the element to select */
    first_input = true;
    while (*rank < 1 or *rank > (int)elems.size()) {
        if (not first_input) {
            cout << "Rank must be within the range of the elements" << endl;
        }
        cout << "Select which rank element? (please enter an integer)" << endl;
        cin >> *rank;
        first_input = false;
    }
}

/* 
 * Test function that prints out all elements in inputted vector. Used to 
 * test that elements were read in correctly. This is not currently called
 * anywhere in the selection algorithm.
 */
void test_read_elems(vector<ElemType> &elems)
{
    for (int i = 0; i < (int)elems.size(); i++) {
        cout << elems[i] << endl;
    }
}