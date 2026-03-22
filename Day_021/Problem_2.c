/*Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node*/
#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to find middle node
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // move 1 step
        fast = fast->next->next;  // move 2 steps
    }

    return slow; // middle node
}

// Helper function to create list
struct ListNode* createList(int arr[], int n) {
    struct ListNode *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
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

// Print list from given node
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = 6;

    struct ListNode* head = createList(arr, n);

    struct ListNode* mid = middleNode(head);

    printList(mid); // print from middle
    return 0;
}
