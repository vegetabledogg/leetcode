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

bool isPalindrome(struct ListNode* head) {
    if (NULL == head || NULL == head->next)
    {
        return true;
    }
    struct ListNode *slow = head, *fast = head, *temp;
    while (NULL != fast && NULL != fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (NULL == fast)
    {
        temp = reverseList(slow);
    }
    else
    {
        temp = reverseList(slow->next);
    }
    while (NULL != temp)
    {
        if (head->val != temp->val)
        {
            return false;
        }
        head = head->next;
        temp = temp->next;
    }
    return true;
}
