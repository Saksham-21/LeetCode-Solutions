/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* dummyA=headA;
        ListNode* dummyB=headB;
        while(dummyA!=dummyB){
            dummyA= (dummyA==NULL)?headB:dummyA->next;
            dummyB= (dummyB==NULL)?headA:dummyB->next;
        }
        return dummyA;
    }
};