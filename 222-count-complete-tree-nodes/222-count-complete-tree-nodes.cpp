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
    int find_depth(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + find_depth(root->left);
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        auto ptr = root;
        int count = 0, depth = 0, pos = 1;
        while(ptr->left || ptr->right){
            int leftDepth = find_depth(ptr->left), rightDepth = find_depth(ptr->right);
            count += (1<<depth);
            depth++;
            
            if(leftDepth > rightDepth){
                ptr = ptr->left;
                pos = 2*pos - 1;
            }
            else{
                ptr = ptr->right;
                pos = 2*pos;
            }
        }
        return count + pos;
    }
};
/*
TC(n) = logn*logn
SC(n) = logn (recursion stack)
*/
