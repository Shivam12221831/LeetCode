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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head == NULL) return head;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        if(cnt == k || k%cnt == 0) return head;
        k %= cnt;
        temp = head;
        for(int i=1; i<cnt-k; i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;

        return newHead;
    }
};