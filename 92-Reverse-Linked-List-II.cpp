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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *tempNode, *pNode = head, *firstNode;
        if (1 == m)
        {
            firstNode = head;
            for (int i = 0; i < n - m; i++)
            {
                tempNode = firstNode->next;
                firstNode->next = tempNode->next;
                tempNode->next = head;
                head = tempNode;
            }
        }
        else
        {
            for (int i = 1; i < m - 1; i++)
            {
                pNode = pNode->next;
            }
            firstNode = pNode->next;
            for (int i = 0; i < n - m; i++)
            {
                tempNode = firstNode->next;
                firstNode->next = tempNode->next;
                tempNode->next = pNode->next;
                pNode->next = tempNode;
            }
        }
        return head;
    }
};
