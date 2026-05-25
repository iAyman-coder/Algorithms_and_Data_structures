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
 * @brief Sort arr from left to right by bringing the minimum value to the front of the array.
 * 
 * @param arr: Array that will be sorted.
 * @param len: Length of the array.
 * 
 * @return Pointer to the sorted array.
 */
int *selection_sort(int arr[], size_t len);


#endif