/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (NULL == l1)
    {
        return l2;
    }
    if (NULL == l2)
    {
        return l1;
    }
    struct ListNode *head = NULL, *tail = NULL;
    while (NULL != l1 && NULL != l2)
    {
        if (l1->val < l2->val)
        {
            if (NULL == head)
            {
                head = l1;
                tail = l1;
            }
            else
            {
                tail->next = l1;
                tail = tail->next;
            }
            l1 = l1->next;
        }
        else
        {
            if(NULL == head)
            {
                head = l2;
                tail = l2;
            }
            else
            {
                tail->next = l2;
                tail = tail->next;
            }
            l2 = l2->next;
        }
    }
    if (NULL != l1)
    {
        tail->next = l1;
    }
    if (NULL != l2)
    {
        tail->next = l2;
    }
    return head;
}
