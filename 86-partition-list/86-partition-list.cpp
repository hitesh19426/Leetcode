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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* less_head = new ListNode(-1), *less = less_head;
        ListNode* great_head = new ListNode(-1), *great = great_head;
        
        ListNode* ptr = head;
        while(ptr){
            if(ptr->val < x){
                less->next = ptr;
                less = ptr;
            }
            else{
                great->next = ptr;
                great = ptr;
            }
            ptr = ptr->next;
        }
        less->next = great->next = NULL;
        
        
        less->next = great_head->next;
        return less_head->next;
    }
};