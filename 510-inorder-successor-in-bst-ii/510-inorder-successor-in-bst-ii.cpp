/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node == NULL)
            return NULL;
        if(node->right){
            auto ptr = node->right;
            while(ptr->left)
                ptr = ptr->left;
            return ptr;
        }
        
        if(node->parent == NULL)
            return NULL;
        while(node->parent && node->parent->right == node)
            node = node->parent;
        return node->parent;
    }
};