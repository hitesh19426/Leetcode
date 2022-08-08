class MyCircularDeque {
    int limit;
    deque<int> list;
public:
    MyCircularDeque(int k) : limit(k) {}
    
    bool insertFront(int value) {
        if(list.size() == limit)
            return false;
        list.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(list.size() == limit)
            return false;
        list.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(list.empty())
            return false;
        list.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(list.empty())
            return false;
        list.pop_back();
        return true;
    }
    
    int getFront() {
        if(list.empty())
            return -1;
        return list.front();
    }
    
    int getRear() {
        if(list.empty())
            return -1;
        return list.back();
    }
    
    bool isEmpty() {
        return list.empty();
    }
    
    bool isFull() {
        return list.size() == limit;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */