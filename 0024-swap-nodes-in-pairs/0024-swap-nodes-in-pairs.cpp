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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* node = dummy;

        while (odd != NULL && even != NULL) {

            ListNode* next = even->next;  // 3 ko save kiya 

            // 1 -> 2  to   2 -> 1
            node->next = even;
            even->next = odd;

            // 1 -> 3
            odd->next = next;

            // node ab 1 par
            node = odd;

            // next pair
            odd = next;

            if (odd != NULL)
                even = odd->next;
        }

        return dummy->next;
    }
};