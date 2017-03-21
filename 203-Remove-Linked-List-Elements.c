/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (NULL == head)
    {
        return NULL;
    }
    while (NULL != head && val == head->val)
    {
        head = head->next;
    }
    struct ListNode *tail = head;
    if (NULL == head)
    {
        return head;
    }
    while (NULL != tail->next)
    {
        if (val == tail->next->val)
        {
            tail->next = tail->next->next;
        }
        else
        {
            tail = tail->next;
        }
    }
    return head;
}
