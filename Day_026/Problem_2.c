/*Design your implementation of the linked list. You can choose to use a singly or doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Linked List structure
typedef struct {
    Node* head;
    int size;
} MyLinkedList;

// Constructor
MyLinkedList* createLinkedList() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

// Get value at index
int get(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* temp = obj->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

// Add at head
void addAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;

    obj->head = newNode;
    obj->size++;
}

// Add at tail
void addAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* temp = obj->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    obj->size++;
}

// Add at index
void addAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        addAtHead(obj, val);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;

    Node* temp = obj->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    obj->size++;
}

// Delete at index
void deleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp = obj->head;

    if (index == 0) {
        obj->head = temp->next;
        free(temp);
    } else {
        Node* prev = NULL;
        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }

    obj->size--;
}

// Display list (for testing)
void printList(MyLinkedList* obj) {
    Node* temp = obj->head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function (demo)
int main() {
    MyLinkedList* list = createLinkedList();

    addAtHead(list, 10);
    addAtTail(list, 20);
    addAtTail(list, 30);
    addAtIndex(list, 1, 15); // 10 -> 15 -> 20 -> 30

    printList(list);

    printf("Value at index 2: %d\n", get(list, 2));

    deleteAtIndex(list, 1); // remove 15
    printList(list);

    return 0;
}
