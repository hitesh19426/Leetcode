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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            int size = queue.size(), count = size;
            long long sum = 0;
            while(size--){
                auto node = queue.front();
                queue.pop();
                
                sum += node->val;
                
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
            
            ans.push_back((double)sum/count);
        }
        
        return ans;
    }
};