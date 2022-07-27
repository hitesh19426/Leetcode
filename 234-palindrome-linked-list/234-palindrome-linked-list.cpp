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
    stack<int> st;
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        
        ListNode *slow = head;
        while(slow){
            st.push(slow->val);
            slow = slow->next;
        }
        
        slow = head;
        while(slow){
            if(slow->val != st.top())
                return false;
            slow = slow->next;
            st.pop();
        }
        
        return true;
    }
};