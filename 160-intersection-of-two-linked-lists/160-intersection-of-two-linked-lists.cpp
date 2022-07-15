/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL || headA == headB)
            return headA == NULL ? headA : headB;
        
        auto ptr1 = headA, ptr2 = headB;
        while(ptr1 && ptr2 && ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            if(ptr1 == ptr2)
                return ptr1;
            if(ptr1 == NULL)
                ptr1 = headB;
            if(ptr2 == NULL)
                ptr2 = headA;
        }
        return ptr1;
    }
};