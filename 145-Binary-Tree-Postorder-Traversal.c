/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(1000000 * sizeof(int));
    struct TreeNode* stack[100000];
    struct TreeNode *visit = NULL;
    int top = -1;
    *returnSize = 0;
    while (NULL != root || -1 != top)
    {
        while (NULL != root)
        {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top];
        if (root->right == visit || NULL == root->right)
        {
            result[(*returnSize)++] = root->val;
            top--;
            visit = root;
            root = NULL;
        }
        else
        {
            root = root->right;
        }
    }
    return result;
}
