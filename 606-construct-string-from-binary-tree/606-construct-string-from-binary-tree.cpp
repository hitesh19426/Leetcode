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
    string preorder(TreeNode* root){
        if(root == NULL)
            return "";
        
        string ans = to_string(root->val);
        if(root->left || root->right){
            ans += "(" + preorder(root->left) + ")";
        }
        
        if(root->right){
            ans += "(" + preorder(root->right) + ")";
        }
        return ans;
    }
public:
    string tree2str(TreeNode* root) {
        if(root == NULL)
            return "";
        return preorder(root);
    }
};