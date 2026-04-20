class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> stk;
        
        for(int i = 0; i < temperatures.size(); i++) {
            // while loop solely for popping temps smaller than current temp
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int prev_index = stk.top();
                res[prev_index] = i - prev_index;
                stk.pop();              
            }
            stk.push(i);
        }
        return res;
    }
};
