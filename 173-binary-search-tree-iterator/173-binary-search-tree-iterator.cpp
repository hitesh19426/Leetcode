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
class BSTIterator {
    stack<TreeNode*> stack;
    TreeNode* root;
public:
    BSTIterator(TreeNode* root) : root(root) {}
    
    int next() {
        while(root){
            stack.push(root);
            root = root->left;
        }
        auto ans = stack.top();
        stack.pop();
        root = ans->right;
        return ans->val;
    }
    
    bool hasNext() {
        return (root || !stack.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */