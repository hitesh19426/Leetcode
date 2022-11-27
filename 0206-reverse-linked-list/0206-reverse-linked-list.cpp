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
    pair<ListNode*, ListNode*> reverse(ListNode* head){
        if(head == NULL)
            return {NULL, NULL};
        if(head->next == NULL)
            return {head, head};
        
        ListNode* next = head->next;
        head->next = NULL;
        
        auto [nexthead, nexttail] = reverse(next);
        nexttail->next = head;
        return {nexthead, head};
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head).first;
    }
};