//Problem: Create and Traverse Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of elements
    scanf("%d", &n);

    // If no elements
    if (n <= 0) {
        return 0;
    }

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        // If first node
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traverse and print
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
