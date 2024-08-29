/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node* temp = head;
        while (temp) {
            if (temp->child) {
                Node* child = temp->child;
                Node* childTail = child;
                while (childTail->next) {
                    childTail = childTail->next;
                }
                childTail->next = temp->next;
                if (temp->next) {
                    temp->next->prev = childTail;
                }
                temp->next = child;
                child->prev = temp;
                temp->child = nullptr;
            }
            temp = temp->next;
        }
        return head;
    }
};