/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    bool find(TreeNode* root, TreeNode* v){
        if(root == NULL)
            return false;
        if(root == v)
            return true;
        if(root->val < v->val)
            return find(root->right, v);
        return find(root->left, v);
    }
    bool lieOnOppSides(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val > p->val && root->val < q->val)
            return true;
        return root->val > q->val && root->val < p->val;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!find(root, p) || !find(root, q))
            return NULL;
        if(root ==  p || root == q || lieOnOppSides(root, p, q))
            return root;
        if(root->val > p->val)
            return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};