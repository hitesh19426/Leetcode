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
    void helper(TreeNode* root, long long &sum, long long target, int &count, unordered_map<long long, int>& prefix){
        if(root == NULL)
            return;
        
        // visit all downward nodes from this node
        sum += root->val;
        if(sum == target)
            count++;
        if(prefix.find(sum-target) != prefix.end())
            count += prefix[sum-target];
        prefix[sum]++;
        
        helper(root->left, sum, target, count, prefix);
        helper(root->right, sum, target, count, prefix);
        
        if(--prefix[sum] == 0)
            prefix.erase(sum);
        sum -= root->val;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        long long sum = 0;
        unordered_map<long long, int> prefix;
        helper(root, sum, targetSum, count, prefix);
        return count;
    }
};