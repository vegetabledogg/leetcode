/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *newHead = NULL, *tail = NULL, *pNode = head, *temp;
    struct RandomListNode *nextPtrArray[100000];
    int i = 0;
    if (NULL == head)
    {
        return newHead;
    }
    while (NULL != pNode)
    {
        if (NULL == newHead)
        {
            newHead = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
            tail = newHead;
        }
        else
        {
            tail->next = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
            tail = tail->next;
        }
        tail->label = pNode->label;
        temp = pNode;
        pNode = pNode->next;
        nextPtrArray[i++] = temp->next;
        temp->next = tail;
        tail->random = temp->random;
        tail->next = NULL;
    }
    pNode = newHead;
    while (NULL != pNode)
    {
        if (NULL != pNode->random)
        {
            pNode->random = pNode->random->next;
        }
        pNode = pNode->next;
    }
    pNode = head;
    i = 0;
    while (NULL != pNode)
    {
        pNode->next = nextPtrArray[i++];
        pNode = pNode->next;
    }
    return newHead;
}
