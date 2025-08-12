#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, data, pos, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);
    printf("Enter data to insert: ");
    scanf("%d", &data);

    newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Updated Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
