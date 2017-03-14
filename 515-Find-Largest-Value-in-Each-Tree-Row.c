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
int* largestValues(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(100000 * sizeof(int));
    struct TreeNode* queue[100000];
    int head = 0, tail = -1, sentinel = 0;
    int max;
    *returnSize = 0;
    if (NULL != root)
    {
        queue[++tail] = root;
        max = queue[head]->val;
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
        if (max < queue[head]->val)
        {
            max = queue[head]->val;
        }
        if (head == sentinel)
        {
            result[(*returnSize)++] = max;
            sentinel = tail;
            if (head < tail)
            {
                max = queue[head + 1]->val;
            }
        }
        head++;
    }
    return result;
}
