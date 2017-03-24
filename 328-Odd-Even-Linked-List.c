/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (NULL == head || NULL == head->next)
    {
        return head;
    }
    struct ListNode *oddNode = head, *evenNode = head->next;
    struct ListNode *oddHead = NULL, *oddTail, *evenHead = NULL, *evenTail;
    while (NULL != oddNode && NULL != evenNode)
    {
        if (NULL == oddHead)
        {
            oddHead = oddNode;
        }
        else
        {
            oddTail->next = oddNode;
        }
        oddTail = oddNode;
        oddNode = evenNode->next;
        if (NULL == evenHead)
        {
            evenHead = evenNode;
        }
        else
        {
            evenTail->next = evenNode;
        }
        evenTail = evenNode;
        if (NULL != oddNode)
        {
            evenNode = oddNode->next;
        }
        else
        {
            evenNode = NULL;
        }
    }
    if (NULL != oddNode)
    {
        oddTail->next = oddNode;
        oddTail = oddNode;
    }
    oddTail->next = evenHead;
    evenTail->next = NULL;
    return oddHead;
}
