#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H


#include <stddef.h>    // This is included for the size_t data type.

/**
 * @brief Node for a singly linked list.
 */
typedef struct Node {
    char data;
    struct Node *next;
}Node;

/**
 * @brief Form a singly linked list.
 * 
 * @param arr: Array of characters that data will be taken from.
 * @param len: Length of the array.
 * 
 * @return Pointer to the head node of the formed singly linked list.
 */
Node *make_linked_list(char arr[], size_t len);

/**
 * @brief Add a new node to a singly linked list at a specific position.
 * 
 * @param head: Pointer to the head node.
 * @param list_len: Length of the singly linked list.
 * @param data: Character that will be put in the new node that will be inserted.
 * @param pos: An integer that represents the position where the new node will be inserted.
 * 
 * @return Pointer to the head node of the singly linked list.
 * 
 * @note - First position in the linked list is zero, similar to indexes.
 */
Node *insert_node(Node *head, size_t list_len, char data, int pos);

/**
 * @brief Remove a node from a singly linked list at a specific position.
 * 
 * @param head: Pointer to the head node.
 * @param list_len: Length of the singly linked list.
 * @param pos: An integer that represents the position of the node that will be deleted.
 * 
 * @return Pointer to the head node of the singly linked list.
 * 
 * @note First position in the linked list is zero, similar to indexes.
 */
Node *remove_node(Node *head, size_t list_len, int pos);

/**
 * @brief Search a singly linked list for the node that contains target.
 * 
 * @param head: Pointer to the head node.
 * @param target: Character that will be looked for in the nodes of the singly linked list.
 * 
 * @return If target was found, pointer to the node that contains the character. If not, NULL.
 */
Node *search_linked_list(Node *head, char target);

/**
 * @brief Print a singly linked list.
 * 
 * @param head: Pointer to the head node.
 * 
 * @return Nothing (void).
 */
void print_linked_list(Node *head);

/**
 * @brief Calculate the length of a singly linked list.
 * 
 * @param head: Pointer to the head node.
 * 
 * @return Length of singly linked list as size_t.
 */
size_t len_linked_list(Node *head);

/**
 * @brief Delete the entire singly linked list from memory.
 * 
 * @param head: Pointer to the head node.
 * 
 * @return NULL.
 */
Node *delete_linked_list(Node *head);


#endif