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
        if(!list1 && !list2)
            return NULL;
        if(!list1 || !list2)
            return (list1 ? list1 : list2);
        
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy, *ptr1 = list1, *ptr2 = list2;
        
        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        if(ptr1){
            ptr->next = ptr1;
        }
        if(ptr2){
            ptr->next = ptr2;
        }
        
        return dummy->next;
    }
};