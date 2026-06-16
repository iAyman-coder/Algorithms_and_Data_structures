#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    char data;
    struct Node *next;
}Node;


Node *make_linked_list(char arr[], size_t len) {
    if (len <= 0) {
        printf("Can't form a singly linked list.\n");
        printf("len of (%i) is invalid.\n", len);
    }

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

Node *insert_node(Node *head, size_t list_len, Node *new_node, int pos) {
    if (head == NULL) {
        printf("Node was not inserted.\n");
        printf("head must not be NULL.\n");
        return head;
    }
    else if(list_len <= 0) {
        printf("Node was not inserted.\n");
        printf("list_len of (%i) is invalid.\n", list_len);
        return head;
    }
    else if (new_node == NULL) {
        printf("Node was not inserted.\n");
        printf("new_node must not be NULL.\n");
        return head;
    }
    else if (pos < 0 || pos > list_len) {
        printf("Node was not inserted.\n");
        printf("pos of (%i) is invalid.\n", pos);
        return head;
    }

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

Node *remove_node(Node *head, size_t list_len, int pos) {
    if (head == NULL) {
        printf("Node was not removed.\n");
        printf("head must not be NULL.\n");
        return head;
    }
    else if(list_len <= 0) {
        printf("Node was not removed.\n");
        printf("list_len of (%i) is invalid.\n", list_len);
        return head;
    }
    else if (pos < 0 || pos > list_len - 1) {
        printf("Node was not removed.\n");
        printf("pos of (%i) is invalid.\n", pos);
        return head;
    }

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

    // todo: change this to be current_node == NULL
    if (i != pos) {
        return head;
    }

    prev_node->next = current_node->next;
    free(current_node);

    return head;
}

Node *search_linked_list(Node *head, char target) {
    if (head == NULL) {
        printf("No search was performed.\n");
        printf("head must not be NULL.\n");
        return NULL;
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

Node *delete_linked_list(Node *head) {
    if (head == NULL) {
        printf("Singly linked list was not deleted.\n");
        printf("head must not be NULL.\n");
        return NULL;
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

void print_linked_list(Node *head) {
    if (head == NULL) {
        printf("Can't print singly linked list.\n");
        printf("head must not be NULL.\n");
        return;
    }

    Node *current_node = head;

    printf("Pos | Data\n");
    for (int i = 0; current_node != NULL; i++) {
        printf("%i | %c\n", i, current_node->data);
        current_node = current_node->next;
    }
}

size_t len_linked_list(Node *head) {
    if (head == NULL) {
        printf("Can't find the length of singly linked list.\n");
        printf("head must not be NULL.\n");
        return 0;
    }

    Node *current_node = head;

    size_t len = 0;

    while (current_node != NULL) {
        len++;

        current_node = current_node->next;
    }

    return len;
}