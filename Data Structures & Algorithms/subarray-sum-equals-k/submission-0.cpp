class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum_freq;
        preSum_freq[0] = 1;
        int sub_count = 0;

        int currSum = 0;
        for(auto &num : nums) {
            currSum += num;
            int diff = currSum - k;
            // check whether subarray can be formed
            if(preSum_freq.find(diff) != preSum_freq.end())
                sub_count += preSum_freq[diff];
            preSum_freq[currSum]++;
        }

        return sub_count;
    }
};