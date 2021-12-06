/********************************************************************
* generate_inputs.cpp
* Assignment: CS 160 Project
* Author: Randy Dang (rdang02)
* Date: 11/20/21
* Summary: This file contains code that generates random integers within
*          a certain range and outputs each number on a separate line
*          in a file.
*
* Input: - The name of the output file to store generated integers 
*          will be taken as the first argument on the command line.
*        - The number of random integers to generate will be inputted
*          through stdin (the program prompts the user)
********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

/* Bounds for random integers to generate */
const int RANGE_MIN = 0;
const int RANGE_MAX = 100;

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2) {
        cerr << "Usage: ./generate_inputs outputFile" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream outfile(argv[1]);
    
    /* Prompt for size of input */
    unsigned num_ints;
    cout << "How many integers?" << endl;
    cin >> num_ints;

    /* Output random integers within range to file */
    int range = RANGE_MAX - RANGE_MIN + 1;
    for (unsigned i = 0; i < num_ints; i++) {
        outfile << rand() % range + RANGE_MIN << endl;
    }

    outfile.close();
    return 0;
}
