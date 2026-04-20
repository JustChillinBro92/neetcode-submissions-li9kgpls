class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // { dist, {x, y} } format in maxHeap
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> res;

        for(auto &p: points) {
            int dist = p[0]*p[0] + p[1]*p[1];            
            maxHeap.push({ dist, p });
            if(maxHeap.size() > k) maxHeap.pop();
        }

        while(maxHeap.size()) {
            vector<int> coords;
            coords = maxHeap.top().second; maxHeap.pop();
            res.push_back(coords);
        }
        return res;
    }
};
