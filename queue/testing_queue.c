#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "testing_tools.h"

int main(void) {
    qNode *head_and_tail[2];
    char arr[5] = {'q', 'u', 'e', 'u', 'e'};
    make_queue(arr, 5, head_and_tail);

    qNode *front = head_and_tail[0];
    qNode *rear = head_and_tail[1];

    char correct1[5] = {'q', 'u', 'e', 'u', 'e'};
    test_queue(front, correct1, 5, "Forming initial queue");

    size_t queue_len = len_queue(front);
    test_result(queue_len, 5, "Length: 5 (initial)");

    printf("\n");
    printf("==========Initial Queue==========\n");
    peek(front, rear);
    printf("#################################\n");
    print_queue(front);
    printf("=================================\n");
    printf("\n");

    rear = enqueue(rear, 'X');

    char correct2[6] = {'q', 'u', 'e', 'u', 'e', 'X'};
    test_queue(front, correct2, 6, "Enqueuing 'X'");

    queue_len = len_queue(front);
    test_result(queue_len, 6, "Length: 6 (enqueuing)");

    rear = enqueue(rear, 'Y');

    char correct3[7] = {'q', 'u', 'e', 'u', 'e', 'X', 'Y'};
    test_queue(front, correct3, 7, "Enqueuing 'Y'");

    queue_len = len_queue(front);
    test_result(queue_len, 7, "Length: 7 (enqueuing)");

    printf("\n");
    printf("==========Modified Queue==========\n");
    peek(front, rear);
    printf("#################################\n");
    print_queue(front);
    printf("=================================\n");
    printf("\n");
    
    front = dequeue(front);

    char correct4[6] = {'u', 'e', 'u', 'e', 'X', 'Y'};
    test_queue(front, correct4, 6, "Dequeuing 'q'");

    queue_len = len_queue(front);
    test_result(queue_len, 6, "Length: 6 (dequeuing)");
    
    front = dequeue(front);

    char correct5[5] = {'e', 'u', 'e', 'X', 'Y'};
    test_queue(front, correct5, 5, "Dequeuing 'u'");

    queue_len = len_queue(front);
    test_result(queue_len, 5, "Length: 5 (dequeuing)");
    
    printf("\n");
    printf("==========Queue After Deletion==========\n");
    peek(front, rear);
    printf("#################################\n");
    print_queue(front);
    printf("=================================\n");
    printf("\n");
    
    front = delete_queue(front);

    if (front == NULL) {
        printf("\033[0;32m[queue was deleted successfully]\033[0;0m\n");
    }
    else {
        printf("\033[0;31m[queue was not deleted]\033[0;0m\n");
    }
}