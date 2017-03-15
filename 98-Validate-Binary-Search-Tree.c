/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    struct TreeNode* stack[10000];
    int top = -1;
    int precursor, flag = 1;
    while (NULL != root || -1 != top)
    {
        while (NULL != root)
        {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        if (1 == flag)
        {
            flag = 0;
        }
        else if (0 == flag && root->val <= precursor)
        {
            return false;
        }
        precursor = root->val;
        root = root->right;
    }
    return true;
}
