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
 * @brief A function that forms a linked list.
 * 
 * @param arr: Array of characters that data will be taken from.
 * @param len: Length of the array.
 * 
 * @return Pointer to the head node of the linked list.
 */
Node *make_linked_list(char arr[], size_t len);

/**
 * @brief A function that adds a new node to a linked list at a specific position.
 * 
 * @param head: Pointer to the head node of the linked list.
 * @param new_node: Pointer to the new node that will be inserted.
 * @param pos: An integer that represents the position where the new node will be inserted.
 * 
 * @return Pointer to the head node of the linked list.
 * 
 * @note - The new node must be dynamically allocated via malloc() or calloc().
 * @note - First position in the linked list is zero, similar to indexes.
 */
Node *insert_node(Node *head, Node *new_node, int pos);

/**
 * @brief A function that removes a node from a linked list at a specific position.
 * 
 * @param head: Pointer to the head node of the linked list.
 * @param pos: An integer that represents the position of the node that will be deleted.
 * 
 * @return Pointer to the head node of the linked list.
 * 
 * @note First position in the linked list is zero, similar to indexes.
 */
Node *remove_node(Node *head, int pos);

/**
 * @brief A function that searches a linked list for a specific node that contains specific data.
 * 
 * @param head: Pointer to the head node of the linked list.
 * @param target: Character that will be looked for in the nodes of the linked list.
 * 
 * @return If target was found, pointer to the node that contains the character. If not, NULL.
 */
Node *search_linked_list(Node *head, char target);

/**
 * @brief A function that deletes the entire linked list from memory.
 * 
 * @param head: Pointer to the head node of the linked list.
 * 
 * @return The new memory address for head, which is NULL.
 */
Node *delete_linked_list(Node *head);

/**
 * @brief A function that prints a linked list.
 * 
 * @param head: Pointer to the head node.
 * 
 * @return Nothing (void).
 */
void print_linked_list(Node *head);

/**
 * @brief A function that returns the length of a linked list.
 * 
 * @param head: Pointer to the head node.
 * 
 * @return Length of linked list as size_t.
 */
size_t len_linked_list(Node *head);


#endif