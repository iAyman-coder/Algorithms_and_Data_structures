#include <stdio.h>
#include <stdlib.h>
#include "ds_custom_tests.h"
#include "../data_structures/singly_linked_list.h"

int main(void) {
    char arr[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    Node *head = make_linked_list(arr, 10);

    char correct1[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(head, correct1, 10, "Initial linked list");

    Node *new_node_first = malloc(sizeof(Node));
    new_node_first->data = 'S';
    new_node_first->next = NULL;

    head = insert_node(head, new_node_first, 0);

    char correct2[11] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(head, correct2, 11, "Inserting node in the first position");

    Node *new_node_middle = malloc(sizeof(Node));
    new_node_middle->data = 'G';
    new_node_middle->next = NULL;

    head = insert_node(head, new_node_middle, 7);

    char correct3[12] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't'};
    test_linked_list(head, correct3, 12, "Inserting node in a middle position");

    Node *new_node_last = malloc(sizeof(Node));
    new_node_last->data = 'W';
    new_node_last->next = NULL;

    head = insert_node(head, new_node_last, 12);

    char correct4[13] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't', 'W'};
    test_linked_list(head, correct4, 13, "Inserting node in the last position");

    head = remove_node(head, 0);

    char correct5[12] = {'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't', 'W'};
    test_linked_list(head, correct5, 12, "Removing the first node");

    head = remove_node(head, 6);

    char correct6[11] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't', 'W'};
    test_linked_list(head, correct6, 11, "Removing a middle node");

    head = remove_node(head, 10);

    char correct7[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(head, correct7, 10, "Removing the last node");

    Node *found_node_first = search_linked_list(head, 'l');

    char correct8[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(found_node_first, correct8, 10, "Search for first node");

    Node *found_node_middle = search_linked_list(head, 'k');

    char correct9[7] = {'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_linked_list(found_node_middle, correct9, 7, "Search for node in the middle");

    Node *found_node_last = search_linked_list(head, 't');

    char correct10[1] = {'t'};
    test_linked_list(found_node_last, correct10, 1, "Search for last node");

    head = delete_linked_list(head);

    if (head == NULL) {
        printf("\033[0;32m[Linked list was deleted successfully]\033[0;0m\n");
    }
    else {
        printf("\033[0;31m[Linked list was not deleted successfully]\033[0;0m\n");
    }

    return 0;
}