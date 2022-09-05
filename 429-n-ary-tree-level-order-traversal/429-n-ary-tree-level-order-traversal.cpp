/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return {};
        
        queue<Node*> queue;
        queue.push(root);
        
        vector<vector<int>> ans;
        while(!queue.empty()){
            int size = queue.size();
            vector<int> lvl;
            while(size--){
                auto node = queue.front();
                queue.pop();
                
                lvl.push_back(node->val);
                
                for(auto &v: node->children){
                    queue.push(v);
                }
            }
            
            ans.push_back(lvl);
        }
        
        return ans;
    }
};