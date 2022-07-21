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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftptr = head, *prev = NULL;
        int count = 1;
        while(count < left){
            prev = leftptr;
            leftptr = leftptr->next;
            count++;
        }
        
        if(prev)
            prev->next = NULL;
        
        ListNode* rightptr = leftptr, *next = NULL, *prevloop = NULL;
        while(count <= right){
            next = rightptr->next;
            rightptr->next = prevloop;
            prevloop = rightptr;
            rightptr = next;
            count++;
        }
        
        leftptr->next = rightptr;
        if(prev)
            prev->next = prevloop;
        
        return (prev ? head : prevloop);
    }
};
/*
T(N) = O(N), one pass
S(N) = O(1)
*/
