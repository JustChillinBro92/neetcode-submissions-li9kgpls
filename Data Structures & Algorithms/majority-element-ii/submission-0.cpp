class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> res;
        for(auto &num : nums) freq[num]++;
        for(auto &[num, count] : freq) {
            if(count > floor(n / 3))
            res.push_back(num);
        }
        return res;
    }
};