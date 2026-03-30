#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Detect and remove cycle
bool detectAndRemoveCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected

            // Step 2: Find start of loop
            slow = head;
            struct Node* prev = NULL;

            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Step 3: Remove loop
            prev->next = NULL;
            return true;
        }
    }

    return false; // No cycle
}

//  Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//  Create cycle manually 
void createCycle(struct Node* head, int pos) {
    if (pos < 0) return;

    struct Node *temp = head, *cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    if (cycleNode != NULL)
        temp->next = cycleNode;
}

// Main function
int main() {
    // Example: 1 -> 3 -> 4
    struct Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);

    // Create cycle at position 1 (0-based index)
    createCycle(head, 1);

    if (detectAndRemoveCycle(head)) {
        printf("true\n");
        printList(head);
    } else {
        printf("false\n");
    }

    return 0;
}
