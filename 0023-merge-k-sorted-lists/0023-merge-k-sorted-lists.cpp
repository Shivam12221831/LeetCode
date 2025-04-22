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
ListNode* mergeLists(ListNode* h1, ListNode* h2){
    if(h1==NULL || h2==NULL) return h1==NULL ? h2 : h1;
    if(h1->val <= h2->val){
        h1->next = mergeLists(h1->next, h2);
        return h1;
    } else {
        h2->next = mergeLists(h1, h2->next);
        return h2;
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* newHead = lists[0];
        for(int i=1; i<lists.size(); i++){
            newHead = mergeLists(newHead, lists[i]);
        }
        return newHead;
    }
};