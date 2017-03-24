/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int a1[100000], a2[100000], ans[100000];
    int i = 0, j = 0, k = 0;
    while (NULL != l1)
    {
        a1[i++] = l1->val;
        l1 = l1->next;
    }
    i--;
    while (NULL != l2)
    {
        a2[j++] = l2->val;
        l2 = l2->next;
    }
    j--;
    int carry = 0;
    int temp;
    while (i >= 0 && j >= 0)
    {
        temp = a1[i--] + a2[j--] + carry;
        ans[k++] = temp % 10;
        carry = temp / 10;
    }
    while (i >= 0)
    {
        temp = a1[i--] + carry;
        ans[k++] = temp % 10;
        carry = temp / 10;
    }
    while (j >= 0)
    {
        temp = a2[j--] + carry;
        ans[k++] = temp % 10;
        carry = temp / 10;
    }
    if (0 == carry)
    {
        k--;
    }
    else
    {
        ans[k] = carry;   
    }
    struct ListNode *head = NULL, *tail = NULL;
    while (k >= 0)
    {
        if (NULL == head)
        {
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            head->val = ans[k--];
            head->next = NULL;
            tail = head;
        }
        else
        {
            tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = ans[k--];
            tail->next = NULL;
        }
    }
    return head;
}
