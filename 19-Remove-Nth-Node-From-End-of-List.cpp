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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (NULL == head)
        {
            return head;
        }
        vector<ListNode*> record;
        ListNode *pNode = head;
        while (nullptr != pNode)
        {
            record.push_back(pNode);
            pNode = pNode->next;
        }
        int index = record.size() - n;
        if (0 == index)
        {
            return head->next;
        }
        else
        {
            record[index - 1]->next = record[index]->next;
        }
        return head;
    }
};
