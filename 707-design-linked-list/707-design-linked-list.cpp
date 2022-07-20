class MyLinkedList {
    int size = 0;
    ListNode *head = NULL, *tail = NULL;
public:
    MyLinkedList() {}
    
    int get(int index) {
        if(index >= size)
            return -1;
        auto ptr = head;
        while(index--)
            ptr = ptr->next;
        return ptr->val;
    }
    
    void addAtHead(int val) {
        if(head == NULL)
            head = tail = new ListNode(val);
        else
            head = new ListNode(val, head);
        size++;
        // printList(head);
        // cout << head->val << " " << tail->val << " " << size << endl;
    }
    
    void addAtTail(int val) {
        if(head == NULL)
            head = tail = new ListNode(val);
        else
            tail->next = new ListNode(val), tail = tail->next;
        size++;
        // printList(head);
        // cout << head->val << " " << tail->val << " " << size << endl;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        if(index == size){
            addAtTail(val);
        }
        else if(index == 0){
            addAtHead(val);
        }
        else{
            ListNode* ptr = head, *prev = NULL;
            while(index--)
                prev = ptr, ptr = ptr->next;
            prev->next = new ListNode(val, ptr);
            size++;
            // printList(head);
            // cout << head->val << " " << tail->val << " " << size << endl;
        }
        
    }
    
    void printList(ListNode* head){
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size)
            return;
        if(index == 0){
            auto to_delete = head;
            head = head->next;
            delete to_delete;
            
        }
        else{
            ListNode* ptr = head, *prev = NULL;
            while(index--)
                prev = ptr, ptr = ptr->next;
            if(ptr == tail)
                tail = prev;
            prev->next = ptr->next;
            delete ptr;
        }
        if(--size == 0)
            head = tail = NULL;
        // printList(head);
        // cout << head->val << " " << tail->val << " " << size << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */