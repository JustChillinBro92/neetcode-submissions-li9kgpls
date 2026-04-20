class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        int count = 1;

        for(int i = 1; i <= nums.size(); i++) 
            map[i] = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(map[nums[i]] == 0)
                map[nums[i]] = count;
            else
                map[nums[i]] = ++count;

            if(map[nums[i]] > 1) return true;
        }
        return false;
    }
};