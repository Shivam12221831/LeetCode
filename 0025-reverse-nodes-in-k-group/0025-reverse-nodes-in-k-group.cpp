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
    ListNode* findKthNode(ListNode* head, int k){
        ListNode* temp = head;
        for(int i=1; i<k; i++){
            if(temp == NULL) return NULL;
            temp = temp->next;
        }
        return temp;
    }
    void reverse_LL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode*  next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;

            reverse_LL(temp);

            if(head == temp){
                head = kthNode;
                prevNode = temp;
            }else{
                prevNode->next = kthNode;
                prevNode = temp;
            }
            temp = nextNode;
        }
        return head;
    }
};