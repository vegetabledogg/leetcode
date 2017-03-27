/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }
        ListNode *lastNode = head;
        ListNode *insertNode, *pNode;
        while (nullptr != lastNode->next)
        {
            insertNode = lastNode->next;
            int tempVal = insertNode->val;
            if (tempVal >= lastNode->val)
            {
                lastNode = insertNode;
                continue;
            }
            lastNode->next = insertNode->next;
            if (tempVal <= head->val)
            {
                insertNode->next = head;
                head = insertNode;
                continue;
            }
            pNode = head;
            while (pNode->next != lastNode->next)
            {
                if (pNode->next->val >= tempVal)
                {
                    insertNode->next = pNode->next;
                    pNode->next = insertNode;
                    break;
                }
                pNode = pNode->next;
            }
        }
        return head;
    }
};
