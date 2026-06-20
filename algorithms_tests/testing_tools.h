#ifndef ALGORITHMSTESTS_H
#define ALGORITHMSTESTS_H


#include <stddef.h>    // This is included for the size_t data type.

/**
 * @brief Test an integer returned by a function.
 * 
 * @param actual_result: The integer returned by a function.
 * @param expected_result: The integer that is expected to be returned by the function.
 * @param test_name: Custom name for the test to make each test unique and easy to identify.
 * 
 * @return Nothing (void).
 */
void test_result(int actual_result, int expected_result, char *test_name);

/**
 * @brief Test an array returned by a function.
 * 
 * @param result_arr: The array returned by a function.
 * @param expected_arr: The array that is expected to be returned by the function.
 * @param len: Length of both result_arr and expected_arr (both arrays must be of the same length).
 * @param test_name: Custom name for the test to make each test unique and easy to identify.
 * 
 * @return Nothing (void). 
 */
void test_array(int result_arr[], int expected_arr[], size_t len, char *test_name);


#endif