class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> res;

        for(auto &r : points) {
            int dist = r[0] * r[0] + r[1] * r[1];
            maxHeap.push({dist, {r[0], r[1]}});
            if(maxHeap.size() > k) maxHeap.pop();
        }

        while(!maxHeap.empty()) {
            auto top = maxHeap.top();
            res.push_back(top.second);
            maxHeap.pop();
        }
        return res;
    }
};
