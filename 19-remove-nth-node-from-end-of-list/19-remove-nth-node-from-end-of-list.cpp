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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        while(n--){
            ptr = ptr->next;
        }
        
        ListNode* prev = NULL, *cur = head;
        while(ptr){
            ptr = ptr->next;
            prev = cur;
            cur = cur->next;
        }
        (prev == NULL ? head = head->next : prev->next = cur->next);
        return head;
    }
};