class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) {
            minHeap.push(num);
            // keep the size of heap = k
            if(minHeap.size() > k) minHeap.pop();
        } 
    }
    
    int add(int val) {
        minHeap.push(val);
        // keep the size of heap = k
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
