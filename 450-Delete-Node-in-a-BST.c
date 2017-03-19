/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (NULL == root)
    {
        return root;
    }
    if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (NULL == root->left)
        {
            return root->right;
        }
        else if (NULL == root->right)
        {
            return root->left;
        }
        else
        {
            struct TreeNode *temp = root->right;
            while (NULL != temp->left)
            {
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}
