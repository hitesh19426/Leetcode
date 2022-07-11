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
    void dfs(TreeNode* root, map<int, int>& count, int &ans){
        if(root == NULL)
            return;
        
        count[root->val]++;
        if(count.rbegin()->first == root->val)
            ans++;
        
        dfs(root->left, count, ans);
        dfs(root->right, count, ans);
        
        if(--count[root->val] == 0)
            count.erase(root->val);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        map<int, int> count;
        dfs(root, count, ans);
        return ans;
    }
};