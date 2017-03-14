/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool mirror(struct TreeNode *p, struct TreeNode *q)
{
    if ((NULL == p && NULL != q) || (NULL != p && NULL == q))
    {
        return false;
    }
    if (NULL == p && NULL == q)
    {
        return true;
    }
    return p->val == q->val && mirror(p->left, q->right) && mirror(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (NULL == root)
    {
        return true;
    }
    return mirror(root->left, root->right);
}
