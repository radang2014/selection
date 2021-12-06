This repository contains the implementation of a linear time recursive selection 
algorithm. 

To compile the code, type “make selection” on the command line.
 • To run the code, type “./selection inputFile” on the command line,
   where inputFile is the name of a file containing the elements to select
   from.
    – Each element in inputFile should be separated by some amount of
      whitespace, and there should be at least two elements. Elements
      can be integers or decimal numbers.
    – The code will prompt for a subarray size. Select a subarray size
      between 2 and the number of elements in the input. 5 is a common
      choice.
    – The code will prompt for the rank of the element to be selected.
      Input a rank between 1 and the number of elements. For example, 
      to find the median, input approximately number of elements
      divided by 2.
    – The code will output the selected element and the time it took to
      run selection.
 • To generate random integers between 0 and 100, type “make generate inputs” 
   followed by “./generate inputs outputFile” where outputFile is the name 
   of the file to output random numbers to.


An example of commands to type to find the median of a random 51 numbers between 0
and 100:

make generate_inputs
./generate_inputs input_ints.txt
51
make selection
./selection input_ints.txt
5
26


Results of an experiment done where the selection algorithm is timed for various 
input and subarray sizes can be found in selection_data.xlsx

