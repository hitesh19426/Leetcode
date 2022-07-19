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
    TreeNode* helper(int low, int high, int &root, vector<int>& preorder, unordered_map<int, int>& indexes){
        if(high < low)
            return NULL;
        
        int index = indexes[preorder[root]];
        auto node = new TreeNode(preorder[root++]);
        node->left = helper(low, index-1, root, preorder, indexes);
        node->right = helper(index+1, high, root, preorder, indexes);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indexes;
        for(int i=0; i<inorder.size(); i++)
            indexes[inorder[i]] = i;
        
        int root = 0;
        return helper(0, inorder.size()-1, root, preorder, indexes);
    }
};