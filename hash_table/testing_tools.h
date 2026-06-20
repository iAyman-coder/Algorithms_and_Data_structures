#ifndef DSCUSTOMTESTS_H
#define DSCUSTOMTESTS_H


#include <stdbool.h>    // Included for the bool data type.

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
 * @brief Test whether insertion/removal was successful.
 * 
 * @param actual_result: The boolean value returned by a function.
 * @param test_name: Custom name for the test to make each test unique and easy to identify.
 * 
 * @return Nothing (void).
 */
void test_boolean(bool actual_result, char *test_name);


#endif