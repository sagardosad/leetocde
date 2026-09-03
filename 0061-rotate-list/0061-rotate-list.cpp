class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* prev = head;
        ListNode* length = head;
        ListNode* temp = head->next;

        long long cnt = 0;

        while(length != NULL){
            cnt++;
            length = length->next;
        }

        k = k % cnt;

        if(k == 0)
            return head;

        for(int i = 0; i < cnt-k-1; i++){
            temp = temp->next;
            prev = prev->next;
        }

        ListNode* newnode = new ListNode(-1);
        newnode->next = temp;

        while(temp->next != NULL){
            temp = temp->next;
        }

        prev->next = NULL;
        temp->next = head;

        return newnode->next;
    }
};