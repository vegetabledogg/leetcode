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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (nullptr != fast && nullptr != fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }
        if (nullptr == fast || nullptr == fast->next)
        {
            return nullptr;
        }
        while (head != fast)
        {
            slow = fast;
            while (1)
            {
                slow = slow->next;
                if (slow == head)
                {
                    return head;
                }
                if (slow == fast)
                {
                    break;
                }
            }
            head = head->next;
        }
        return fast;
    }
};
