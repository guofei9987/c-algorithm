int size = 0;
int **result;

void get_depth(struct TreeNode* root, int count)
{
    if(root == NULL)
    {
        if(count > size)
            size = count;
        return;
    }

    get_depth(root->left,count+1);
    get_depth(root->right,count+1);
}

void travel(struct TreeNode* root,int** returnColumnSizes,int level)
{
    if(root == NULL)
        return;
    result[level][(*returnColumnSizes)[level]++] = root->val;
    travel(root->left, returnColumnSizes, level + 1);
    travel(root->right, returnColumnSizes, level + 1);

}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    size = 0;
    get_depth(root,0);

    result = (int **)malloc(size * sizeof(int*));
    for(int i = 0; i < size;i++)
        result[i] = (int*)malloc(sizeof(int)*256);

    *returnColumnSizes = (int*)calloc(size, sizeof(int));
    travel(root,returnColumnSizes ,0);
    *returnSize = size;
    return result;
}