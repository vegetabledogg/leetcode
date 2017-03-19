/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b)
{
    return a > b ? a : b;
}
int height(struct TreeNode *root)
{
    if (NULL == root)
    {
        return -1;
    }
    return root->val;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    if (NULL == root)
    {
        return 0;
    }
    int lenth2 = diameterOfBinaryTree(root->left);
    int lenth3 = diameterOfBinaryTree(root->right);
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int lenth1 = 2 + leftHeight + rightHeight;
    root->val = max(leftHeight, rightHeight) + 1;
    int max;
    if (lenth1 > lenth2)
    {
        max = lenth1;
    }
    else
    {
        max = lenth2;
    }
    if (max < lenth3)
    {
        max = lenth3;
    }
    return max;
}
