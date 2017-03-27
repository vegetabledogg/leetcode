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
        ListNode *pNode = head;
        while (nullptr != pNode && nullptr != pNode->next)
        {
            if (pNode->val == pNode->next->val)
            {
                pNode->next = pNode->next->next;
            }
            else
            {
                pNode = pNode->next;
            }
        }
        return head;
    }
};
