#include "BinaryTree.h"

//DLR
int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *result = NULL;
    *returnSize = 0;

    if (root == NULL) {
        return result;
    }


    struct TreeNode **stack = (struct TreeNode **) malloc(sizeof(struct TreeNode *));
    struct TreeNode *pop;
    int length = 0;
    stack[length++] = root;

    while (length > 0) {
        result = (int *) realloc(result, (*returnSize + 1) * sizeof(int));
        pop = stack[--length];
        result[*returnSize] = pop->val;
        *returnSize += 1;
        if (pop->right) {
            stack = (struct TreeNode **) realloc(stack, sizeof(struct TreeNode *) * (length + 1));
            stack[length++] = pop->right;
        }
        if (pop->left) {
            stack = (struct TreeNode **) realloc(stack, sizeof(struct TreeNode *) * (length + 1));
            stack[length++] = pop->left;
        }
    }
    free(stack);
    return result;
}