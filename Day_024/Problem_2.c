//given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct ListNode {
    int val;
    struct ListNode* next;
};

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

// Function to remove all occurrences of val
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Remove from beginning
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode* curr = head;

    // Remove remaining
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
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
    int n, val;

    // Input
    scanf("%d", &n);
    struct ListNode* head = createList(n);

    scanf("%d", &val);

    // Remove elements
    head = removeElements(head, val);

    // Output
    printList(head);

    return 0;
}
