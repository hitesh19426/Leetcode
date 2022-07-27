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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *curr = head;
        while(curr){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* middle(ListNode* head){
        auto slow = head, fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* mid = middle(head);
        ListNode* secondList = mid->next;
        mid->next = NULL;
        
        secondList = reverse(secondList);
        
        int ans = 0;
        while(head){
            ans = max(head->val + secondList->val, ans);
            head = head->next;
            secondList = secondList->next;
        }
        return ans;
    }
};