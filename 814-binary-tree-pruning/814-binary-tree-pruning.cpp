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
    void prune(TreeNode* &root){
        if(root == NULL)
            return;
        
        prune(root->left);
        prune(root->right);
        
        if(!root->left && !root->right && (root->val != 1))
            root = NULL;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        prune(root);
        return root;
    }
};