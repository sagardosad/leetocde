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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        stack<ListNode*> st;
        ListNode* curr = head;

        // Step 1: Push all nodes into the stack
        while (curr != NULL) {
            st.push(curr);
            curr = curr->next;
        }

        // Step 2: Reorder the list
        curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;

            ListNode* last = st.top();
            st.pop();

            if (curr == last || nextNode == last) {
                last->next = NULL;
                break;
            }

            curr->next = last;
            last->next = nextNode;

            curr = nextNode;
        }
    }
};
