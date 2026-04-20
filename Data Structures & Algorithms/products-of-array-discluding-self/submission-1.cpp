class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix, suffix;

        int prod = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0) {
                prod *= nums[i-1];
                prefix.push_back(prod);
            } else prefix.push_back(1);
        }

        prod = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            if(i < nums.size()-1) {
                prod *= nums[i+1];
                suffix.push_back(prod);
            } else suffix.push_back(1);
        }
        reverse(suffix.begin(), suffix.end());

        for(int i = 0; i < nums.size(); i++) 
            prefix[i] *= suffix[i];

        return prefix;
    }
};
