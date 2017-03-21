/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (NULL == headA || NULL == headB)
    {
        return NULL;
    }
    struct ListNode *tempA = headA, *tempB = headB;
    int countA = 0, countB = 0, count;
    while (NULL != tempA)
    {
        tempA = tempA->next;
        countA++;
    }
    while (NULL != tempB)
    {
        tempB = tempB->next;
        countB++;
    }
    if (countA > countB)
    {
        count = countA - countB;
        while (count--)
        {
            headA = headA->next;
        }
    }
    else
    {
        count = countB - countA;
        while (count--)
        {
            headB = headB->next;
        }
    }
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
