//https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/931/discuss/1602435/C-Iterative-Solution-using-a-Queue

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (!root) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct TreeNode *q[1001];
    int head = 0;
    int tail = 0;
    int **ret = malloc(sizeof *ret * 2000);
    *returnColumnSizes = malloc(sizeof **returnColumnSizes * 2000);
    q[tail++] = root;
    while ((tail - head) % 1001) {
        int sz = (*returnColumnSizes)[*returnSize] = (tail - head) % 1001;
        ret[*returnSize] = malloc(sizeof **ret * sz);
        for (int i = 0; i < sz; i++) {
            struct TreeNode *p = q[head++ % 1001];
            ret[*returnSize][i] = p->val;
            if (p->left)
                q[tail++ % 1001] = p->left;
            if (p->right)
                q[tail++ % 1001] = p->right;
        }
        (*returnSize)++;
    }
    return ret;
}