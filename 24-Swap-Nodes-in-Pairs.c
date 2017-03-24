/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *pNode = head, *tempNode, *lastNode = head;
    if (NULL == head || NULL == head->next)
    {
        return head;
    }
    while (NULL != pNode && NULL != pNode->next)
    {
        if (head == pNode)
        {
            head = pNode->next;
            pNode->next = pNode->next->next;
            head->next = pNode;
            lastNode = pNode;
            pNode = pNode->next;
        }
        else
        {
            lastNode->next = pNode->next;
            pNode->next = pNode->next->next;
            lastNode->next->next = pNode;
            lastNode = pNode;
            pNode = pNode->next;
        }
    }
    return head;
}
