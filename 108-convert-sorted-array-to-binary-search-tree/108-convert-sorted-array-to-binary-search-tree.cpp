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
    TreeNode *helper(vector<int> &arr, int low, int high){
        if(high < low)
            return nullptr;
        
        int mid = low + (high-low)/2;
        
        TreeNode *node = new TreeNode(arr[mid]);
        node->left = helper(arr, low, mid-1);
        node->right = helper(arr, mid+1, high);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};