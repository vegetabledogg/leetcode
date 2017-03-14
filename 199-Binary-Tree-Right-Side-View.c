/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(100000 * sizeof(int));
    struct TreeNode* queue[100000];
    int head = 0, tail = -1, sentinel = 0;
    *returnSize = 0;
    if (NULL != root)
    {
        queue[++tail] = root;
    }
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
            result[(*returnSize)++] = queue[head]->val;
            sentinel = tail;
        }
        head++;
    }
    return result;
}
