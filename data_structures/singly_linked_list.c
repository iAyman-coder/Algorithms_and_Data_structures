#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
}Node;


Node *make_linked_list(char arr[], size_t len) {
    Node *head = NULL;

    Node *prev_node = NULL;

    for (int i = 0; i < len; i++) {
        Node *current_node = malloc(sizeof(Node));
        current_node->data = arr[i];
        current_node->next = NULL;

        if (prev_node != NULL) {
            prev_node->next = current_node;
        }

        if (i == 0) {
            head = current_node;
        }

        prev_node = current_node;
    }

    return head;
}

Node *insert_node(Node *head, Node *new_node, int pos) {
    if (pos == 0) {
        new_node->next = head;
        return new_node;
    }

    Node *prev_node = head;

    for (int i = 1; prev_node->next != NULL; i++) {
        if (i == pos) {
            break;
        }

        prev_node = prev_node->next;
    }

    Node *next_node = prev_node->next;

    new_node->next = next_node;
    prev_node->next = new_node;

    return head;
}

Node *remove_node(Node *head, int pos) {
    if (pos == 0) {
        Node *new_head = head->next;
        free(head);
        return new_head;
    }

    Node *current_node = head->next;
    Node *prev_node = head;

    int i = 1;
    for (i; current_node != NULL; i++) {
        if (i == pos) {
            break;
        }

        prev_node = current_node;
        current_node = current_node->next;
    }

    if (i != pos) {
        return head;
    }

    prev_node->next = current_node->next;
    free(current_node);

    return head;
}

Node *search_linked_list(Node *head, char target) {
    Node *current_node = head;

    while (current_node != NULL) {
        if (current_node->data == target) {
            return current_node;
        }

        current_node = current_node->next;
    }

    return NULL;
}

Node *delete_linked_list(Node *head) {
    Node *current_node = head;
    Node *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;

        free(current_node);

        current_node = next_node;
    }

    return NULL;
}

// TODO: make a function for printing singly linked list.


// TODO: make a function that returns the length of the linked list.