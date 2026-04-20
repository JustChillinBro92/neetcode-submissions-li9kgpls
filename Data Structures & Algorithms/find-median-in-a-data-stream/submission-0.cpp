class MedianFinder {
private:
    priority_queue<double, vector<double>, greater<double>> minHeap;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        minHeap.push((double)num);
    }
    
    double findMedian() {
        priority_queue<double, vector<double>, greater<double>> tempHeap = minHeap;       
        vector<double> arr;
        while(!tempHeap.empty()) {
            arr.push_back(tempHeap.top());
            tempHeap.pop();
        }

        int n = arr.size();
        double median;
        if(n % 2 != 0)
            median = arr[n/2];
        else 
            median = (arr[n/2 - 1] + arr[n/2]) / 2.0;
        
        return median;
    }
};
