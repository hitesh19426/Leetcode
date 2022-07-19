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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        int prev = 0;
        while(!queue.empty()){
            int size = queue.size(), curr = 0;
            while(size--){
                auto node = queue.front();
                queue.pop();
                
                curr += node->val;
                
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
            prev = curr;
        }
        return prev;
    }
};