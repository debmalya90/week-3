#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

int main() {
    struct Node *head, *second, *third, *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1; head->next = second;
    second->data = 2; second->next = third;
    third->data = 3; third->next = fourth;
    fourth->data = 4; fourth->next = second; 

    if (detectLoop(head))
        printf("Loop detected in linked list\n");
    else
        printf("No loop found\n");

    return 0;
}
