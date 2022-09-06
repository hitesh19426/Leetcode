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
    int helper(TreeNode* &root){
        if(root == NULL)
            return 0;
        
        int left = helper(root->left);
        int right = helper(root->right);
        int sum = left + right + root->val;
        
        if(sum == 0)
            root = NULL;
        
        return sum;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        return root;
    }
};