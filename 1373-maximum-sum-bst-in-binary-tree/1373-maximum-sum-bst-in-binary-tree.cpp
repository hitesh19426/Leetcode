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
class DS{
public:
    int sum = 0, maxtree = INT_MIN, mintree = INT_MAX, isbst = true;
    DS() {}
    DS(int sum, int maxtree, int mintree, bool isbst) : sum(sum), maxtree(maxtree), mintree(mintree), isbst(isbst) {}
};
class Solution {
    DS helper(TreeNode* root, int &res){
        if(root == NULL)
            return DS();
        
        auto left = helper(root->left, res);
        auto right = helper(root->right, res);
        
        bool isBST = left.isbst && right.isbst && left.maxtree < root->val && root->val < right.mintree;
        int sum = root->val + left.sum + right.sum;
        if(isBST)
            res = max(res, sum);
        
        return DS(sum, max({root->val, left.maxtree, right.maxtree}), min({root->val, left.mintree, right.mintree}), isBST);
    }
public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};