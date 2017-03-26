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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pNode, *lastNode;
        while (nullptr != head)
        {
            if (nullptr == head->next)
            {
                return head;
            }
            else
            {
                if (head->val == head->next->val)
                {
                    int temp = head->val;
                    while (nullptr != head && temp == head->val)
                    {
                        head = head->next;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if (nullptr == head)
        {
            return nullptr;
        }
        lastNode = head;
        pNode = head->next;
        while (nullptr != pNode)
        {
            if (nullptr == pNode->next)
            {
                return head;
            }
            else
            {
                if (pNode->val == pNode->next->val)
                {
                    int temp = pNode->val;
                    while (nullptr != pNode && temp == pNode->val)
                    {
                        pNode = pNode->next;
                    }
                    lastNode->next = pNode;
                }
                else
                {
                    lastNode = pNode;
                    pNode = pNode->next;
                }
            }
        }
        return head;
    }
};
