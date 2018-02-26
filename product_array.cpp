/*
 * Given an array of integers, return a new array such that each element at index i of the new array is the product of
 * all the numbers in the original array except the one at i. Solve it without using division and in O(n) time.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
 * If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 */
#include <iostream>

void printArray(const int* arr, int size) {
	std::cout << "Printing array: ";
	for (int i=0; i<size; i++) {
		std::cout<< arr[i] << " ";
		
	}
	std::cout << "\n";
	return;
}
int* processArray(const int* arr, int size) {
	int * ans = new int(size);
	ans[0] = arr[0];
	for (int i=1; i<size; i++) {
		ans[i] = ans[i-1]*arr[i];
	}
	int rightProduct = 1;
	for (int j = size-1; j>0; j--) {
		ans[j] = ans[j-1]*rightProduct;
		rightProduct *= arr[j];
	}
	ans[0] = rightProduct;
	return ans;
}
int main() {
   int arr[] = {3,2,1};
   int * res = processArray(arr, 3);
   printArray(res,3);
   return 0;

}
