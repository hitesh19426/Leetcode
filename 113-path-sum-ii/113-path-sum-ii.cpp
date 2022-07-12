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
    bool isleaf(TreeNode* root){
        return root->left == NULL && root->right == NULL;
    }
    
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ans, int target){
        if(root == NULL)
            return;
        
        path.push_back(root->val);
        sum += root->val;
        
        if(isleaf(root) && sum == target){
            ans.push_back(path);
        }
        
        dfs(root->left, sum, path, ans, target);
        dfs(root->right, sum, path, ans, target);
        
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(root, 0, path, ans, targetSum);
        return ans;
    }
};