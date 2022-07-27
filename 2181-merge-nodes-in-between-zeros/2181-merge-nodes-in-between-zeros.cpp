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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1), *last = dummy, *ptr = head->next;
        while(ptr){
            int sum = 0;
            while(ptr && ptr->val != 0){
                sum += ptr->val;
                ptr = ptr->next;
            }
            last->next = new ListNode(sum);
            last = last->next;
            ptr = ptr->next;
        }
        
        auto to_return = dummy->next;
        delete dummy;
        return to_return;
    }
};