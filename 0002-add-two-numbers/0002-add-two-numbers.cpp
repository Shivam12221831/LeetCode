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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val; 
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;

            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* conti = (l1 == NULL) ? l2 : l1;
        while(conti != NULL){
            int sum = conti->val;
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;

            temp->next = new ListNode(sum);
            temp = temp->next;
            conti = conti->next;
        }
        if(carry > 0){
            temp->next = new ListNode(carry);
            temp = temp->next;
        }

        return dummyNode->next;
    }
};