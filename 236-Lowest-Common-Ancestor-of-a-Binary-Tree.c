/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (NULL == root)
    {
        return NULL;
    }
    if (p == root)
    {
        return p;
    }
    else if (q == root)
    {
        return q;
    }
    struct TreeNode *left, *right;
    left = lowestCommonAncestor(root->left, p, q);
    right = lowestCommonAncestor(root->right, p, q);
    if (NULL == left)
    {
        return right;
    }
    else if (NULL == right)
    {
        return left;
    }
    else
    {
        return root;
    }
}
