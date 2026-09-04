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
    ListNode* mergeNodes(ListNode* head) {
      ListNode* temp=head->next;
       ListNode* dummy=new ListNode(-1);
       ListNode* t1=dummy;
      int sum=0;
      while(temp!=NULL){
        sum=sum+temp->val;
        if(temp->val==0){
            ListNode* newnode=new ListNode(sum);
            t1->next=newnode;
            t1=newnode;
            sum=0;
        }
        temp=temp->next;
      }  
      return dummy->next;
    }
};