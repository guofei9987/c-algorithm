#ifndef C_ALGORITHM_BINARYTREE_H
#define C_ALGORITHM_BINARYTREE_H


struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

//DLR
int *preorderTraversal(struct TreeNode *root, int *returnSize);

//InOrder(self, root):  # LDR

//PostOrder(self, root):  # LRD

//levelOrder(self, root)


#endif //C_ALGORITHM_BINARYTREE_H
