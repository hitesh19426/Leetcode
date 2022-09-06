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
    bool hasOne(TreeNode* &root){
        if(root == NULL)
            return false;
        
        bool left = hasOne(root->left);
        bool right = hasOne(root->right);
        bool curr = left || right || (root->val == 1);
        
        if(!curr)
            root = NULL;
        
        return curr;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        hasOne(root);
        return root;
    }
};