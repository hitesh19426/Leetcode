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
    TreeNode* helper(vector<int>& pre, int low, int high, int &root, unordered_map<int, int> &index){
        if(high < low)
            return NULL;

        int ind = index[pre[root]];
        TreeNode* node = new TreeNode(pre[root++]);
        node->left = helper(pre, low, ind-1, root, index);
        node->right = helper(pre, ind+1, high, root, index);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if(pre.empty())
            return NULL;
    
        unordered_map<int, int> index;
        vector<int> inorder(pre.begin(), pre.end());
        sort(inorder.begin(), inorder.end());
        for(int i=0; i<inorder.size(); i++)
            index[inorder[i]] = i;

        int root = 0;
        return helper(pre, 0, pre.size()-1, root, index);
    }
};