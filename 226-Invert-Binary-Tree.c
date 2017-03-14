/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (NULL == root)
    {
        return NULL;
    }
    struct TreeNode *temp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = temp;
    return root;
}
