/*given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to remove cycle
bool removeCycle(struct Node* head) {
    if (head == NULL) return false;

    struct Node *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find start of cycle
            slow = head;

            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            // Step 3: Remove cycle
            fast->next = NULL;
            return true;
        }
    }

    return false;
}

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int n, pos;
    scanf("%d", &n);

    if (n == 0) {
        printf("false");
        return 0;
    }

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* tail = NULL;

    // Input nodes
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct Node* new_node = newNode(x);

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Input position for cycle
    scanf("%d", &pos);

    // Create cycle if pos != -1
    if (pos != -1) {
        temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        tail->next = temp; // create loop
    }

    // Remove cycle
    bool result = removeCycle(head);

    if (result)
        printf("true\n");
    else
        printf("false\n");

    // Print list after removing cycle
    printList(head);

    return 0;
}
