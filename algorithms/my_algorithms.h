#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H


#include <stddef.h>   // This is included for the size_t data type.

/**
 * @brief Search an array for target linearly.
 * 
 * Best case: O(1) | Worst case: O(n)
 * 
 * @param arr: Array that will be searched.
 * @param len: Length of the array.
 * @param target: The integer that will be looked for.
 * 
 * @return Index of target inside arr if found. -1 if not found.
 */
int linear_search(int arr[], size_t len, int target);

/**
 * @brief Search an array for target by examining the middle element in each iteration.
 * 
 * Best case: O(1) | Worst case: O(log n)
 * 
 * @param arr: Array that will be searched.
 * @param len: Length of the array.
 * @param target: The integer that will be looked for.
 * 
 * @return Index of target inside arr if found. -1 if not found.
 */
int binary_search(int arr[], size_t len, int target);

/**
 * @brief Sort an array from left to right by bringing smaller elements into the front of the array.
 * 
 * Best and Worst case: O(n^2)
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * 
 * @return Pointer to the sorted array.
 */
int *selection_sort(int arr[], size_t len);

/**
 * @brief Sort an array from right to left by pushing larger elements to the end of the array.
 * 
 * Best case: O(n) | Worst case: O(n^2)
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * 
 * @return Pointer to the sorted array.
 */
int *bubble_sort(int arr[], size_t len);

/**
 * @brief Sort an array by divide and conquer via recursion.
 * 
 * Best and Worst case: O(n log n)
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * 
 * @return Pointer to the sorted array.
 */
int *merge_sort(int arr[], size_t len);

/**
 * @brief Search an array for target by estimating its position via a mathematical formula in each iteration.
 * 
 * Best case: O(1) | Average case: O(log(log n)) | Worst case: O(n)
 * 
 * @param arr: Array that will be searched.
 * @param len: Length of the array.
 * @param target: The integer that will be looked for.
 * 
 * @return Index of target inside arr if found. -1 if not found.
 */
int interpolation_search(int arr[], size_t len, int target);

/**
 * @brief Sort an array by divide and conquer via choosing a pivot and recursion.
 * 
 * Best case: O(n log n) | Worst case: O(n^2)
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * @param start_index: Index of the first element in the array.
 * @param end_index: Index of the last element in the array.
 * 
 * @return Pointer to the sorted array.
 */
int *quick_sort(int arr[], size_t len, int start_index, int end_index);

/**
 * @brief Sort an array by swapping elements to the right that are larger than the element we are pointing to
 * in this iteration.
 * 
 * Best case: O(n) | Worst case: O(n^2)
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * 
 * @return Pointer to the sorted array.
 */
int *insertion_sort(int arr[], size_t len);


#endif