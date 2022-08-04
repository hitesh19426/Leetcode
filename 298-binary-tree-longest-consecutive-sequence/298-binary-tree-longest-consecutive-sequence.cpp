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
        
        int curr = 1;
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        if(root->left && root->left->val == root->val+1)
            curr += left;
        if(root->right && root->right->val == root->val+1)
            curr = max(curr, 1+right);
        ans = max(ans, curr);
        return curr;
    }
public:
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};