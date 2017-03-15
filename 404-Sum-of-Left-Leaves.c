/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    struct TreeNode* stack[100000];
    int top = -1;
    int sum = 0;
    while (NULL != root || -1 != top)
    {
        while (NULL != root)
        {
            stack[++top] = root;
            if (NULL != root->left && NULL == root->left->left && NULL == root->left->right)
            {
                sum += root->left->val;
            }
            root = root->left;
        }
        root = stack[top--]->right;
    }
    return sum;
}
