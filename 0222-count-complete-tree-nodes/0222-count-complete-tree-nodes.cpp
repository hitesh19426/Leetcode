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
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        return depth(root->left)+1;
    }
    void countNodes(TreeNode* root, int dep, int id, int &ans){
        if(root == NULL)
            return;
        
        // cout << root->val << " "; 
        int leftDepth = depth(root->left), rightDepth = depth(root->right);
        if(max(leftDepth, rightDepth) == 0)
            ans += id;
        else
            ans += (1<<dep);
        
        if(leftDepth > rightDepth){
            countNodes(root->left, dep+1, 2*id-1, ans);
        }else{
            countNodes(root->right, dep+1, 2*id, ans);
        }
    }
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        countNodes(root, 0, 1, ans);
        return ans;
    }
};