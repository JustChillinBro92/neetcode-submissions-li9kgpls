class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr(26, 0);
        for(char c : tasks) arr[c - 'A']++;
        
        priority_queue<int> maxHeap;
        for(int i = 0; i < 26; i++) {
            if(arr[i]) maxHeap.push(arr[i]);   
        }

        queue<pair<int, int>> q;
        int cycles = 0;
        while(!maxHeap.empty() || !q.empty()) {
            cycles++;

            if(!maxHeap.empty()) {
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if(count > 0)
                    q.push({count, cycles + n});
            } else {
                cycles = q.front().second;
            }

            if(!q.empty() && q.front().second == cycles) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return cycles;
    }
};
