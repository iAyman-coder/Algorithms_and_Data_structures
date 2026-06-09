#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
}Node;


Node *make_linked_list(char arr[], size_t len) {
    Node *prev_node = NULL;
    Node *head = NULL;

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
    Node *next_node = NULL;

    int i = 1;
    while (prev_node->next != NULL) {
        if (i == pos) {
            break;
        }

        prev_node = prev_node->next;

        i++;
    }

    next_node = prev_node->next;
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

    Node *current_node = head;
    Node *prev_node = NULL;

    int i = 1;
    while (current_node->next != NULL) {
        prev_node = current_node;
        current_node = current_node->next;

        if (i == pos) {
            break;
        }
        
        i++;
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

    while (1) {
        if (current_node->data == target) {
            return current_node;
        }
        else if (current_node->next == NULL) {
            return NULL;
        }
        else {
            current_node = current_node->next;
        }
    }
}

Node *delete_linked_list(Node *head) {
    Node *current_node = head;
    Node *next_node = current_node->next;

    while (1) {
        free(current_node);
        current_node = next_node;

        if (current_node == NULL) {
            break;
        }

        next_node = current_node->next;
    }

    return NULL;
}