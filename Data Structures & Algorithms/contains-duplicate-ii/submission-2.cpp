class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {  
        unordered_set<int> s;
        int n = nums.size();
        int l = 0, r = 0;
        while(r < n) {
            if(r - l > k) {
                s.erase(nums[l]);
                l++;
            }
            if(s.count(nums[r])) return true;
            s.insert(nums[r]);
            r++;
        }
        return false;       
    }
};