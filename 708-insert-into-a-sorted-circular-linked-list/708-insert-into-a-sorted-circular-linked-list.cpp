/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL){
            auto head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        Node* just_smaller = NULL, *largest = NULL, *ptr = head;
        do{
            if(ptr->val <= insertVal){
                if(just_smaller == NULL || ptr->val >= just_smaller->val)
                    just_smaller = ptr;
            }
            if(largest == NULL || ptr->val >= largest->val)
                largest = ptr;
            ptr = ptr->next;
            
        }while(ptr != head);
        
        if(just_smaller){
            just_smaller->next = new Node(insertVal, just_smaller->next);
        }else{
            largest->next = new Node(insertVal, largest->next);
        }
        return head;
    }
};