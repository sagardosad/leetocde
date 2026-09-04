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
        if(head==NULL || head->next==NULL) return head;
        ListNode* newhead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
            return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* nextnode=NULL;
        ListNode* first=NULL;
        ListNode*second=NULL;
        int cnt=1;
        while(temp!=NULL){
            if(cnt==left-1){
                prev=temp;
                first=temp->next;
            }
            if(cnt==right){
                second=temp;
                nextnode=temp->next;
                second->next=NULL;
            }
            temp=temp->next;
            cnt++;
        }
        if(left == 1) {
        first = head;
        ListNode* newhead = reverseList(first);
        first->next = nextnode;
        return newhead;
    }
        ListNode* newhead=reverseList(first);
        prev->next=newhead;
        first->next=nextnode;
        return head;
    }
};