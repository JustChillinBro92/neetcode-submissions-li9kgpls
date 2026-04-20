class MyCircularQueue {
private:
    int cap, size;
    int f, r;
    vector<int> q;

public:
    MyCircularQueue(int k) {
        cap = k;
        q = vector<int> (cap);
        f = 0; 
        r = -1;
        size = 0;
    }
    
    bool enQueue(int value) {
        // overflow
        if(isFull()) return false;

        r = (r + 1) % cap;
        q[r] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        // underflow
        if(isEmpty()) return false;

        f = (f + 1) % cap;
        size--;
        return true;
    }
    
    int Front() {
        return !isEmpty() ? q[f] : -1;
    }
    
    int Rear() {
        return !isEmpty() ? q[r] : -1;
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