/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Given a list of integers, write a function that returns the largest 
 *					sum of non-adjacent numbers. Numbers can be 0 or negative. For 
 *					example, [2, 4, 6, 8] should return 12, since we pick 4 and 8. 
 *					[5, 1, 1, 5] should return 10, since we pick 5 and 5.
 *
 *        Version:  1.0
 *        Created:  Saturday 24 February 2018 11:48:55  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Harit (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>

int main ( int argc, char *argv[] )
{
	int arr[] = {2,4,6,8};
	int size = sizeof(arr) / sizeof(arr[0]);
	int inc = arr[0], exc = 0, temp;
	for (int i=1; i<size; i++) {
		
		temp = exc > inc? exc: inc;

		inc = (exc + arr[i]);
		exc = temp;
	}
	std::cout << "Sum is: " << (inc > exc? inc : exc) << "\n";
	return EXIT_SUCCESS;
}
