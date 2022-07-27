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
    int length(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int n = length(head);
        stack<pair<int, int>> stack;
        vector<int> ans(n, 0);
        
        auto ptr = head;
        int index = 0;
        while(ptr){
            while(!stack.empty() && stack.top().first < ptr->val){
                ans[stack.top().second] = ptr->val;
                stack.pop();
            }
            stack.push({ptr->val, index++});
            ptr = ptr->next;
        }
        return ans;
    }
};