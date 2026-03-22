//Problem: Count Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x, count = 0;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input
    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Count nodes
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Output
    printf("%d", count);

    return 0;
}
