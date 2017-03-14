/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize <= 0)
    {
        return NULL;
    }
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = postorder[postorderSize - 1];
    int i;
    for (i = 0; i < inorderSize; i++)
    {
        if (inorder[i] == postorder[postorderSize - 1])
        {
            break;
        }
    }
    newNode->left = buildTree(inorder, i, postorder, i);
    newNode->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, inorderSize - i - 1);
    return newNode;
}
