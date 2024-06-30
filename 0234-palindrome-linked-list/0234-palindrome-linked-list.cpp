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
    ListNode* reverseLL(ListNode* head){
        ListNode* pre=NULL;
        ListNode* curr=head;
        ListNode* nex=NULL;
        
        while(curr!=NULL){
            nex=curr->next;
            
            curr->next=pre;
            pre=curr;
            curr=nex;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL ||head==NULL){
            return true;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        //find middle element
        while(fast->next!=NULL &&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //reverse the second half of LL(palindrome reverse)
        slow->next=reverseLL(slow->next);
        
        //move slow by 1
        slow=slow->next;
        
        while(slow!=NULL){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};