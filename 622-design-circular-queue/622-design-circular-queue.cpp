class MyCircularQueue {
    int cap, size;
    list<int> queue;
public:
    MyCircularQueue(int k) : cap(k), size(0) {}
    
    bool enQueue(int value) {
        if(size == cap)
            return false;
        queue.push_back(value);
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0)
            return false;
        queue.pop_front();
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0)
            return -1;
        return queue.front();
    }
    
    int Rear() {
        if(size == 0)
            return -1;
        return queue.back();
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */