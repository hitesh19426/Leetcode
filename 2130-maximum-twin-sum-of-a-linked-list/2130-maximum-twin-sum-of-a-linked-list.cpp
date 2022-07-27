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
    int pairSum(ListNode* head) {
        vector<int> arr;
        auto ptr = head;
        while(ptr){
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        int ans = 0;
        for(int low = 0, high = arr.size()-1; low < high; low++, high--)
            ans = max(arr[low] + arr[high], ans);
        return ans;
    }
};