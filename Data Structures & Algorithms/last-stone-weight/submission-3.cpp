class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto &stone : stones) maxHeap.push(stone);

        while(maxHeap.size() > 1) {
            int x = maxHeap.top(); maxHeap.pop();
            int y = maxHeap.top(); maxHeap.pop();
            if(x != y) maxHeap.push(abs(y - x));
        }
        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};
