/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize <= 0)
    {
        return NULL;
    }
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = preorder[0];
    int i;
    for (i = 0; i < inorderSize; i++)
    {
        if (preorder[0] == inorder[i])
        {
            break;
        }
    }
    newNode->left = buildTree(preorder + 1, i, inorder, i);
    newNode->right = buildTree(preorder + i + 1, preorderSize - i - 1, inorder + i + 1, preorderSize - i - 1);
    return newNode;
}
