#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H


#include <stddef.h>

/**
 * @brief Search for target in arr linearly.
 * 
 * @param arr: Array that will be searched.
 * @param len: Length of the array.
 * @param target: The int that will be looked for.
 * 
 * @return index of the element inside arr if found. -1 if not found.
 */
int linear_search(int arr[], size_t len, int target);


#endif