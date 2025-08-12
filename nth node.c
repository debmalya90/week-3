#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int nthFromEnd(struct Node* head, int n) {
    struct Node *first = head, *second = head;

    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (first == NULL) return -1; // n is greater than list length
        first = first->next;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second->data;
}

int main() {
    int n_nodes, data, n;
    struct Node *head = NULL, *temp, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n_nodes);

    for (int i = 0; i < n_nodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printf("Enter n (from end): ");
    scanf("%d", &n);

    int result = nthFromEnd(head, n);
    if (result != -1)
        printf("%dth node from end is: %d\n", n, result);
    else
        printf("List is shorter than given n\n");

    return 0;
}
