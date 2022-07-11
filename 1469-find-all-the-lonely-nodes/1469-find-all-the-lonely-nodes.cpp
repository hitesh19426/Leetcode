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
    void dfs(TreeNode* root, int parentChildren, vector<int>& arr){
        if(root == NULL)
            return;
        
        if(parentChildren == 1)
            arr.push_back(root->val);
        
        int children = (root->left != NULL) + (root->right != NULL);
        dfs(root->left, children, arr);
        dfs(root->right, children, arr);
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> lonely_nodes;
        dfs(root, 0, lonely_nodes);
        return lonely_nodes;
    }
};