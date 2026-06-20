#ifndef STACK_H
#define STACK_H


#include <stddef.h>    // Included for the size_t data type.

/**
 * @brief Node of a stack data structure
 */
typedef struct stNode {
    char data;
    struct stNode *next;
}stNode;

/**
 * @brief Form a stack data structure.
 * 
 * @param arr: Array of characters that data will be taken from.
 * @param len: Length of the array.
 * 
 * @return Pointer to the top node.
 */
stNode *make_stack(char arr[], size_t len);

/**
 * @brief Push (insert) a new node into the top of a stack data structure.
 * 
 * @param top: Pointer to the top node.
 * @param data: Character that will be put in the new node that will be pushed.
 * 
 * @return Pointer to the new top node.
 */
stNode *push(stNode *top, char data);

/**
 * @brief Pop (remove) the top node from a stack data structure.
 * 
 * @param top: Pointer to the top node.
 * 
 * @return Pointer to the new top node.
 */
stNode *pop(stNode *top);

/**
 * @brief Calculate the length of the stack data structure.
 * 
 * @param top: Pointer to the top node.
 * 
 * @return Length of the stack as size_t.
 */
size_t len_stack(stNode *top);

/**
 * @brief Print the data of the top node only.
 * 
 * @param top: Pointer to the top node.
 * 
 * @return Nothing (void).
 */
void peek(stNode *top);

/**
 * @brief Print the entire stack data structure.
 * 
 * @param top: Pointer to the top node.
 * 
 * @return Nothing (void).
 */
void print_stack(stNode *top);

/**
 * @brief Delete the entire stack data structure.
 * 
 * @param top: Pointer to the top node.
 * 
 * @return NULL.
 */
stNode *delete_stack(stNode *top);


#endif