/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Given an integer k and a string s, find the length of the longest 
 *					substring that contains at most k distinct characters. For example,
 *					given s = "bbcdddca" and k = 2, the longest substring with k distinct
 *					characters is "cdddc", so your function should return 5,
 *
 *        Version:  1.0
 *        Created:  Sunday 25 February 2018 04:25:11  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Harit (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  lengthOfLongestSubstringWithKDistinctCharacters
 *  Description:  
 * =====================================================================================
 */
int lengthOfLongestSubstringWithKDistinctCharacters (string s, int k)
{
	int leftIndex = 0,
		rightIndex = 0,
		windowBegin = 0,
		windowEnd = 0,
		visited[26]; 

	for (int i=0; i<26; i++) {
		visited[i] = -1;
	}

	// a windowing approach
	for (; rightIndex < s.size(); rightIndex++) {
		
	}

	return rightIndex - leftIndex;
}		/* -----  end of function lengthOfLongestSubstringWithKDistinctCharacters  ----- */


int main ( int argc, char *argv[] )
{
	string s = "abcba";
	int k = 2;
	cout << "Max length: " << lengthOfLongestSubstringWithKDistinctCharacters(s,k);
	return EXIT_SUCCESS;
}
