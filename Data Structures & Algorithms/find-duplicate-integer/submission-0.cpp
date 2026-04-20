class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        int result;

        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            if(hash[nums[i]] > 1) result = nums[i];
        }
        return result;
    }
};
