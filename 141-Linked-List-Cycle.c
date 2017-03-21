/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (NULL == head)
    {
        return false;
    }
    struct ListNode *temp = head;
    while (NULL != temp && NULL != temp->next)
    {
        temp = temp->next->next;
        head = head->next;
        if (temp == head)
        {
            return true;
        }
    }
    return false;
}
