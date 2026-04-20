class Solution {
private:
    int sum = 0;
    void dfs(vector<int> &nums, int xorTotal, int start) {
        if(start == nums.size()) {
            sum += xorTotal;
            return;
        }

        xorTotal ^= nums[start];
        dfs(nums, xorTotal, start + 1);
        xorTotal ^= nums[start];
        dfs(nums, xorTotal, start + 1);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        vector<int> curr;
        dfs(nums, 0, 0);
        return sum;
    }
};