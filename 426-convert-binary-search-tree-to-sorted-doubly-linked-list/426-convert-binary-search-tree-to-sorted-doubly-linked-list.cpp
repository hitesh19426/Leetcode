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
    pair<Node*, Node*> helper(Node* root){
        if(root == NULL)
            return {NULL, NULL};
        
        auto [headl, taill] = helper(root->left);
        auto [headr, tailr] = helper(root->right);
        
        if(taill)
            taill->right = root;
        if(headr)
            headr->left = root;
        root->left = taill;
        root->right = headr;
            
        auto newhead = (headl ? headl : root);
        auto newtail = (tailr ? tailr : root);
        
        return {newhead, newtail};
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return NULL;
        auto [head, tail] = helper(root);
        tail->right = head;
        head->left = tail;
        return head;
    }
};