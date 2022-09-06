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
    bool allSame(TreeNode* root, int &ans){
        if(root == NULL)
            return true;
        
        bool left = allSame(root->left, ans);
        bool right = allSame(root->right, ans);
        
        bool allsame = true;
        if(left == false || (root->left && root->left->val != root->val))
            allsame = false;
        if(right == false || (root->right && root->right->val != root->val))
            allsame = false;
        
        if(allsame)
            ans++;
        return allsame;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        allSame(root, ans);
        return ans;
    }
};