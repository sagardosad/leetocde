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
    ListNode* reversell(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newhead=reversell(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* midll(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=midll(head);
        ListNode* first=head;
        ListNode* second=slow->next;
        second = reversell(second);
        while(second!=NULL){
            if(first->val !=second->val){
                reversell(slow->next);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
        
    }
};