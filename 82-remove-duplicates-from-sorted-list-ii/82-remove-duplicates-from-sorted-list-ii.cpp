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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1), last = dummy, ptr = head;
        while(ptr){
            if(ptr->next && ptr->next->val == ptr->val){
                while(ptr->next && ptr->next->val == ptr->val){
                    auto next = ptr->next;
                    ptr->next = ptr->next->next;
                    delete next;
                }
                ptr = ptr->next;
            }
            else{
                last->next = ptr;
                last = ptr;
                ptr = ptr->next;
            }
        }
        
        last->next = NULL;
        return dummy->next;
    }
};