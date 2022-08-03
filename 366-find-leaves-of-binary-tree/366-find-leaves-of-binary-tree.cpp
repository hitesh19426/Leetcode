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
    int depth(TreeNode* root, vector<vector<int>>& ans){
        if(root == nullptr)
            return 0;
        
        int left = depth(root->left, ans);
        int right = depth(root->right, ans);
        
        int depth = max(left, right);
        if(ans.size() <= depth)
            ans.push_back({});
        ans[depth].push_back(root->val);
        
        return depth+1;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        depth(root, ans);
        return ans;
    }
};