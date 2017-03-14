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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(100000 * sizeof(int));
    struct TreeNode* stack[100000];
    int top = -1;
    *returnSize = 0;
    while (NULL != root || -1 != top)
    {
        while (NULL != root)
        {
            stack[++top] = root;
            result[(*returnSize)++] = root->val;
            root = root->left;
        }
        root = stack[top--]->right;
    }
    return result;
}
