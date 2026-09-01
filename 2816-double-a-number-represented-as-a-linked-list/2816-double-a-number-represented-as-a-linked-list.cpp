/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newhead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newhead;
    }

    ListNode* doubleIt(ListNode* head) {
        if (head == NULL)
            return NULL;

        // Reverse
        head = reverseList(head);

        ListNode* temp = head;
        int carry = 0;

        while (temp != NULL) {
            int value = temp->val * 2 + carry;

            temp->val = value % 10;
            carry = value / 10;

            if (temp->next == NULL)
                break;

            temp = temp->next;
        }
        if (carry == 1) {
            temp->next = new ListNode(1);
        }

        // Reverse back
        head = reverseList(head);

        return head;
    }
};