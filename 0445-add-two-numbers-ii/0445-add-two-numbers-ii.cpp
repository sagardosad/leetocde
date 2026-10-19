
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;

        while (l1 != nullptr) {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        while (!st1.empty() || !st2.empty() || carry) {
            int sum = carry;

            if (!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }

            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            carry = sum / 10;
            int digit = sum % 10;

            // Insert the new digit at the beginning
            ListNode* node = new ListNode(digit);
            node->next = head;
            head = node;
        }

        return head;
    }
};
