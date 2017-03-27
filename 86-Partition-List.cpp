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
    ListNode* partition(ListNode* head, int x) {
        ListNode *frontHead = nullptr, *frontTail, *backHead = nullptr, *backTail;
        while (nullptr != head)
        {
            if (head->val < x)
            {
                if (nullptr == frontHead)
                {
                    frontHead = head;
                    frontTail = head;
                }
                else
                {
                    frontTail->next = head;
                    frontTail = frontTail->next;
                }
                head = head->next;
                frontTail->next = nullptr;
            }
            else
            {
                if (nullptr == backHead)
                {
                    backHead = head;
                    backTail = head;
                }
                else
                {
                    backTail->next = head;
                    backTail = backTail->next;
                }
                head = head->next;
                backTail->next = nullptr;
            }
        }
        if (nullptr == frontHead)
        {
            return backHead;
        }
        frontTail->next = backHead;
        return frontHead;
    }
};
