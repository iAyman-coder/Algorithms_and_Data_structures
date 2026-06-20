#ifndef DOUBLYLINKEDLISTTESTS_H
#define DOUBLYLINKEDLISTTESTS_H


#include <stddef.h>    // This is included for the size_t data type.
#include "doubly_linked_list.h"

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
 * @brief Test if a doubly linked list was formed correctly and as expected.
 * 
 * @param head: Pointer to the head node of the doubly linked list.
 * @param expected_result: Array of characters that contains the expected order and content of each node.
 * @param len: Length of the expected_result array.
 * @param test_name: Custom name for the test to make each test unique and easy to identify.
 * 
 * @return Nothing (void).
 */
void test_dlinked_list(dNode *head, char expected_result[], size_t len, char *test_name);


#endif