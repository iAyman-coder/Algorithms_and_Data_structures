#ifndef QUEUE_H
#define QUEUE_H


#include <stddef.h>    // Included for the size_t data type

/**
 * @brief Node of a queue data structure.
 */
typedef struct qNode {
    char data;
    struct qNode *next;
}qNode;

/**
 * @brief Form a queue data structure.
 * 
 * @param arr: Array of character that data will be taken from.
 * @param len: Length of the array.
 * @param front_and_rear_ptrs: Array of pointers where the pointers to the front and rear nodes will be stored in.
 * 
 * @return Pointer to the front_and_rear_ptrs array.
 * 
 * @note In the front_and_rear_ptrs array, front will be stored at index 0, and rear will be stored at index 1.
 */
qNode **make_queue (char arr[], size_t len, qNode *front_and_rear_ptrs[2]);

/**
 * @brief Enqueue (insert) a new node into the end of a queue data structure.
 * 
 * @param rear: Pointer to the rear node.
 * @param data: Character that will be put in the new node what will be enqueued.
 * 
 * @return Pointer to the new rear node.
 */
qNode *enqueue(qNode *rear, char data);

/**
 * @brief Dequeue (remove) the front node from a queue data strucure.
 * 
 * @param front: Pointer to the front node.
 * 
 * @return Pointer to the new front node.
 */
qNode *dequeue(qNode *front);

/**
 * @brief Calculate the length of a queue data structure.
 * 
 * @param front: Pointer to the front node.
 * 
 * @return Length of the queue as size_t.
 */
size_t len_queue(qNode *front);

/**
 * @brief Print the data of the front and rear node.
 * 
 * @param front: Pointer to the front node.
 * @param rear: Pointer to the rear node.
 * 
 * @return Nothing (void).
 */
void peek(qNode *front, qNode *rear);

/**
 * @brief Print the entire queue data structure.
 * 
 * @param front: Pointer ot the front node.
 * 
 * @return Nothing (void).
 */
void print_queue(qNode *front);

/**
 * @brief Delete the entire queue data structure.
 * 
 * @param front: Pointer to the front node.
 * 
 * @return NULL.
 */
qNode *delete_queue(qNode *front);


#endif