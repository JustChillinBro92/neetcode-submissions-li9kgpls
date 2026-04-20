class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> ans;

        for(int num : nums) freq[num]++;

        for(auto& [num, count] : freq) 
            bucket[count].push_back(num);
        
        for(int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            for(int num : bucket[i]) {
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};