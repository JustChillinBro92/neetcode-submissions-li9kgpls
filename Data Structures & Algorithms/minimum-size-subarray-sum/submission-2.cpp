class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int sum = 0, minLen = INT_MAX;
        while(r < n) {
            sum += nums[r];
            while(sum >= target) {
                if((sum - nums[l]) < target) { 
                    minLen = min(minLen, r - l + 1);
                    break;
                }
                sum -= nums[l];
                l++;
            } 
            r++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};