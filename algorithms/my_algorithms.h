#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H


#include <stddef.h>

/**
 * @brief Search for target in arr linearly.
 * 
 * @param arr: Array that will be searched.
 * @param len: Length of the array.
 * @param target: The integer that will be looked for.
 * 
 * @return index of target inside arr if found. -1 if not found.
 */
int linear_search(int arr[], size_t len, int target);

/**
 * @brief Search for target in arr in a way that cuts arr in halfs each time it searches the array.
 * 
 * @param arr: Array that will be searched.
 * @param len: Length of the array.
 * @param target: The integer that will be looked for.
 * 
 * @return index of target inside arr if found. -1 if not found.
 */
int binary_search(int arr[], size_t len, int target);

/**
 * @brief Sort arr from left to right by bringing the minimum values to the front of the array.
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * 
 * @return Pointer to the sorted array.
 */
int *selection_sort(int arr[], size_t len);

/**
 * @brief Sort arr from right to left by swapping adjacent elements and pushing maximum values to the end of the array.
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * 
 * @return Pointer to the sorted array.
 */
int *bubble_sort(int arr[], size_t len);

/**
 * @brief Sort arr by divide and conquer via recursion.
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * 
 * @return Pointer to the sorted array.
 */
int *merge_sort(int arr[], size_t len);

/**
 * @brief Search for target in arr by calculating its index with a mathematical formula.
 * 
 * @param arr: Array that will be searched.
 * @param len: Length of the array.
 * @param target: The integer that will be looked for.
 * 
 * @return Index of target inside arr if found. -1 if not found.
 */
int interpolation_search(int arr[], size_t len, int target);


#endif