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
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        map<int, vector<int>> cols;
        queue<pair<TreeNode*, int>> queue;
        queue.emplace(root, 0);
        
        while(!queue.empty()){
            auto [node, col] = queue.front();
            queue.pop();
            
            cols[col].push_back(node->val);
            if(node->left)
                queue.emplace(node->left, col-1);
            if(node->right)
                queue.emplace(node->right, col+1);
        }
        
        vector<vector<int>> ans;
        for(auto &[col, nodes]: cols)
            ans.push_back(nodes);
        return ans;
    }
};