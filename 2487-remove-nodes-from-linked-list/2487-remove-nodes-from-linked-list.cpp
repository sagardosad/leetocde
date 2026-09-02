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
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* newhead = reverseList(head);
        ListNode* prev = newhead;
        ListNode* temp = prev->next;

        int max = prev->val;

        while (temp != NULL) {

            if (temp->val >= max) {
                prev->next = temp;
                prev = temp;
                max = temp->val;
                temp = temp->next;
            }
            else {
                prev->next = temp->next;
                temp = temp->next;
            }
        }

        return reverseList(newhead);
    }
};