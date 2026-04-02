/*You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children. Return the minimum number of cameras needed to monitor all nodes of the tree.*/

#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int cameras = 0;

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; // covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1; // place camera
    }

    if (left == 1 || right == 1)
        return 2; // covered

    return 0; // needs camera
}

// Main logic
int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == 0)
        cameras++;
    return cameras;
}

int main() {

    struct TreeNode* root = newNode(0);
    root->left = newNode(0);
    root->left->left = newNode(0);
    root->left->right = newNode(0);

    int result = minCameraCover(root);
    printf("Minimum cameras needed: %d\n", result);

    return 0;
}
