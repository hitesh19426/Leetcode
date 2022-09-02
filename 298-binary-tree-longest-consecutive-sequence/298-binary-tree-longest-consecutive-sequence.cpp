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
    int helper(TreeNode* root, int &ans){
        if(root == NULL)
            return 0;
        
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        int maxlen = 1;
        if(root->left && root->left->val-1 == root->val)
            maxlen = max(maxlen, left+1);
        if(root->right && root->right->val-1 == root->val)
            maxlen = max(maxlen, right+1);
        
        ans = max(ans, maxlen);
        return maxlen;
    }
public:
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};