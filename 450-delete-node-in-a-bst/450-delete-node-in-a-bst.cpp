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
    TreeNode* deleteNode(TreeNode* &root){
        // cout << root->val << endl;
        auto right = root->right, node = root->right;
        if(right){
            while(right->left)
                right = right->left;
            // cout << right->val << endl;
            right->left = root->left;
            delete root;
            return node;
        }
        
        node = root->left;
        delete root;
        return node;
        // cout << node->val << endl;
        // delete root;
        // return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* ptr = root, *parent = NULL;
        while(ptr && ptr->val != key){
            parent = ptr;
            if(ptr->val < key)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if(ptr == nullptr)
            return root;
        
        if(parent == NULL)
            return deleteNode(ptr);
        
        if(parent->left && parent->left->val == key)
            parent->left = deleteNode(ptr);
        else
            parent->right = deleteNode(ptr);
        
        return root;
    }
};
/*
TC() = O(H)
SC() = O(1)
*/