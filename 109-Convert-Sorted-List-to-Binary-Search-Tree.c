/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct ListNode *slow = NULL, *fast = head, *temp;
    struct TreeNode *newNode;
    if (NULL == head)
    {
        return NULL;
    }
    if (NULL == head->next)
    {
        newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = head->val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    while (NULL != fast && NULL != fast->next)
    {
        if (NULL == slow)
        {
            slow = head;
        }
        else
        {
            slow = slow->next;
        }
        fast = fast->next->next;
    }
    temp = slow->next;
    slow->next = NULL;
    newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = temp->val;
    newNode->left = sortedListToBST(head);
    newNode->right = sortedListToBST(temp->next);
    return newNode;
}
