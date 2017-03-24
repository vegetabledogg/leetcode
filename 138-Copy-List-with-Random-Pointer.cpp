/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        struct RandomListNode *newHead = NULL, *tail = NULL, *pNode = head, *temp;
        vector<struct RandomListNode*> nextPtrArray;
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
            nextPtrArray.push_back(temp->next);
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
        while (NULL != pNode)
        {
            pNode->next = nextPtrArray[i++];
            pNode = pNode->next;
        }
        return newHead;
    }
};
