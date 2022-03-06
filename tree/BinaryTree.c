#include "BinaryTree.h"




void travel(struct TreeNode *root, int *ret, int *size) {
    if (root == NULL)return;
    travel(root->left, ret, size);
    ret[(*size)++] = root->val;
    travel(root->right, ret, size);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    int *ret = malloc(sizeof(int) * 100);
    travel(root, ret, returnSize);
    return ret;
}

/////////////////////////////////////////////////////////



void travel(struct TreeNode *root, int *ret, int *size) {
    if (root == NULL)return;
    ret[(*size)++] = root->val;
    travel(root->left, ret, size);
    travel(root->right, ret, size);
}

//DLR
int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    int *ret = malloc(sizeof(int) * 100);
    travel(root, ret, returnSize);
    return ret;
}


/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////



void travel(struct TreeNode *root, int *ret, int *size) {
    if (root == NULL)return;
    travel(root->left, ret, size);
    travel(root->right, ret, size);
    ret[(*size)++] = root->val;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    int *ret = malloc(sizeof(int) * 100);
    travel(root, ret, returnSize);
    return ret;
}


/////////////////////////////////////////////////////////
