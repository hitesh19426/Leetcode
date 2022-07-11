/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        
        queue<TreeNode*> queue;
        string data = "";
        queue.push(root);
        data += to_string(root->val) + " ";
        
        while(!queue.empty()){
            auto node = queue.front();
            queue.pop();
            
            if(node->left){
                data += to_string(node->left->val) + " ";
                queue.push(node->left);
            } else{
                data += "1001 ";
            }
            
            if(node->right){
                data += to_string(node->right->val) + " ";
                queue.push(node->right);
            }
            else{
                data += "1001 ";
            }
        }
        
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        
        stringstream ss(data);
        queue<TreeNode*> queue;
        int val;
        ss >> val;
        
        TreeNode* root = new TreeNode(val);
        queue.push(root);
        
        while(!queue.empty()){
            auto node = queue.front();
            queue.pop();
            
            int left, right;
            ss >> left >> right;
            
            if(left != 1001){
                node->left = new TreeNode(left);
                queue.push(node->left);
            }
            if(right != 1001){
                node->right = new TreeNode(right);
                queue.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));