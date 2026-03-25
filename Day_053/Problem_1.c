/*Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue Node (stores node + horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

// Queue
struct QNode queue[MAX];
int front = -1, rear = -1;

// Create new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Enqueue
void enqueue(struct Node* node, int hd) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear].node = node;
    queue[rear].hd = hd;
}

// Dequeue
struct QNode dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* q[MAX];
    int f = 0, r = 0;
    q[r++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    int map[MAX][MAX]; // store nodes
    int count[MAX] = {0}; // count per HD
    int offset = MAX / 2; // shift for negative index

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, temp.hd - 1);
        if (curr->right)
            enqueue(curr->right, temp.hd + 1);
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
