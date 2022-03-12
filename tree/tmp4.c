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