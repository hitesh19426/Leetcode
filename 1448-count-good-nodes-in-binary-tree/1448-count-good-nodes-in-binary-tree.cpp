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
    void dfs(TreeNode* root, int max_value_on_path, int &ans){
        if(root == NULL)
            return;
        
        max_value_on_path = max(max_value_on_path, root->val);
        if(max_value_on_path == root->val)
            ans++;
        
        dfs(root->left, max_value_on_path, ans);
        dfs(root->right, max_value_on_path, ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MIN, ans);
        return ans;
    }
};