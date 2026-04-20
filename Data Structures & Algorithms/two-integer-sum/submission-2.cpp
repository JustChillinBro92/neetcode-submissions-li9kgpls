class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int search;

        for(int i = 0; i < nums.size(); i++) {
            search = target - nums[i];
            if(map.count(search)) return {map[search], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
