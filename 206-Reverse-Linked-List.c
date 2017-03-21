/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (NULL == head)
    {
        return NULL;
    }
    if (NULL == head->next)
    {
        return head;
    }
    struct ListNode *temp;
    struct ListNode *tail = head->next;
    head->next = NULL;
    while (NULL != tail)
    {
        temp = tail;
        tail = tail->next;
        temp->next = head;
        head = temp;
    }
    return head;
}
