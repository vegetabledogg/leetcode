/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    struct TreeNode* queue[100000];
    int head = 0, rear = -1, sentinel = 0, depth = 0;
    if (NULL == root)
    {
        return 0;
    }
    else
    {
        queue[++rear] = root;
    }
    while (head <= rear)
    {
        if (NULL != queue[head]->left)
        {
            queue[++rear] = queue[head]->left;
        }
        if (NULL != queue[head]->right)
        {
            queue[++rear] = queue[head]->right;
        }
        if (head == sentinel)
        {
            depth++;
            sentinel = rear;
        }
        head++;
    }
    return depth;
}
