/********************************************************************
* read_input.h
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains the interface for functions that 
*          read in the inputted multiset and selection parameters.
********************************************************************/

#ifndef READ_INPUT 
#define READ_INPUT 

#include <string>
#include <vector>

#include "select_definitions.h"

/* 
 * Reads in elements from multiset stored in inputted filename 
 * and stores them in inputted vector.
 * Input:
 *  - Name of file containing multiset. Should be the name of 
 *    a valid file in current directory.
 *  - Reference to a vector to store multiset elements in.
 *    Expected to be initially empty.
 */
void read_elems(std::string filename, std::vector<ElemType> &elems);

/* 
 * Prompt user for subarray size and rank of element to select, both 
 * important parameters for the selection algorithm.
 * Input:
 *  - Reference to vector containing inputted multiset of elements to 
 *    select.
 *  - Pointer to the rank of element to select.
 *  - Pointer to subarray size
 * 
 * Effects:
 *  - *rank and *subarr_size will be set to user inputted values.
 */
void prompt_input(std::vector<ElemType> &elems, int *rank, int *subarr_size);

/* Testing function for reading input (never called in selection) */
void test_read_elems(std::vector<ElemType> &elems);

#endif