class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lb = 0, ub = nums.size()-1;

        int curr = 0;
        while(curr <= ub) {
            if(nums[curr] == 0) 
                swap(nums[curr], nums[lb++]);
            else if(nums[curr] == 2) 
                swap(nums[curr--], nums[ub--]);
            curr++;
        }
    }
};