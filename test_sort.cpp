/********************************************************************
* test_sort.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains tests for sorting implementations in 
*          sort.cpp.
********************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "sort.h"
#include "select_definitions.h"

/* Define hard-coded array of 100 random elements */
const int ARR_SIZE = 100;
const double ARR[ARR_SIZE] = {32, 32, 54, 12, 52, 56, 8, 30, 44, 94, 44, 39, 
65, 19, 51, 91, 1, 5, 89, 34, 25, 58, 20, 51, 38, 65, 30, 7, 20, 10, 51, 18, 
43, 71, 97, 61, 26, 5, 57, 70, 65, 0, 75, 29, 86, 93, 87, 87, 64, 75, 88, 89, 
100, 7, 40, 37, 38, 36, 44, 24, 46, 95, 43, 89, 32, 5, 15, 58, 77, 72, 95, 8, 
38, 69, 37, 24, 27, 90, 77, 92, 31, 30, 80, 30, 37, 86, 33, 76, 21, 77, 100, 
68, 37, 8, 22, 69, 81, 38, 94, 57};

using namespace std;

int main()
{
    /* Test selection sort */
    vector<ElemType> elements;
    for (unsigned i = 0; i < ARR_SIZE; i++) {
        elements.push_back(ARR[i]);
    }
    brute_force_sort(elements);
    for (unsigned i = 0; i < elements.size(); i++) {
        cout << elements[i] << " ";
    }
    cout << endl;

    /* Test quick sort */
    elements.clear();
    for (unsigned i = 0; i < ARR_SIZE; i++) {
        elements.push_back(ARR[i]);
    }
    quick_sort(elements);
    for (unsigned i = 0; i < elements.size(); i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}