/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findBottomLeftValue(struct TreeNode* root) {
    int result[10000];
    struct TreeNode* queue[100000];
    int head = 0, tail = -1, sentinel = 0;
    int i = 0;
    queue[++tail] = root;
    result[i++] = root->val;
    while (head <= tail)
    {
        if (NULL != queue[head]->left)
        {
            queue[++tail] = queue[head]->left;
        }
        if (NULL != queue[head]->right)
        {
            queue[++tail] = queue[head]->right;
        }
        if (head == sentinel)
        {
            if (head < tail)
            {
                result[i++] = queue[head + 1]->val;
            }
            sentinel = tail;
        }
        head++;
    }
    return result[i - 1];
}
