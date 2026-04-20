class Solution {
private:
    vector<vector<int>> res;
    vector<int> curr;
    int _target;

    void dfs(vector<int> &arr, int i, vector<int> &curr, int total) {
        if(total == _target) {
            res.push_back(curr);
            return;
        }

        for(int start = i; start < arr.size(); start++) {
            // skip duplicates
            if(start > i && arr[start] == arr[start-1]) continue;

            // little QOL feature, early break instead of recursive call
            if(total + arr[start] > _target) break;

            curr.push_back(arr[start]);
            dfs(arr, start+1, curr, total + arr[start]);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> arr;
        _target = target;

        for(auto &num : candidates) minHeap.push(num);
        while(!minHeap.empty()) {
            arr.push_back(minHeap.top());
            minHeap.pop();
        }
        dfs(arr, 0, curr, 0);
        return res;
    }
};
