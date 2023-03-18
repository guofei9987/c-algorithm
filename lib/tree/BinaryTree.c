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


int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {

}


//typedef struct TreeNode TreeNode;

int **levelOrder(struct TreeNode *root, int **columnSizes, int *returnSize) {
    if (root == NULL) return NULL;

    int **ret = malloc(sizeof(int *) * 1000);
    *columnSizes = malloc(sizeof(int) * 1000);

//    TreeNode *queue[2000]; //easy queue
    struct TreeNode *queue[2000]; //easy queue
    int first = 0, end = 0;
    queue[end++] = root;

    int nodes_cur_level = 1, nodes_next_level = 0, level = 0;

    while (first < end) {
        ret[level] = malloc(sizeof(int) * 1000);

        for (int i = 0; i < nodes_cur_level && first < end; i++) {
            struct TreeNode *tmp = queue[first++];
            ret[level][i] = tmp->val;

            if (tmp->left) {
                queue[end++] = tmp->left;
                nodes_next_level++;
            }
            if (tmp->right) {
                queue[end++] = tmp->right;
                nodes_next_level++;
            }
        }

        (*columnSizes)[level++] = nodes_cur_level;
        if ((nodes_cur_level = nodes_next_level) == 0) break;

        nodes_next_level = 0;
    }

    *returnSize = level;
    return ret;
}

//获取树深度
void _get_depth(struct TreeNode *root, int count, int *depth) {
    if (root == NULL) {
        if (count > *depth)
            *depth = count;
        return;
    }

    _get_depth(root->left, count + 1, depth);
    _get_depth(root->right, count + 1, depth);
}

int get_depth(struct TreeNode *root) {
    int v_depth = 0;
    int *depth = &v_depth;
    _get_depth(root, 0, depth);
    return *depth;
}

//另一个 level order 方案
//https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/931/discuss/1602435/C-Iterative-Solution-using-a-Queue

void travel(struct TreeNode *root, int **returnColumnSizes, int level, int **result) {
    if (root == NULL)
        return;
    result[level][(*returnColumnSizes)[level]++] = root->val;
    travel(root->left, returnColumnSizes, level + 1, result);
    travel(root->right, returnColumnSizes, level + 1, result);
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    int **result;

    int size = get_depth(root);


    result = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        result[i] = (int *) malloc(sizeof(int) * 256);

    *returnColumnSizes = (int *) calloc(size, sizeof(int));
    travel(root, returnColumnSizes, 0, result);
    *returnSize = size;
    return result;
}