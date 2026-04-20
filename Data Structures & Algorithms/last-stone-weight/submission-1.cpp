class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> maxHeap;

        for(int stone: stones) maxHeap.push(stone);

        while(maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();
            int new_weight = stone1 - stone2;
            if(new_weight > 0) maxHeap.push(new_weight);
        }
        return maxHeap.size() ? maxHeap.top() : 0;  
    }
};
