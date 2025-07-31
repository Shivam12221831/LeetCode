/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
        temp = head;
        while(temp != NULL){
            Node* copyNode = temp->next;
            if(temp->random != NULL){
                copyNode->random = temp->random->next;
            }else {
                copyNode->random = NULL;
            }
            temp = copyNode->next;
        }
        temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(temp != NULL){
            Node* copyNode = temp->next;
            res->next = copyNode;
            res = copyNode;
            temp->next = copyNode->next;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};