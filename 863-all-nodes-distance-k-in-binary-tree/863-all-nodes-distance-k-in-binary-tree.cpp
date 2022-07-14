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
    void dfs(TreeNode* root, TreeNode* par, vector<TreeNode*>& parent){
        if(root == NULL)
            return;
        
        parent[root->val] = par;
        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> parent(501, NULL);
        dfs(root, NULL, parent);
        
        queue<TreeNode*> queue;
        bool vis[501] = {};
        queue.push(target);
        vis[target->val] = true;
        int dist = 0;
        
        vector<int> ans;
        while(!queue.empty()){
            int size = queue.size();
            while(size--){
                auto node = queue.front();
                queue.pop();
                
                if(dist == k){
                    ans.push_back(node->val);
                }
                
                if(parent[node->val] && !vis[parent[node->val]->val]){
                    queue.push(parent[node->val]);
                    vis[parent[node->val]->val] = true;
                }
                if(node->left && !vis[node->left->val]){
                    queue.push(node->left);
                    vis[node->left->val] = true;
                }
                if(node->right && !vis[node->right->val]){
                    queue.push(node->right);
                    vis[node->right->val] = true;
                }
            }
            dist++;
        }
        
        return ans;
    }
};