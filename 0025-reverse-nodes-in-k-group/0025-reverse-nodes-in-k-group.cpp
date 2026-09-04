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
    ListNode* reversell(ListNode*head){
        if(head==NULL || head->next==NULL) return head;
         ListNode* newhead=reversell(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
            return newhead;

    }
    ListNode* kthnode(ListNode*head,int k){
        k=k-1;
        while(head!=NULL && k!=0 ){
            k--;
            head=head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp=head;
    ListNode* prev=NULL;
    ListNode* nextnode=NULL;
    while(temp!=NULL){
        ListNode* knode=kthnode(temp,k);
        if(knode==NULL){
            if(prev){
            prev->next=temp;
            }
            break;
        }
        nextnode=knode->next;
        knode->next=NULL;
        reversell(temp);
        if(temp==head){
            head=knode;
        }
        else{
            prev->next=knode;
           
        }
         prev=temp;
        temp=nextnode;


    }
    return head;
    }
};