/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    while (1)
    {
        node->val = node->next->val;
        if (NULL == node->next->next)
        {
            node->next = NULL;
            return;
        }
        node = node->next;
    }
}
