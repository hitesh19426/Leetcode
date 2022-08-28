/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int, int> helper(TreeNode* root, int &ans){
        if(root == NULL)
            return {0, 0};
        
        auto [left_inc, left_dec] =  helper(root->left, ans);
        auto [right_inc, right_dec] = helper(root->right, ans);
        
        int inc = 1, dec = 1;
        if(root->left){
            if(root->left->val == root->val-1){
                dec += left_dec, ans = max(ans, dec);
            }
            else if(root->left->val == root->val+1){
                inc += left_inc, ans = max(ans, inc);
            }   
        }
        if(root->right){
            if(root->right->val == root->val-1){
                dec = max(dec, right_dec+1), ans = max(ans, dec);
                if(root->left && root->left->val == root->val+1)
                    ans = max(ans, left_inc+right_dec+1);
            }
            else if(root->right->val == root->val+1){
                inc = max(inc, right_inc+1), ans = max(ans, inc);
                if(root->left && root->left->val == root->val-1)
                    ans = max(ans, left_dec+right_inc+1);
            }
        }
        
        return {inc, dec};
    }
public:
    int longestConsecutive(TreeNode* root) {
        int ans = 1;
        helper(root, ans);
        return ans;
    }
};