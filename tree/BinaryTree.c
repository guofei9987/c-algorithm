#include "BinaryTree.h"

enum travel_type {
    traversal_ldr, traversal_dlr, traversal_lrd
};

int *Traversal(struct TreeNode *root, int *returnSize, enum travel_type travelType) {
    *returnSize = 0;
    int *ret = malloc(sizeof(int) * 100);
    switch (travelType) {
        case traversal_ldr:
            ldr(root, ret, returnSize);
        case traversal_dlr:
            dlr(root, ret, returnSize);
        case traversal_lrd:
            lrd(root, ret, returnSize);
    }
    return ret;
}


void ldr(struct TreeNode *root, int *ret, int *size) {
    if (root == NULL)return;
    ldr(root->left, ret, size);
    ret[(*size)++] = root->val;
    ldr(root->right, ret, size);
}

void dlr(struct TreeNode *root, int *ret, int *size) {
    if (root == NULL)return;
    ret[(*size)++] = root->val;
    dlr(root->left, ret, size);
    dlr(root->right, ret, size);
}


void lrd(struct TreeNode *root, int *ret, int *size) {
    if (root == NULL)return;
    lrd(root->left, ret, size);
    lrd(root->right, ret, size);
    ret[(*size)++] = root->val;
}


