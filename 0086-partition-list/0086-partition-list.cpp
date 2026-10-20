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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = new ListNode(-1);
        ListNode* largeHead = new ListNode(-1);

        ListNode* small = smallHead;
        ListNode* large = largeHead;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val < x) {
                small->next = temp;
                small = temp;
            } else {
                large->next = temp;
                large = temp;
            }

            temp = temp->next;
        }

        large->next = nullptr;
        small->next = largeHead->next;

        ListNode* result = smallHead->next;

        delete smallHead;
        delete largeHead;

        return result;
    }
};