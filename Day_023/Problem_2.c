/*Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter. Return true if there is a cycle in the linked list. Otherwise, return false.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to detect cycle
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // cycle found
        }
    }

    return false; // no cycle
}

// Function to create linked list
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

// Function to create cycle at position pos
void createCycle(struct ListNode* head, int pos) {
    if (pos == -1) return;

    struct ListNode *temp = head, *cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }

    // connect last node to cycleNode
    if (cycleNode != NULL) {
        temp->next = cycleNode;
    }
}

int main() {
    int n, pos;

    // Input
    scanf("%d", &n);
    struct ListNode* head = createList(n);

    scanf("%d", &pos); // position to create cycle

    // Create cycle (for testing)
    createCycle(head, pos);

    // Check cycle
    if (hasCycle(head)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}
