/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (NULL == root)
    {
        return false;
    }
    if (NULL == root->left && NULL == root->right)
    {
        if (root->val == sum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
