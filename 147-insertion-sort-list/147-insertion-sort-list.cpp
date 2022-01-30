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
    ListNode* insert(ListNode* head, ListNode* node){
        ListNode* dummy = new ListNode(-1), *ptr = dummy;
        while(head && head->val < node->val){
            ptr->next = head;
            head = head->next;
            ptr = ptr->next;
        }
        
        ptr->next = node;
        node->next = head;
        return dummy->next;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
                return head;
        ListNode* curr = head->next;
        head->next = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = NULL;
            
            head = insert(head, curr);
            curr = next;
        }
        return head;
    }
};