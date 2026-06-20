#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
}Node;


Node *make_linked_list(char arr[], size_t len) {
    if (len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't form a singly linked list. arr must contain one element at least.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    Node *head = NULL;

    Node *prev_node = NULL;

    for (int i = 0; i < len; i++) {
        // Allocating a node and populating it with data
        Node *current_node = malloc(sizeof(Node));
        current_node->data = arr[i];
        current_node->next = NULL;

        if (prev_node != NULL) {
            /*
                This conditional connects prev_node to current_node only
                if prev_node was not NULL.
            */
            prev_node->next = current_node;
        }

        if (i == 0) {
            head = current_node;
        }

        prev_node = current_node;
    }

    return head;
}

Node *insert_node(Node *head, size_t list_len, char data, int pos) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't insert new_node. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if(list_len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't insert new_node. (%i) list_len is invalid.\033[0;0m\n", list_len);
        exit(EXIT_FAILURE);
    }
    else if (pos < 0 || pos > list_len) {
        fprintf(stderr, "\033[0;31mError: Can't insert new_node. (%i) pos is invalid in a list with (%i) nodes.\033[0;0m\n", pos, list_len);
        exit(EXIT_FAILURE);
    }

    // Allocating a new node and populating it with data
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (pos == 0) {
        /*
            This conditional changes the head to be the new_node and
            returns new_node as the new head of the singly linked list. 
        */
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

    // Connecting node at position pos - 1 to the new node.
    prev_node->next = new_node;
    // Connecting node at position pos to the new node.
    new_node->next = next_node;

    return head;
}

Node *remove_node(Node *head, size_t list_len, int pos) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }
    else if(list_len <= 0) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. (%i) list_len is invalid.\033[0;0m\n", list_len);
        exit(EXIT_FAILURE);
    }
    else if (pos < 0 || pos > list_len - 1) {
        fprintf(stderr, "\033[0;31mError: Can't remove node. (%i) pos is invalid in a list with (%i) nodes.\033[0;0m\n", pos, list_len);
        exit(EXIT_FAILURE);
    }

    if (pos == 0) {
        /*
            This conditional removes head and makes the node after it
            the new head and return a pointer to that new head. 
        */
        Node *new_head = head->next;
        free(head);
        return new_head;
    }

    Node *current_node = head->next;
    Node *prev_node = head;

    for (int i = 1; current_node != NULL; i++) {
        if (i == pos) {
            break;
        }

        prev_node = current_node;
        current_node = current_node->next;
    }

    Node *next_node = current_node->next;

    // Connectin the node before current_node to the node after it.
    prev_node->next = next_node;

    free(current_node);

    return head;
}

Node *search_linked_list(Node *head, char target) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't search. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    Node *current_node = head;

    while (current_node != NULL) {
        if (current_node->data == target) {
            return current_node;
        }

        current_node = current_node->next;
    }

    return NULL;
}

void print_linked_list(Node *head) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't print singly linked list. head can't be NULL\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    Node *current_node = head;

    printf("Pos | Data\n");
    printf("----+-----\n");
    for (int i = 0; current_node != NULL; i++) {
        printf("%3i | %c\n", i, current_node->data);
        current_node = current_node->next;
    }
}

size_t len_linked_list(Node *head) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't find the length of the singly linked list. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    Node *current_node = head;

    size_t len = 0;

    while (current_node != NULL) {
        len++;

        current_node = current_node->next;
    }

    return len;
}

Node *delete_linked_list(Node *head) {
    if (head == NULL) {
        fprintf(stderr, "\033[0;31mError: Can't delete singly linked list. head can't be NULL.\033[0;0m\n");
        exit(EXIT_FAILURE);
    }

    Node *current_node = head;
    Node *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;

        free(current_node);

        current_node = next_node;
    }

    return NULL;
}
