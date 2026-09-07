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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp=head;
        int cnt=1;
        int length=0;
        while(temp!=NULL){
            if(cnt==k){
                first=temp;
            }
            length++;
            cnt++;
             temp = temp->next; 
        }
        temp=head;
        cnt=1;
        while(temp!=NULL){
            if(cnt==length+1-k){
                second=temp;
                break;
            }
            cnt++;
             temp = temp->next; 
        }
    
        

        // Swap values
        swap(first->val, second->val);

        return head;
    }
};