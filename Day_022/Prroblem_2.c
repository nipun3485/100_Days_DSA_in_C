//Given the head of a singly linked list, reverse the list, and return the reversed list.
#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse the linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev
        curr = next;         // move curr
    }

    return prev;
}

// Function to create list
struct ListNode* createList(int n) {
    struct ListNode *head = NULL, *temp = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Function to print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n;

    // Input
    scanf("%d", &n);

    struct ListNode* head = createList(n);

    // Reverse list
    head = reverseList(head);

    // Output
    printList(head);

    return 0;
}
