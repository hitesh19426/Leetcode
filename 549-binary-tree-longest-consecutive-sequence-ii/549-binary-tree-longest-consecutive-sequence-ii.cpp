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
            if(root->left->val+1 == root->val){
                dec = left_dec+1;
            }
            else if(root->left->val-1 == root->val){
                inc = left_inc+1;
            }   
        }
        if(root->right){
            if(root->right->val+1 == root->val){
                dec = max(dec, right_dec+1);
            }
            else if(root->right->val-1 == root->val){
                inc = max(inc, right_inc+1);
            }
        }
        
        ans = max(ans, inc+dec-1);
        return {inc, dec};
    }
public:
    int longestConsecutive(TreeNode* root) {
        int ans = 1;
        helper(root, ans);
        return ans;
    }
};