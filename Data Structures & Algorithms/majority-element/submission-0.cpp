class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;

        for(auto &num : nums) {
            if(count == 0) candidate = num;
            count += candidate == num ? 1 : -1;
        }
        return candidate;
    }
};