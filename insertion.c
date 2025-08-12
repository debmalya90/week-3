#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int choice, data, pos, i;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        switch (choice) {
            case 1: // Insert at Beginning
                printf("Enter data: ");
                scanf("%d", &data);
                newNode = malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = head;
                head = newNode;
                break;

            case 2: // Insert at End
                printf("Enter data:

