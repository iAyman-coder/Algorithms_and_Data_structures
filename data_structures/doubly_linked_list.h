#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H


#include <stddef.h>    // This is included for the size_t data type.

/**
 * @brief Node of a doubly linked list.
 */
typedef struct dNode {
    char data;
    struct dNode *prev;
    struct dNode *next;
}dNode;

/**
 * @brief A functoin that forms a doubly linked list.
 * 
 * @param arr: Array of characters that data will be taken from.
 * @param len: Length of the array.
 * @param head_and_tail_ptrs: Array of pointers where the pointers to the head and tail nodes will be stored in.
 * 
 * @return Pointer to the head_and_tail_ptrs array.
 * 
 * @note In the head_and_tail_ptrs array, the head will be stored at index 0, and the tail will be stored at index 1.
 */
dNode **make_dlinked_list(char arr[], size_t len, dNode *head_and_tail_ptrs[2]);

/**
 * @brief A function that adds a new node to a doubly linked list at a specific position.
 * 
 * @param head_or_tail: Pointer to the head/tail node of the doubly linked list.
 * @param direction: String that tells the function to go forward or backward.
 * @param new_node: Pointer to the new node that will be inserted.
 * @param pos: An integer that represents the position where the new node will be inserted.
 * 
 * @return Pointer to the head node of the doubly linked list.
 * 
 * @note - The new node must be dynamically allocated via malloc() or calloc().
 * @note - Set the direction as "forward" if you passed the head pointer.
 * @note - Set the direction as "backward" if you passed the tail pointer.
 * @note - First position in the doubly linked list is zero, similar to indexes.
 */
dNode *insert_dnode(dNode *head_or_tail, char *direction, dNode *new_node, int pos);

/**
 * @brief A function that removes a node from a doubly linked list at a specific position.
 * 
 * @param head_or_tail: Pointer to the head/tail node of the doubly linked list.
 * @param direction: String that tells the function to go forward or backward.
 * @param pos: An integer that represents the position of the node that will be deleted.
 * 
 * @return Pointer to the head node of the doubly linked list.
 * 
 * @note - Set the direction as "forward" if you passed the head pointer.
 * @note - Set the direction as "backward" if you passed the tail pointer.
 * @note - First position in the doubly linked list is zero, similar to indexes.
 */
dNode *remove_dnode(dNode *head_or_tail, char *direction, int pos);

/**
 * @brief A function that searches a doubly linked list for a specific node that contains specific data.
 * 
 * @param head_or_tail: Pointer to the head/tail node of the doubly linked list.
 * @param direction: String that tells the function to go forward or backward.
 * @param target: Character that will be looked for in the nodes of the doubly linked list.
 * 
 * @return If target was found, pointer to the node that contains the character. If not, NULL.
 * 
 * @note - Set the direction as "forward" if you passed the head pointer.
 * @note - Set the direction as "backward" if you passed the tail pointer.
 */
dNode *search_dlinked_list(dNode *head_or_tail, char *direction, char target);

/**
 * @brief A function that deletes the entire doubly linked list from memory.
 * 
 * @param head_or_tail: Pointer to the head/tail node of the doubly linked list.
 * @param direction: String that tells the function to go forward or backward.
 * 
 * @return The new memory address for head, which is NULL.
 * 
 * @note - Set the direction as "forward" if you passed the head pointer.
 * @note - Set the direction as "backward" if you passed the tail pointer.
 */
dNode *delete_dlinked_list(dNode *head_or_tail, char *direction);


#endif