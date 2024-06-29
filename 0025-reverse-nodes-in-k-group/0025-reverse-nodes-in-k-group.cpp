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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode* node = head;
        int count = 0;
        while (node != NULL && count < k) {
            node = node->next;
            count++;
        }
        
        if (count < k) {
            return head;
        }
        
        ListNode* pre=NULL;
        ListNode* curr=head;
        ListNode* nex=NULL;
        int cnt=0;
        
        while(curr!=NULL && cnt<k){
            nex=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nex;
            cnt++;
        }
        
        if(nex!=NULL){
            head->next=reverseKGroup(nex,k);
        }
        
        return pre;
    }
};