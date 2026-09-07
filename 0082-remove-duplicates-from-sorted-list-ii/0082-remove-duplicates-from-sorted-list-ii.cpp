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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* current=head;
        ListNode* prev=dummy;
        while(current!=NULL && current->next!=NULL){
            if(current->val==current->next->val){
                int duplicate=current->val;
                while(current!=NULL && current->val==duplicate){
                    current=current->next;
                }
                prev->next=current;
            }
            else{
                prev=current;
                current=current->next;
            }

        }
      
        return dummy->next;
    }
};