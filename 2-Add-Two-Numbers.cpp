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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, temp;
        ListNode *head = NULL, *tail = NULL;
        while (nullptr != l1 && nullptr != l2)
        {
            temp = l1->val + l2->val + carry;
            carry = temp / 10;
            l1 = l1->next;
            l2 = l2->next;
            if (NULL == head)
            {
                head = new ListNode(temp % 10);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(temp % 10);
                tail = tail->next;
            }
        }
        while (nullptr != l1)
        {
            temp = l1->val + carry;
            carry = temp / 10;
            l1 = l1->next;
            if (NULL == head)
            {
                head = new ListNode(temp % 10);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(temp % 10);
                tail = tail->next;
            }
        }
        while (nullptr != l2)
        {
            temp = l2->val + carry;
            carry = temp / 10;
            l2 = l2->next;
            if (NULL == head)
            {
                head = new ListNode(temp % 10);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(temp % 10);
                tail = tail->next;
            }
        }
        if (0 != carry)
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
