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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* prev = NULL;
        ListNode* later = NULL;
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        int cnt = 0;

        while (t1 != NULL) {
            if (cnt == a - 1) {
                prev = t1;
            }

            if (cnt == b) {
                later = t1->next;
                break;
            }

            cnt++;
            t1 = t1->next;
        }

        prev->next = t2;

        while (t2->next != NULL) {
            t2 = t2->next;
        }

        t2->next = later;

        return list1;
    }
};