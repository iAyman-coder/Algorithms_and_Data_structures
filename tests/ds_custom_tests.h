#ifndef DSCUSTOMTESTS_H
#define DSCUSTOMTESTS_H


#include <stddef.h>
#include "../data_structures/singly_linked_list.h"

/**
 * @brief A function that tests if a linked list was formed correctly and as expected.
 * 
 * @param head: Pointer to the head node of the linked list.
 * @param expected_result: Array of characters that contains the expected order and content of each node.
 * @param len: Length of the expected_result array.
 * @param test_name: Custom name for the test to make each test unique and easy to identify.
 * 
 * @return Nothing (void).
 */
void test_linked_list(Node *head, char expected_result[], size_t len, char *test_name);


#endif