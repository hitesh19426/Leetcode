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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            ans.push_back(queue.back()->val);
            int len = queue.size();
            
            while(len--){
                auto front = queue.front();
                queue.pop();
                
                if(front->left)
                    queue.push(front->left);
                if(front->right)
                    queue.push(front->right);
            }
            
        }
        
        return ans;
    }
};