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
        queue<TreeNode*> queue;
        queue.push(root);
        
        int prev = 0;
        while(!queue.empty()){
            int size = queue.size();
            prev = 0;
            while(size--){
                auto node = queue.front();
                queue.pop();
                
                prev += node->val;
                
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
        }
        return prev;
    }
};