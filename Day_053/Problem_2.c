//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order input (-1 means NULL)
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = newNode(arr[0]);

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct TreeNode* curr = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Level Order Traversal function
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    *returnSize = 0;

    while (front < rear) {
        int levelSize = rear - front;

        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            result[*returnSize][i] = node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return result;
}

// Print result
void printResult(int** result, int returnSize, int* returnColumnSizes) {
    printf("[\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1)
                printf(", ");
        }
        printf("]\n");
    }
    printf("]\n");
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    int returnSize;
    int* returnColumnSizes;

    int** result = levelOrder(root, &returnSize, &returnColumnSizes);

    printResult(result, returnSize, returnColumnSizes);

    return 0;
}
