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
    int findmaxdivisor(int val1, int val2) {
        int data = 0;

        int limit = min(val1, val2);

        for (int i = 1; i <= limit; i++) {
            if (val1 % i == 0 && val2 % i == 0) {
                data = i;
            }
        }

        return data;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            int data = findmaxdivisor(temp->val, temp->next->val);
            ListNode* nextNode = temp->next;
            ListNode* newnode = new ListNode(data, nextNode);
            temp->next = newnode;
            temp = nextNode;
        }

        return head;
    }
};