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
 * @note - In the head_and_tail_ptrs array, the head will be stored at index 0, and the tail will be stored at index 1.
 */
dNode **make_dlinked_list(char arr[], size_t len, dNode *head_and_tail_ptrs[2]);

/**
 * @brief A function that inserts new head to a doubly linked list.
 * 
 * @param head: Pointer to the head node.
 * @param data: Character tha will be put in the new node that will be inserted.
 * 
 * @return Pointer to the new head.
 * 
 * @note - To get correct results, You must pass the correct pointer to the head node.
 */
 dNode *insert_new_head(dNode *head, char data);

/**
 * @brief A function that inserts new tail to a doubly linked list.
 * 
 * @param tail: Pointer to tail node.
 * @param data: Character tha will be put in the new node that will be inserted.
 * 
 * @return Pointer to the new tail.
 * 
 * @note - To get correct results, You must pass the correct pointer to the tail node.
 */
dNode *insert_new_tail(dNode *tail, char data);

/**
 * @brief A function that inserts a new node between head and tail.
 * 
 * @param head: Pointer to the head node.
 * @param list_len: Length of the doubly linked list.
 * @param data: Character tha will be put in the new node that will be inserted.
 * @param pos: Integer representing the position where the new node will be inserted.
 * 
 * @return Pointer to the head node.
 * 
 * @note - To get correct results, You must pass the correct pointer to the head node.
 * @note - You can't change the head or tail of the doubly linked list with this function.
 * @note - First position in the doubly linked list is zero, similar to indexes.
 */
dNode *insert_dnode_after_head(dNode *head, size_t list_len, char data, int pos);

/**
 * @brief A function that inserts a new node between head and tail.
 * 
 * @param tail: Pointer to the tail node.
 * @param list_len: Length of the doubly linked list.
 * @param data: Character tha will be put in the new node that will be inserted.
 * @param pos: Integer representing the position where the new node will be inserted.
 * 
 * @return Pointer to the tail node.
 * 
 * @note - To get correct results, You must pass the correct pointer to the tail node.
 * @note - You can't change the head or tail of the doubly linked list with this function.
 * @note - First position in the doubly linked list is zero, similar to indexes.
 */
dNode *insert_dnode_before_tail(dNode *tail, size_t list_len, char data, int pos);

/**
 * @brief A function that removes the head of the doubly linked list.
 * 
 * @param head: Pointer to the head node.
 * 
 * @return Pointer to the new head node.
 * 
 * @note - To get correct results, You must pass the correct pointer to the head node.
 */
dNode *remove_head(dNode *head);

/**
 * @brief A function that removes the tail of the doubly linked list.
 * 
 * @param tail: Pointer to the tail node.
 * 
 * @return Pointer to the new tail node.
 * 
 * @note - To get correct results, You must pass the correct pointer to the tail node.
 */
dNode *remove_tail(dNode *tail);

/**
 * @brief A functoin that removes a node from in between head and tail.
 * 
 * @param head: Pointer to the head node.
 * @param list_len: Length of the doubly linked list.
 * @param pos: Integer representing the position of the node that will be removed.
 * 
 * @return Pointer to the head node.
 * 
 * @note - To get correct results, You must pass the correct pointer to the head node.
 * @note - You can't remove/change the head or tail of the doubly linked list with this function.
 * @note - First position in the doubly linked list is zero, similar to indexes.
 */
dNode *remove_dnode_after_head(dNode *head, size_t list_len, int pos);

/**
 * @brief A function that removes a node from in between head and tail.
 * 
 * @param tail: Pointer to the tail node.
 * @param list_len: Length of the doubly linked list.
 * @param pos: Integer representing the position of the node that will be removed.
 * 
 * @return Pointer to the tail node.
 * 
 * @note - To get correct results, You must pass the correct pointer to the tail node.
 * @note - You can't remove/change the head or tail of the doubly linked list with this function.
 * @note - First position in teh doubly linked list is zero, similar to indexes.
 */
dNode *remove_dnode_before_tail(dNode *tail, size_t list_len, int pos);

/**
 * @brief A function that searches for the node that contains target.
 * 
 * @param head: Pointer to the head node.
 * @param target: Character that will be searched for inside nodes.
 * 
 * @return Pointer to the node that contains target if it was found. If not, it returns NULL.
 * 
 * @note - To get correct results, You must pass the correct pointer to the head node.
 */
dNode *search_dlinked_list_forward(dNode *head, char target);

/**
 * @brief A function that searches for the node that contains target.
 * 
 * @param tail: Pointer to the tail node.
 * @param target: Character that will be searched for inside nodes.
 * 
 * @return Pointer to the node that contains target if it was found. If not, it returns NULL.
 * 
 * @note - To get correct results, You must pass the correct pointer to the tail node.
 */
dNode *search_dlinked_list_backward(dNode *tail, char target);

/**
 * @brief A function that prints a doubly linked list from left to right.
 * 
 * @param head: Pointer to the head node.
 * 
 * @return Nothing (void).
 * 
 * @note - To get correct results, You must pass the correct pointer to the head node.
 */
void print_dlinked_list_forward(dNode *head);

/**
 * @brief A function that prints a doubly linked list from right to left.
 * 
 * @param tail: Pointer to the tail node.
 * @param list_len: Length of the doubly linked list.
 * 
 * @return Nothing (void).
 * 
 * @note - To get correct results, You must pass the correct pointer to the tail node.
 */
void print_dlinked_list_backward(dNode *tail, size_t list_len);

/**
 * @brief A function that finds the length of a doubly linked list.
 * 
 * @param head_or_tail: Pointer to the head or tail node.
 * @param direction: String that tells the function to either traverse forward or backward.
 * 
 * @return Length of the doubly linked list as size_t.
 * 
 * @warning Not following the rules indicated in the note section will yield incorrect results.
 * 
 * @note - To get correct results, You must pass the correct pointer to the head or tail node.
 * @note - If you passed a pointer to the head node, direction must be "forward".
 * @note - If you passed a pointer to the tail node, direction must be "backward".
 */
size_t len_dlinked_list(dNode *head_or_tail, char *direction);

/**
 * @brief A function that deletes the entire doubly linked list from left to right.
 * 
 * @param head: Pointer to the head node.
 * 
 * @return NULL pointer.
 * 
 * @note - To get correct results, You must pass the correct pointer to the head node.
 */
dNode *delete_dlinked_list_forward(dNode *head);

/**
 * @brief A function that deletes the entire doubly linked list from right to left.
 * 
 * @param tail: Pointer to the tail node.
 * 
 * @return NULL pointer.
 * 
 * @note - To get correct results, You must pass the correct pointer to the tail node.
 */
dNode *delete_dlinked_list_backward(dNode *tail);


#endif