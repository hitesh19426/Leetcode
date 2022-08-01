/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return NULL;
        
        stack<Node*> stack;
        Node* dummy = new Node(-1), *tail = dummy;
        
        while(root || !stack.empty()){
            while(root){
                stack.push(root);
                root = root->left;
            }
            auto node = stack.top();
            stack.pop();
            
            tail->right = node;
            node->left = tail;
            tail = node;
            
            root = node->right;
        }
        
        auto head = dummy->right;
        delete dummy;
        
        head->left = tail;
        tail->right = head;
        return head;
    }
};