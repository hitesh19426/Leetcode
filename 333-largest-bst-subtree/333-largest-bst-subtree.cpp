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
struct DS{
    int minv, maxv, count, isbst;
    DS() : minv(INT_MAX), maxv(INT_MIN), count(0), isbst(true) {}
    DS(int minv, int maxv, int count, int isbst) : minv(minv), maxv(maxv), count(count), isbst(isbst){}
};

class Solution {
    DS dfs(TreeNode* root, int &res){
        if(root == NULL)
            return DS();
        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        
        bool isbst = left.isbst && right.isbst && root->val > left.maxv && root->val < right.minv;
        int minv = min({root->val, left.minv, right.minv});
        int maxv = max({root->val, left.maxv, right.maxv});
        int count = left.count + right.count + 1;
        
        if(isbst)
            res = max(res, count);
        
        return DS(minv, maxv, count, isbst);
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};