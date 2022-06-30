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
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL)
            return NULL;
        TreeNode* ptr = root, *node = NULL;
        while(ptr){
            if(ptr->val <= p->val){
                ptr = ptr->right;
            }
            else{
                if(node == NULL || ptr->val < node->val)
                    node = ptr;
                ptr = ptr->left;
            }
        }
        
        return node;
    }
};