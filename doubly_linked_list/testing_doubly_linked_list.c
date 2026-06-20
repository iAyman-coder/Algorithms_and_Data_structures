#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "testing_tools.h"

void testing_forward(void) {
    dNode *head_and_tail[2];

    char arr[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    make_dlinked_list(arr, 10, head_and_tail);

    dNode *head = head_and_tail[0];

    char correct1[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct1, 10, "Initial linked list");

    size_t list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 10, "Length: 10 (initial)");

    printf("\n");
    printf("============Initial Doubly Linked List============\n");
    print_dlinked_list_forward(head);
    printf("==================================================\n");
    printf("\n");

    head = insert_new_head(head, 'S');

    char correct2[11] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct2, 11, "Inserting new head");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 11, "Length: 11 nodes (insertion)");

    head = insert_dnode_after_head(head, list_len, 'G', 7);

    char correct3[12] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct3, 12, "Inserting node in a middle position");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 12, "Length: 12 nodes (insertion)");

    head = insert_dnode_after_head(head, list_len, 'W', 11);

    char correct4[13] = {'S', 'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 'W', 't'};
    test_dlinked_list(head, correct4, 13, "Inserting node before tail node");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 13, "Length: 13 nodes (insertion)");

    printf("\n");
    printf("============Modified Doubly Linked List============\n");
    print_dlinked_list_forward(head);
    printf("==================================================\n");
    printf("\n");

    head = remove_head(head);

    char correct5[12] = {'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 'W', 't'};
    test_dlinked_list(head, correct5, 12, "Removing head");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 12, "Length: 12 nodes (removal)");

    head = remove_dnode_after_head(head, list_len, 6);

    char correct6[11] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 'W', 't'};
    test_dlinked_list(head, correct6, 11, "Removing a middle node");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 11, "Length: 11 nodes (removal)");

    head = remove_dnode_after_head(head, list_len, 9);

    char correct7[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct7, 10, "Removing the node before tail");

    list_len = len_dlinked_list(head, "forward");
    test_result(list_len, 10, "Length: 10 nodes (removal)");

    printf("\n");
    printf("============Doubly Linked List After Removing Nodes============\n");
    print_dlinked_list_forward(head);
    printf("==================================================\n");
    printf("\n");

    dNode *found_node_first = search_dlinked_list_forward(head, 'l');

    char correct8[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(found_node_first, correct8, 10, "Search for first node");

    dNode *found_node_middle = search_dlinked_list_forward(head, 'k');

    char correct9[7] = {'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(found_node_middle, correct9, 7, "Search for node in the middle");

    dNode *found_node_last = search_dlinked_list_forward(head, 't');

    char correct10[1] = {'t'};
    test_dlinked_list(found_node_last, correct10, 1, "Search for last node");

    head = delete_dlinked_list_forward(head);

    if (head == NULL) {
        printf("\033[0;32m[Linked list was deleted successfully]\033[0;0m\n");
    }
    else {
        printf("\033[0;31m[Linked list was not deleted]\033[0;0m\n");
    }

}

void testing_backward(void) {
    dNode *head_and_tail[2];

    char arr[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    make_dlinked_list(arr, 10, head_and_tail);

    dNode *head = head_and_tail[0];
    dNode *tail = head_and_tail[1];

    char correct1[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct1, 10, "Initial linked list");

    size_t list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 10, "Length: 10 (initial)");

    printf("\n");
    printf("============Initial Doubly Linked List============\n");
    print_dlinked_list_backward(tail, 10);
    printf("==================================================\n");
    printf("\n");

    tail = insert_new_tail(tail, 'S');

    char correct2[11] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't', 'S'};
    test_dlinked_list(head, correct2, 11, "Inserting new tail");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 11, "Length: 11 nodes (insertion)");

    tail = insert_dnode_before_tail(tail, list_len, 'G', 6);

    char correct3[12] = {'l', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't', 'S'};
    test_dlinked_list(head, correct3, 12, "Inserting node in a middle position");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 12, "Length: 12 nodes (insertion)");

    tail = insert_dnode_before_tail(tail, list_len, 'W', 1);

    char correct4[13] = {'l', 'W', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't', 'S'};
    test_dlinked_list(head, correct4, 13, "Inserting node after head node");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 13, "Length: 13 nodes (insertion)");

    printf("\n");
    printf("============Modified Doubly Linked List============\n");
    print_dlinked_list_backward(tail, 13);
    printf("==================================================\n");
    printf("\n");

    tail = remove_tail(tail);

    char correct5[12] = {'l', 'W', 'i', 'n', 'k', 'e', 'd', 'G', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct5, 12, "Removing tail");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 12, "Length: 12 nodes (removal)");

    tail = remove_dnode_before_tail(tail, list_len, 7);

    char correct6[11] = {'l', 'W', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct6, 11, "Removing a middle node");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 11, "Length: 11 nodes (removal)");

    tail = remove_dnode_before_tail(tail, list_len, 1);

    char correct7[10] = {'l', 'i', 'n', 'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(head, correct7, 10, "Removing the node after head");

    list_len = len_dlinked_list(tail, "backward");
    test_result(list_len, 10, "Length: 10 nodes (removal)");

    printf("\n");
    printf("============Doubly Linked List After Removing Nodes============\n");
    print_dlinked_list_backward(tail, 10);
    printf("==================================================\n");
    printf("\n");

    dNode *found_node_last = search_dlinked_list_backward(tail, 't');

    char correct8[1] = {'t'};
    test_dlinked_list(found_node_last, correct8, 1, "Search for last node");

    dNode *found_node_middle = search_dlinked_list_backward(tail, 'k');

    char correct9[7] = {'k', 'e', 'd', 'l', 'i', 's', 't'};
    test_dlinked_list(found_node_middle, correct9, 7, "Search for node in the middle");

    dNode *found_node_first = search_dlinked_list_backward(tail, 'l');

    char correct10[4] = {'l', 'i', 's', 't'};
    test_dlinked_list(found_node_first, correct10, 4, "Search for first node");

    tail = delete_dlinked_list_backward(tail);

    if (tail == NULL) {
        printf("\033[0;32m[Linked list was deleted successfully]\033[0;0m\n");
    }
    else {
        printf("\033[0;31m[Linked list was not deleted]\033[0;0m\n");
    }
}

int main(void) {
    testing_forward();

    printf("#\n");
    printf("#\n");
    printf("#\n");
    printf(">>>>>>>>>> testing_forward finished\n");
    printf("#\n");
    printf("#\n");
    printf("#\n");

    testing_backward();

    printf("#\n");
    printf("#\n");
    printf("#\n");
    printf(">>>>>>>>>> testing_backward finished\n");
    printf("#\n");
    printf("#\n");
    printf("#\n");

    return 0;
}