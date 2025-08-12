#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* temp = &dummy;
    dummy.next = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int val1 = (l1 != NULL) ? l1->data : 0;
        int val2 = (l2 != NULL) ? l2->data : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        temp->next = newNode(sum % 10);
        temp = temp->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // First number: 243 (stored as 3 -> 4 -> 2)
    struct Node* l1 = newNode(3);
    l1->next = newNode(4);
    l1->next->next = newNode(2);

    // Second number: 564 (stored as 4 -> 6 -> 5)
    struct Node* l2 = newNode(4);
    l2->next = newNode(6);
    l2->next->next = newNode(5);

    printf("First number:\n");
    printList(l1);
    printf("Second number:\n");
    printList(l2);

    struct Node* result = addLists(l1, l2);
    printf("Sum:\n");
    printList(result); // Expected: 7 -> 0 -> 8 (807)

    return 0;
}
