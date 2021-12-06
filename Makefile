#
# Makefile for Selection Program
#
# CS 160 Project
# Author: Randy Dang, November 2021
#

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 
LDFLAGS  = -g3

# This rule builds all executables
all: selection generate_inputs test_sort

# This rule builds the selection executable
selection: main.o partition.o sort.o read_input.o selection.o subarrays.o
	${CXX} ${LDFLAGS} -o $@ $^

# This rule builds executable for generating numbers 
generate_inputs: generate_inputs.o 
	${CXX} ${LDFLAGS} -o $@ $^

# This rule builds executable for testing sort functions
test_sort: test_sort.o sort.o partition.o
	${CXX} ${LDFLAGS} -o $@ $^

# This rule builds all necessary .o files 
%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<

# Removes executables, object code, and temporary files from directory 
clean:
	rm -rf generate_inputs input_ints.txt selection test_sort *.o *.dSYM

# Submit assignment 
provide:
	provide comp160 finalproj *

