/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root) {
    struct TreeNode* stack[10000];
    int top = -1;
    int flag = 1;
    struct TreeNode *firstNode = NULL, *secondNode = NULL, *precursor;
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
        else if (0 == flag)
        {
            if (root->val <= precursor->val)
            {
                if (NULL == firstNode)
                {
                    firstNode = precursor;
                    secondNode = root;
                }
                else
                {
                    secondNode = root;
                }
            }
        }
        precursor = root;
        root = root->right;
    }
    int temp = firstNode->val;
    firstNode->val = secondNode->val;
    secondNode->val = temp;
}
