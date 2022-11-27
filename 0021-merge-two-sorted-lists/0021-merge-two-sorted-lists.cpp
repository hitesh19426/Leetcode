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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1), *last = dummy, *ptr1 = list1, *ptr2 = list2;
        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                last->next = ptr1;
                ptr1 = ptr1->next;
            }else{
                last->next = ptr2;
                ptr2 = ptr2->next;
            }
            last = last->next;
        }
        if(ptr1){
            last->next = ptr1;
        }
        if(ptr2){
            last->next = ptr2;
        }
        
        auto newhead = dummy->next;
        delete dummy;
        return newhead;
    }
};